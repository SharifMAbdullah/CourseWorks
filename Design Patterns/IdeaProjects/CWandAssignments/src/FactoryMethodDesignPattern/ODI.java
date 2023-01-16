package FactoryMethodDesignPattern;

public class ODI implements CricketInterface {
    @Override
    public void setMatchSize() {
        System.out.println("Match Size set to 50");
    }
}
