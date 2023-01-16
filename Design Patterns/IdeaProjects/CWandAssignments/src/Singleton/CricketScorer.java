package Singleton;

public class CricketScorer {

        private static CricketScorer cs = new CricketScorer();
        private CricketScorer(){}

        public static CricketScorer getInstance() {
            if(cs==null)
                return new CricketScorer();
            return cs;
        }

        public void doStuff(){
            System.out.println("Scorer called out");
        }

}
