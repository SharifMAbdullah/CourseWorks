package Observer;

public class ConcreteObserver implements Observers{

    @Override
    public void update(String fileName, String changeType, String changeTime) {
        System.out.println("Changed file: "+fileName+"Changing type: "+changeType+"Changing time"+changeTime);
    }
}
