package FactoryMethodDP;

public class Room {
    public String makeRoom(int n){
        if(n==1) return "One room";
        else return "Two room";
    }
}
