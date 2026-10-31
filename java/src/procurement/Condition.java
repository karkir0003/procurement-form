package procurement;

import java.util.Objects;

public class Condition {
    private final String conditionId;
    private final String questionId;
    private final ConditionOperator operator;
    private final Object value;
    private final Form form;

    public Condition(String conditionId, String questionId, ConditionOperator operator, Object value) {
        this(conditionId, questionId, operator, value, null);
    }

    public Condition(String conditionId, String questionId, ConditionOperator operator, Object value, Form form) {
        this.conditionId = conditionId;
        this.questionId = questionId;
        this.operator = operator;
        this.value = value;
        this.form = form;
    }

    public String getConditionId() {
        return conditionId;
    }

    public String getQuestionId() {
        return questionId;
    }

    public ConditionOperator getOperator() {
        return operator;
    }

    public Object getValue() {
        return value;
    }

    public Form getForm() {
        return form;
    }

    public boolean evaluate() {
        return evaluate(this.form);
    }

    public boolean evaluate(Form targetForm) {
        Form activeForm = targetForm != null ? targetForm : this.form;
        if (activeForm == null) {
            return false;
        }

        Question question = activeForm.getQuestion(this.questionId);
        if (question == null) {
            return false;
        }

        Answer answer = activeForm.getAnswer(this.questionId);
        if (answer == null) {
            return false;
        }

        if (this.operator == ConditionOperator.EQUAL) {
            return Objects.equals(answer.getValue(), this.value);
        } else if (this.operator == ConditionOperator.NOT_EQUAL) {
            return !Objects.equals(answer.getValue(), this.value);
        }

        return false;
    }

    @Override
    public String toString() {
        return String.format("<Condition id='%s' q_id='%s' %s '%s'>", conditionId, questionId, operator.getSymbol(), value);
    }
}
