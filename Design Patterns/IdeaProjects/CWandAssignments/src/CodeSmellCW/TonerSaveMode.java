package CodeSmellCW;

public class TonerSaveMode implements Configuration{

    String tonerSavingLevel;
    @Override
    public void setConfiguration() {
        if(tonerSavingLevel=="High")
            reduceHighIntensity();
        else if(tonerSavingLevel=="medium")
            reduceMidIntensity();
        else
            reduceLowIntensity();
    }
    void reduceHighIntensity(){

    }
    void reduceMidIntensity(){

    }
    void reduceLowIntensity(){

    }
}
