#pragma once

#include "enums.hpp"
#include "models.hpp"
#include <string>

namespace procurement {

class Condition {
public:
    std::string condition_id;
    std::string question_id;
    ConditionOperator op;
    std::string value;
    const Form* form;

    Condition(std::string cond_id,
              std::string q_id,
              ConditionOperator oper,
              std::string val,
              const Form* f = nullptr);

    bool evaluate(const Form* target_form = nullptr) const;

    bool operator==(const Condition& other) const {
        return condition_id == other.condition_id;
    }
};

} // namespace procurement
