package CodeSmellCW;

public class BoosterMode extends PrintMode{
    BoosterMode(int pageSize, int orientation, int colorIntensity, int costPerPage, int numberOfPages) {
        super(pageSize, orientation, colorIntensity, costPerPage, numberOfPages);
    }

    @Override
    void saveToner() {

    }

    @Override
    void savePage() {

    }

    @Override
    void boost() {

    }
}
