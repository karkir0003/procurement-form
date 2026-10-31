const { QuestionFormat } = require("./enums");

class Question {
  constructor(questionId, text, questionFormat, options = []) {
    this.questionId = questionId;
    this.text = text;
    this.questionFormat = questionFormat;
    this.options = options || [];
  }

  toString() {
    return `<Question id='${this.questionId}' format=${this.questionFormat}>`;
  }
}

class Answer {
  constructor(answerId, questionId, value) {
    this.answerId = answerId;
    this.questionId = questionId;
    this.value = value;
  }

  toString() {
    return `<Answer id='${this.answerId}' question_id='${this.questionId}' value='${this.value}'>`;
  }
}

class Form {
  constructor(formId, questions = null, answers = null) {
    this.formId = formId;
    this._questions = new Map();
    this._answers = new Map();

    if (questions) {
      for (const q of questions) {
        this.addQuestion(q);
      }
    }
    if (answers) {
      for (const a of answers) {
        this.submitAnswer(a);
      }
    }
  }

  addQuestion(question) {
    this._questions.set(question.questionId, question);
  }

  submitAnswer(answer) {
    this._answers.set(answer.questionId, answer);
  }

  getQuestion(questionId) {
    return this._questions.get(questionId) || null;
  }

  getAnswer(questionId) {
    return this._answers.get(questionId) || null;
  }
}

module.exports = {
  Question,
  Answer,
  Form,
};
