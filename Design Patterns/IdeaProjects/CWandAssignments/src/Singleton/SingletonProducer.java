package Singleton;

public class SingletonProducer {

        private static SingletonProducer sp = new SingletonProducer();
        private SingletonProducer(){}

        public static SingletonProducer getInstance(){
            return sp;
        }

        public void doStuff(){
            System.out.println("Singleton produced");
        }

}
