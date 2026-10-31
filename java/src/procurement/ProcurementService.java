package procurement;

import java.util.ArrayList;
import java.util.List;

public class ProcurementService {

    public static Question getFormQuestion(Form form, String questionId) {
        return form.getQuestion(questionId);
    }

    public static boolean evaluateCondition(Condition condition) {
        return condition.evaluate();
    }

    public static boolean evaluateCondition(Condition condition, Form form) {
        return condition.evaluate(form);
    }

    public static List<Condition> filterConditionsMet(List<Condition> conditions) {
        return filterConditionsMet(conditions, null);
    }

    public static List<Condition> filterConditionsMet(List<Condition> conditions, Form form) {
        List<Condition> met = new ArrayList<>();
        for (Condition c : conditions) {
            if (evaluateCondition(c, form)) {
                met.add(c);
            }
        }
        return met;
    }
}
