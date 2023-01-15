package FactoryMethodDesignPattern;

public class ODI extends CricketFactory {
    @Override
    public void setMatchSize() {
        System.out.println("Match Size set to 50");
    }
}
