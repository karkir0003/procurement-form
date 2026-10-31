#include "procurement/models.hpp"

namespace procurement {

Question::Question(std::string id, std::string q_text, QuestionFormat format, std::vector<std::string> opts)
    : question_id(std::move(id)),
      text(std::move(q_text)),
      question_format(format),
      options(std::move(opts)) {}

Answer::Answer(std::string a_id, std::string q_id, std::string val)
    : answer_id(std::move(a_id)),
      question_id(std::move(q_id)),
      value(std::move(val)) {}

Form::Form(std::string form_id,
           const std::vector<Question>& questions,
           const std::vector<Answer>& answers)
    : form_id_(std::move(form_id)) {
    for (const auto& q : questions) {
        add_question(q);
    }
    for (const auto& a : answers) {
        submit_answer(a);
    }
}

const std::string& Form::get_form_id() const {
    return form_id_;
}

void Form::add_question(const Question& question) {
    questions_.insert_or_assign(question.question_id, question);
}

void Form::submit_answer(const Answer& answer) {
    answers_.insert_or_assign(answer.question_id, answer);
}

const Question* Form::get_question(const std::string& question_id) const {
    auto it = questions_.find(question_id);
    if (it != questions_.end()) {
        return &(it->second);
    }
    return nullptr;
}

const Answer* Form::get_answer(const std::string& question_id) const {
    auto it = answers_.find(question_id);
    if (it != answers_.end()) {
        return &(it->second);
    }
    return nullptr;
}

} // namespace procurement
