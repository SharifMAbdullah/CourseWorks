package CodeSmellCW;

public class BoosterMode implements Configuration {
    int colorIntensity;
    int intensityThreshold;
    @Override
    public void setConfiguration() {
        colorIntensity = getIntensityThreshold()+10;
    }

    public int getIntensityThreshold() {
        return intensityThreshold;
    }
}
