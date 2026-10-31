#pragma once

#include "enums.hpp"
#include <string>
#include <vector>
#include <unordered_map>

namespace procurement {

class Question {
public:
    std::string question_id;
    std::string text;
    QuestionFormat question_format;
    std::vector<std::string> options;

    Question(std::string id, std::string q_text, QuestionFormat format, std::vector<std::string> opts = {});
};

class Answer {
public:
    std::string answer_id;
    std::string question_id;
    std::string value;

    Answer(std::string a_id, std::string q_id, std::string val);
};

class Form {
private:
    std::string form_id_;
    std::unordered_map<std::string, Question> questions_;
    std::unordered_map<std::string, Answer> answers_;

public:
    explicit Form(std::string form_id,
                  const std::vector<Question>& questions = {},
                  const std::vector<Answer>& answers = {});

    const std::string& get_form_id() const;
    void add_question(const Question& question);
    void submit_answer(const Answer& answer);
    const Question* get_question(const std::string& question_id) const;
    const Answer* get_answer(const std::string& question_id) const;
};

} // namespace procurement
