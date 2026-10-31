import unittest
from procurement.enums import QuestionFormat, ConditionOperator
from procurement.models import Form, Question, Answer
from procurement.conditions import Condition
from procurement.service import evaluate_condition, filter_conditions_met, get_form_question


class TestProcurementSystem(unittest.TestCase):
    def setUp(self):
        self.q_dept = Question("q1", "What department?", QuestionFormat.SHORT_ANSWER)
        self.q_plan = Question(
            "q2",
            "Subscription tier?",
            QuestionFormat.SINGLE_SELECT,
            options=["Standard", "Enterprise"],
        )
        self.form = Form("f1", questions=[self.q_dept, self.q_plan])

    def test_get_question_utility(self):
        q = get_form_question(self.form, "q1")
        self.assertIsNotNone(q)
        self.assertEqual(q.text, "What department?")
        self.assertIsNone(get_form_question(self.form, "q_missing"))

    def test_evaluate_condition(self):
        self.form.submit_answer(Answer("a1", "q1", "Engineering"))

        c_equal = Condition("c1", "q1", ConditionOperator.EQUAL, "Engineering", self.form)
        c_unequal = Condition("c2", "q1", ConditionOperator.EQUAL, "Marketing", self.form)
        c_not_equal = Condition("c3", "q1", ConditionOperator.NOT_EQUAL, "Finance", self.form)

        self.assertTrue(evaluate_condition(c_equal))
        self.assertFalse(evaluate_condition(c_unequal))
        self.assertTrue(evaluate_condition(c_not_equal))

    def test_filter_conditions_met(self):
        self.form.submit_answer(Answer("a1", "q1", "Engineering"))
        self.form.submit_answer(Answer("a2", "q2", "Enterprise"))

        c1 = Condition("c1", "q1", ConditionOperator.EQUAL, "Engineering", self.form)
        c2 = Condition("c2", "q1", ConditionOperator.EQUAL, "Design", self.form)
        c3 = Condition("c3", "q2", ConditionOperator.NOT_EQUAL, "Standard", self.form)

        met = filter_conditions_met([c1, c2, c3])
        self.assertEqual(len(met), 2)
        self.assertIn(c1, met)
        self.assertIn(c3, met)


if __name__ == "__main__":
    unittest.main()