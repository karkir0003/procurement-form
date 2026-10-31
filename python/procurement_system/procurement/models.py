from __future__ import annotations
from typing import Any, Dict, List, Optional
from procurement.enums import QuestionFormat


class Question:
    def __init__(
        self,
        question_id: str,
        text: str,
        question_format: QuestionFormat,
        options: Optional[List[str]] = None,
    ):
        self.question_id: str = question_id
        self.text: str = text
        self.question_format: QuestionFormat = question_format
        self.options: List[str] = options or []

    def __repr__(self) -> str:
        return f"<Question id={self.question_id!r} format={self.question_format.value}>"


class Answer:
    def __init__(self, answer_id: str, question_id: str, value: Any):
        self.answer_id: str = answer_id
        self.question_id: str = question_id
        self.value: Any = value

    def __repr__(self) -> str:
        return f"<Answer id={self.answer_id!r} question_id={self.question_id!r} value={self.value!r}>"


class Form:
    def __init__(
        self,
        form_id: str,
        questions: Optional[List[Question]] = None,
        answers: Optional[List[Answer]] = None,
    ):
        self.form_id: str = form_id
        self._questions: Dict[str, Question] = {}
        self._answers: Dict[str, Answer] = {}

        if questions:
            for q in questions:
                self.add_question(q)
        if answers:
            for a in answers:
                self.submit_answer(a)

    def add_question(self, question: Question) -> None:
        self._questions[question.question_id] = question

    def submit_answer(self, answer: Answer) -> None:
        self._answers[answer.question_id] = answer

    def get_question(self, question_id: str) -> Optional[Question]:
        return self._questions.get(question_id)

    def get_answer(self, question_id: str) -> Optional[Answer]:
        return self._answers.get(question_id)