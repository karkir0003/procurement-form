from __future__ import annotations
from typing import Any, Optional
from procurement.enums import ConditionOperator
from procurement.models import Form


class Condition:
    def __init__(
        self,
        condition_id: str,
        question_id: str,
        operator: ConditionOperator,
        value: Any,
        form: Optional[Form] = None,
    ):
        self.condition_id: str = condition_id
        self.question_id: str = question_id
        self.operator: ConditionOperator = operator
        self.value: Any = value
        self.form: Optional[Form] = form

    def evaluate(self, form: Optional[Form] = None) -> bool:
        target_form = form or self.form
        if target_form is None:
            return False

        question = target_form.get_question(self.question_id)
        if not question:
            return False

        answer = target_form.get_answer(self.question_id)
        if answer is None:
            return False

        if self.operator == ConditionOperator.EQUAL:
            return answer.value == self.value
        elif self.operator == ConditionOperator.NOT_EQUAL:
            return answer.value != self.value

        return False

    def __repr__(self) -> str:
        return f"<Condition id={self.condition_id!r} q_id={self.question_id!r} {self.operator.value} {self.value!r}>"