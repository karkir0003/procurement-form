package procurement;

public enum QuestionFormat {
    SHORT_ANSWER("short_answer"),
    PARAGRAPH("paragraph"),
    SINGLE_SELECT("single_select");

    private final String value;

    QuestionFormat(String value) {
        this.value = value;
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return value;
    }
}
