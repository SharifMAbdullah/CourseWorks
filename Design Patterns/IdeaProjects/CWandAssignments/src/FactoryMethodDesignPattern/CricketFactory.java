package FactoryMethodDesignPattern;

public class CricketFactory {
    public CricketInterface createMatch(String match){
        if(match=="ODI") return new ODI();
        else return new T20();
    }
}
