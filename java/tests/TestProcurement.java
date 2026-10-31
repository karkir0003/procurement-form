package tests;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import procurement.*;
import java.util.Arrays;
import java.util.List;

public class TestProcurement {
    private Question qDept;
    private Question qPlan;
    private Form form;

    @BeforeEach
    public void setUp() {
        qDept = new Question("q1", "What department?", QuestionFormat.SHORT_ANSWER);
        qPlan = new Question("q2", "Subscription tier?", QuestionFormat.SINGLE_SELECT,
                Arrays.asList("Standard", "Enterprise"));
        form = new Form("f1", Arrays.asList(qDept, qPlan), null);
    }

    @Test
    public void testGetQuestionUtility() {
        Question q = ProcurementService.getFormQuestion(form, "q1");
        assertNotNull(q);
        assertEquals("What department?", q.getText());
        assertNull(ProcurementService.getFormQuestion(form, "q_missing"));
    }

    @Test
    public void testEvaluateCondition() {
        form.submitAnswer(new Answer("a1", "q1", "Engineering"));

        Condition cEqual = new Condition("c1", "q1", ConditionOperator.EQUAL, "Engineering", form);
        Condition cUnequal = new Condition("c2", "q1", ConditionOperator.EQUAL, "Marketing", form);
        Condition cNotEqual = new Condition("c3", "q1", ConditionOperator.NOT_EQUAL, "Finance", form);

        assertTrue(ProcurementService.evaluateCondition(cEqual));
        assertFalse(ProcurementService.evaluateCondition(cUnequal));
        assertTrue(ProcurementService.evaluateCondition(cNotEqual));
    }

    @Test
    public void testFilterConditionsMet() {
        form.submitAnswer(new Answer("a1", "q1", "Engineering"));
        form.submitAnswer(new Answer("a2", "q2", "Enterprise"));

        Condition c1 = new Condition("c1", "q1", ConditionOperator.EQUAL, "Engineering", form);
        Condition c2 = new Condition("c2", "q1", ConditionOperator.EQUAL, "Design", form);
        Condition c3 = new Condition("c3", "q2", ConditionOperator.NOT_EQUAL, "Standard", form);

        List<Condition> met = ProcurementService.filterConditionsMet(Arrays.asList(c1, c2, c3));
        assertEquals(2, met.size());
        assertTrue(met.contains(c1));
        assertTrue(met.contains(c3));
    }
}
