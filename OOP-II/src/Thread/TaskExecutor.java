package Thread;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TaskExecutor {
    public static void main(String[] args) {
        printTask task1 = new printTask("task1");
        printTask task2 = new printTask("task2");
        printTask task3 = new printTask("task3");
        System.out.println("Starting executor");

        ExecutorService threadExecutor = Executors.newCachedThreadPool();
        threadExecutor.execute(task1);
        threadExecutor.execute(task2);
        threadExecutor.execute(task3);

        threadExecutor.shutdown();

        System.out.println("tasks started");
    }
}
