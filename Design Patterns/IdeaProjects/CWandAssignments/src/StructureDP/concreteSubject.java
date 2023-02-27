package StructureDP;

import java.util.Iterator;
import java.util.Observer;

public class concreteSubject  extends Subject{

    public  void attach(ObserverDP observer){
        ObserverList.add(observer);
    };
    public  void detach(ObserverDP observer)
    {
        ObserverList.remove(observer);
    };

    public  void notifyy(){
        for (Iterator<ObserverDP> it = ObserverList.iterator(); it.hasNext();){
            ObserverDP observer = it.next();
            observer.update();
        }
    };
}
