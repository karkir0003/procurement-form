package procurement;

public class Answer {
    private final String answerId;
    private final String questionId;
    private final Object value;

    public Answer(String answerId, String questionId, Object value) {
        this.answerId = answerId;
        this.questionId = questionId;
        this.value = value;
    }

    public String getAnswerId() {
        return answerId;
    }

    public String getQuestionId() {
        return questionId;
    }

    public Object getValue() {
        return value;
    }

    @Override
    public String toString() {
        return String.format("<Answer id='%s' question_id='%s' value='%s'>", answerId, questionId, value);
    }
}
