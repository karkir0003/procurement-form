#include "procurement/service.hpp"

namespace procurement {

const Question* get_form_question(const Form& form, const std::string& question_id) {
    return form.get_question(question_id);
}

bool evaluate_condition(const Condition& condition, const Form* form) {
    return condition.evaluate(form);
}

std::vector<Condition> filter_conditions_met(const std::vector<Condition>& conditions, const Form* form) {
    std::vector<Condition> met;
    for (const auto& c : conditions) {
        if (evaluate_condition(c, form)) {
            met.push_back(c);
        }
    }
    return met;
}

} // namespace procurement
