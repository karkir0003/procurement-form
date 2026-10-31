#include <gtest/gtest.h>
#include "procurement/enums.hpp"
#include "procurement/models.hpp"
#include "procurement/condition.hpp"
#include "procurement/service.hpp"
#include <algorithm>

using namespace procurement;

TEST(ProcurementSystemTest, TestGetQuestionUtility) {
    Question q_dept("q1", "What department?", QuestionFormat::SHORT_ANSWER);
    Question q_plan("q2", "Subscription tier?", QuestionFormat::SINGLE_SELECT, {"Standard", "Enterprise"});
    Form form("f1", {q_dept, q_plan});

    const Question* q = get_form_question(form, "q1");
    ASSERT_NE(q, nullptr);
    EXPECT_EQ(q->text, "What department?");
    EXPECT_EQ(get_form_question(form, "q_missing"), nullptr);
}

TEST(ProcurementSystemTest, TestEvaluateCondition) {
    Question q_dept("q1", "What department?", QuestionFormat::SHORT_ANSWER);
    Question q_plan("q2", "Subscription tier?", QuestionFormat::SINGLE_SELECT, {"Standard", "Enterprise"});
    Form form("f1", {q_dept, q_plan});

    form.submit_answer(Answer("a1", "q1", "Engineering"));

    Condition c_equal("c1", "q1", ConditionOperator::EQUAL, "Engineering", &form);
    Condition c_unequal("c2", "q1", ConditionOperator::EQUAL, "Marketing", &form);
    Condition c_not_equal("c3", "q1", ConditionOperator::NOT_EQUAL, "Finance", &form);

    EXPECT_TRUE(evaluate_condition(c_equal));
    EXPECT_FALSE(evaluate_condition(c_unequal));
    EXPECT_TRUE(evaluate_condition(c_not_equal));
}

TEST(ProcurementSystemTest, TestFilterConditionsMet) {
    Question q_dept("q1", "What department?", QuestionFormat::SHORT_ANSWER);
    Question q_plan("q2", "Subscription tier?", QuestionFormat::SINGLE_SELECT, {"Standard", "Enterprise"});
    Form form("f1", {q_dept, q_plan});

    form.submit_answer(Answer("a1", "q1", "Engineering"));
    form.submit_answer(Answer("a2", "q2", "Enterprise"));

    Condition c1("c1", "q1", ConditionOperator::EQUAL, "Engineering", &form);
    Condition c2("c2", "q1", ConditionOperator::EQUAL, "Design", &form);
    Condition c3("c3", "q2", ConditionOperator::NOT_EQUAL, "Standard", &form);

    std::vector<Condition> met = filter_conditions_met({c1, c2, c3});
    EXPECT_EQ(met.size(), 2u);
    EXPECT_TRUE(std::find(met.begin(), met.end(), c1) != met.end());
    EXPECT_TRUE(std::find(met.begin(), met.end(), c3) != met.end());
}
