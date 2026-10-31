const { ConditionOperator } = require("./enums");

class Condition {
  constructor(conditionId, questionId, operator, value, form = null) {
    this.conditionId = conditionId;
    this.questionId = questionId;
    this.operator = operator;
    this.value = value;
    this.form = form;
  }

  evaluate(form = null) {
    const targetForm = form || this.form;
    if (!targetForm) {
      return false;
    }

    const question = targetForm.getQuestion(this.questionId);
    if (!question) {
      return false;
    }

    const answer = targetForm.getAnswer(this.questionId);
    if (answer === null || answer === undefined) {
      return false;
    }

    if (this.operator === ConditionOperator.EQUAL) {
      return answer.value === this.value;
    } else if (this.operator === ConditionOperator.NOT_EQUAL) {
      return answer.value !== this.value;
    }

    return false;
  }

  toString() {
    return `<Condition id='${this.conditionId}' q_id='${this.questionId}' ${this.operator} '${this.value}'>`;
  }
}

module.exports = {
  Condition,
};
