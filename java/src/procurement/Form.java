package procurement;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Form {
    private final String formId;
    private final Map<String, Question> questions = new HashMap<>();
    private final Map<String, Answer> answers = new HashMap<>();

    public Form(String formId) {
        this.formId = formId;
    }

    public Form(String formId, List<Question> questions, List<Answer> answers) {
        this.formId = formId;
        if (questions != null) {
            for (Question q : questions) {
                addQuestion(q);
            }
        }
        if (answers != null) {
            for (Answer a : answers) {
                submitAnswer(a);
            }
        }
    }

    public String getFormId() {
        return formId;
    }

    public void addQuestion(Question question) {
        questions.put(question.getQuestionId(), question);
    }

    public void submitAnswer(Answer answer) {
        answers.put(answer.getQuestionId(), answer);
    }

    public Question getQuestion(String questionId) {
        return questions.get(questionId);
    }

    public Answer getAnswer(String questionId) {
        return answers.get(questionId);
    }
}
