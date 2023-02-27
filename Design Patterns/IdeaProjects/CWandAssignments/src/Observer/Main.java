package Observer;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {

        concreteSubject subject=new concreteSubject("a.txt", ".");

        ConcreteObserver observer1=new ConcreteObserver();
        ConcreteObserver observer2=new ConcreteObserver();

        subject.registeredObserver(observer1);
        subject.registeredObserver(observer2);

        subject.getUpdate();
    }
}
