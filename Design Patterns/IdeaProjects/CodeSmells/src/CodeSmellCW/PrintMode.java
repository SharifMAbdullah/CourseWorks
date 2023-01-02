package CodeSmellCW;

public abstract class PrintMode {

    int pageSize;
    int orientation; //FR?
    int colorIntensity;
    int costPerPage;
    int numberOfPages;

    abstract void saveToner();
    abstract void savePage();
    abstract void boost();
    PrintMode(int pageSize, int orientation, int colorIntensity, int costPerPage, int numberOfPages) {
        pageSize = this.pageSize;
        orientation = this.orientation;
        colorIntensity = this.colorIntensity;
        costPerPage = this.costPerPage;
        numberOfPages = this.numberOfPages;
    }
    public int getNumberOfPages() {
        return numberOfPages;
    }
    public int getPageSize() {
        return pageSize;
    }
    public int getOrientation() {
        return orientation;
    }
    public int getColorIntensity() {
        return colorIntensity;
    }
    public int getCostPerPage() {
        return costPerPage;
    }


}
