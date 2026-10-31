#pragma once

#include "models.hpp"
#include "condition.hpp"
#include <vector>

namespace procurement {

const Question* get_form_question(const Form& form, const std::string& question_id);

bool evaluate_condition(const Condition& condition, const Form* form = nullptr);

std::vector<Condition> filter_conditions_met(const std::vector<Condition>& conditions, const Form* form = nullptr);

} // namespace procurement
