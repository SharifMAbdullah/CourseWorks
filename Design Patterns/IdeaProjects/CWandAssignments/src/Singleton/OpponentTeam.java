package Singleton;

public class OpponentTeam {
    CricketScorer cs = new CricketScorer();

    //Rest of the code doesn't execute
    public void printMessage(){
        cs.doStuff();
    }
    public static void main(String[] args) {
        OpponentTeam ot = new OpponentTeam();
        ot.printMessage();
    }
}
