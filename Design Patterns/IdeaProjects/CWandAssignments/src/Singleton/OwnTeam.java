package Singleton;

public class OwnTeam {
    CricketScorer cs = CricketScorer.getInstance();
    public void printMessage(){
        cs.doStuff();
    }
    public static void main(String[] args) {
        OwnTeam ot = new OwnTeam();
        ot.printMessage();
    }

}
