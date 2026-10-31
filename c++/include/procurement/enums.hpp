#pragma once

#include <iostream>
#include <string>

namespace procurement {

enum class QuestionFormat {
    SHORT_ANSWER,
    PARAGRAPH,
    SINGLE_SELECT
};

enum class ConditionOperator {
    EQUAL,
    NOT_EQUAL
};

inline std::string to_string(QuestionFormat format) {
    switch (format) {
        case QuestionFormat::SHORT_ANSWER: return "short_answer";
        case QuestionFormat::PARAGRAPH: return "paragraph";
        case QuestionFormat::SINGLE_SELECT: return "single_select";
    }
    return "unknown";
}

inline std::string to_string(ConditionOperator op) {
    switch (op) {
        case ConditionOperator::EQUAL: return "==";
        case ConditionOperator::NOT_EQUAL: return "!=";
    }
    return "unknown";
}

inline std::ostream& operator<<(std::ostream& os, QuestionFormat format) {
    return os << to_string(format);
}

inline std::ostream& operator<<(std::ostream& os, ConditionOperator op) {
    return os << to_string(op);
}

} // namespace procurement
