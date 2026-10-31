from enum import Enum


class QuestionFormat(str, Enum):
    SHORT_ANSWER = "short_answer"
    PARAGRAPH = "paragraph"
    SINGLE_SELECT = "single_select"


class ConditionOperator(str, Enum):
    EQUAL = "=="
    NOT_EQUAL = "!="