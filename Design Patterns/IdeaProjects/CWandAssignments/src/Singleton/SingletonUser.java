package Singleton;

public class SingletonUser {
    SingletonProducer sp = SingletonProducer.getInstance();
    public void printMessage(){
        sp.doStuff();
    }
    public static void main(String[] args) {
        SingletonUser su = new SingletonUser();
        su.printMessage();
    }

}
