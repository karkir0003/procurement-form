function getFormQuestion(form, questionId) {
  return form.getQuestion(questionId);
}

function evaluateCondition(condition, form = null) {
  return condition.evaluate(form);
}

function filterConditionsMet(conditions, form = null) {
  return conditions.filter((c) => evaluateCondition(c, form));
}

module.exports = {
  getFormQuestion,
  evaluateCondition,
  filterConditionsMet,
};
