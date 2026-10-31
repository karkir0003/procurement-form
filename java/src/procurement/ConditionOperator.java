package procurement;

public enum ConditionOperator {
    EQUAL("=="),
    NOT_EQUAL("!=");

    private final String symbol;

    ConditionOperator(String symbol) {
        this.symbol = symbol;
    }

    public String getSymbol() {
        return symbol;
    }

    @Override
    public String toString() {
        return symbol;
    }
}
