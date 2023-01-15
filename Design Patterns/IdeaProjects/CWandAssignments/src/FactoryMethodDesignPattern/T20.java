package FactoryMethodDesignPattern;

public class T20 extends CricketFactory {
    @Override

     public void setMatchSize() {
        System.out.println("Match size set to 20");
    }
}
