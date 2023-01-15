package CodeSmellCW;

import java.util.ArrayList;
import java.util.Objects;

public class PrintJob {
    ArrayList<Objects> queue;
    String PrioritySettings;
    /**
     * Merged PrioritySetting and PrintJob
     * Solves feature envy and lazy class
     */
    void pullJob(){
        if(PrioritySettings =="High")
            System.out.println("Sent to production");
    }
    void changePriority(){
        if(PrioritySettings =="High")
            PrioritySettings = "low";
    }
}
