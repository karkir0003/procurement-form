from typing import List, Optional
from procurement.conditions import Condition
from procurement.models import Form, Question


def get_form_question(form: Form, question_id: str) -> Optional[Question]:
    return form.get_question(question_id)


def evaluate_condition(condition: Condition, form: Optional[Form] = None) -> bool:
    return condition.evaluate(form)


def filter_conditions_met(
    conditions: List[Condition], form: Optional[Form] = None
) -> List[Condition]:
    return [c for c in conditions if evaluate_condition(c, form)]