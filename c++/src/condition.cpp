#include "procurement/condition.hpp"

namespace procurement {

Condition::Condition(std::string cond_id,
                     std::string q_id,
                     ConditionOperator oper,
                     std::string val,
                     const Form* f)
    : condition_id(std::move(cond_id)),
      question_id(std::move(q_id)),
      op(oper),
      value(std::move(val)),
      form(f) {}

bool Condition::evaluate(const Form* target_form) const {
    const Form* active_form = target_form ? target_form : this->form;
    if (!active_form) {
        return false;
    }

    const Question* question = active_form->get_question(this->question_id);
    if (!question) {
        return false;
    }

    const Answer* answer = active_form->get_answer(this->question_id);
    if (!answer) {
        return false;
    }

    if (this->op == ConditionOperator::EQUAL) {
        return answer->value == this->value;
    } else if (this->op == ConditionOperator::NOT_EQUAL) {
        return answer->value != this->value;
    }

    return false;
}

} // namespace procurement
