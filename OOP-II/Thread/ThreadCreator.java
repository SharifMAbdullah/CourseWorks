import java.lang.Thread;
public class ThreadCreator {
    public static void main(String[] args) {
        System.out.println("Creating threads");

        Thread thread1 = new Thread(new printTask("task1"));
        Thread thread2 = new Thread(new printTask("task2"));
        Thread thread3 = new Thread(new printTask("task3"));

        System.out.println("Threads created, starting tasks:");
        thread1.start();
        thread2.start();
        thread3.start();

        System.out.println("tasks started, main ends");
    }
}
