const assert = require("assert");
const {
  QuestionFormat,
  ConditionOperator,
  Question,
  Answer,
  Form,
  Condition,
  getFormQuestion,
  evaluateCondition,
  filterConditionsMet,
} = require("../procurement");

function testGetQuestionUtility() {
  const qDept = new Question("q1", "What department?", QuestionFormat.SHORT_ANSWER);
  const qPlan = new Question("q2", "Subscription tier?", QuestionFormat.SINGLE_SELECT, [
    "Standard",
    "Enterprise",
  ]);
  const form = new Form("f1", [qDept, qPlan]);

  const q = getFormQuestion(form, "q1");
  assert(q !== null);
  assert.strictEqual(q.text, "What department?");
  assert.strictEqual(getFormQuestion(form, "q_missing"), null);
}

function testEvaluateCondition() {
  const qDept = new Question("q1", "What department?", QuestionFormat.SHORT_ANSWER);
  const qPlan = new Question("q2", "Subscription tier?", QuestionFormat.SINGLE_SELECT, [
    "Standard",
    "Enterprise",
  ]);
  const form = new Form("f1", [qDept, qPlan]);

  form.submitAnswer(new Answer("a1", "q1", "Engineering"));

  const cEqual = new Condition("c1", "q1", ConditionOperator.EQUAL, "Engineering", form);
  const cUnequal = new Condition("c2", "q1", ConditionOperator.EQUAL, "Marketing", form);
  const cNotEqual = new Condition("c3", "q1", ConditionOperator.NOT_EQUAL, "Finance", form);

  assert.strictEqual(evaluateCondition(cEqual), true);
  assert.strictEqual(evaluateCondition(cUnequal), false);
  assert.strictEqual(evaluateCondition(cNotEqual), true);
}

function testFilterConditionsMet() {
  const qDept = new Question("q1", "What department?", QuestionFormat.SHORT_ANSWER);
  const qPlan = new Question("q2", "Subscription tier?", QuestionFormat.SINGLE_SELECT, [
    "Standard",
    "Enterprise",
  ]);
  const form = new Form("f1", [qDept, qPlan]);

  form.submitAnswer(new Answer("a1", "q1", "Engineering"));
  form.submitAnswer(new Answer("a2", "q2", "Enterprise"));

  const c1 = new Condition("c1", "q1", ConditionOperator.EQUAL, "Engineering", form);
  const c2 = new Condition("c2", "q1", ConditionOperator.EQUAL, "Design", form);
  const c3 = new Condition("c3", "q2", ConditionOperator.NOT_EQUAL, "Standard", form);

  const met = filterConditionsMet([c1, c2, c3]);
  assert.strictEqual(met.length, 2);
  assert(met.includes(c1));
  assert(met.includes(c3));
}

function runTests() {
  const tests = [
    { name: "test_get_question_utility", fn: testGetQuestionUtility },
    { name: "test_evaluate_condition", fn: testEvaluateCondition },
    { name: "test_filter_conditions_met", fn: testFilterConditionsMet },
  ];

  for (const t of tests) {
    t.fn();
    process.stdout.write(".");
  }
  console.log("\n----------------------------------------------------------------------");
  console.log(`Ran ${tests.length} tests in 0.000s\n\nOK`);
}

if (require.main === module) {
  runTests();
}

module.exports = { runTests };
