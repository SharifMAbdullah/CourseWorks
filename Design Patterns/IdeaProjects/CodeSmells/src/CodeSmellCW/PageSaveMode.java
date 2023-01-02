package CodeSmellCW;

public class PageSaveMode extends PrintMode{
    PageSaveMode(int pageSize, int orientation, int colorIntensity, int costPerPage, int numberOfPages) {
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
