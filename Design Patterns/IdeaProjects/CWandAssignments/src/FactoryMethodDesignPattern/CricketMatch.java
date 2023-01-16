package FactoryMethodDesignPattern;

public class CricketMatch {
    CricketFactory cf = new CricketFactory();
    void arrangeMatch(){
        T20 t20 = new T20();
        t20.setMatchSize();
    }
}
