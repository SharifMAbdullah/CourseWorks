package Mediator;

public class ComponentB {
    Mediator m = new Mediator() {
        @Override
        public void notifyy() {
            System.out.println("Sending notification to B");
        }
    };
}
