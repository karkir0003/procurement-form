package procurement;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Question {
    private final String questionId;
    private final String text;
    private final QuestionFormat questionFormat;
    private final List<String> options;

    public Question(String questionId, String text, QuestionFormat questionFormat) {
        this(questionId, text, questionFormat, Collections.emptyList());
    }

    public Question(String questionId, String text, QuestionFormat questionFormat, List<String> options) {
        this.questionId = questionId;
        this.text = text;
        this.questionFormat = questionFormat;
        this.options = options != null ? new ArrayList<>(options) : new ArrayList<>();
    }

    public String getQuestionId() {
        return questionId;
    }

    public String getText() {
        return text;
    }

    public QuestionFormat getQuestionFormat() {
        return questionFormat;
    }

    public List<String> getOptions() {
        return Collections.unmodifiableList(options);
    }

    @Override
    public String toString() {
        return String.format("<Question id='%s' format=%s>", questionId, questionFormat.getValue());
    }
}
