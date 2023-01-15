package CodeSmellCW;

public class PageSaveMode implements Configuration{

    /**
     * solved refused bequest
     * by creating Interface
     */
    public int pageSize = 0;
    public int orientation = 0;
    @Override
    public void setConfiguration() {
        pageSize = getPageSize()-10;
        orientation = getOrientation() - 10;
    }
    void renderPreview(){
        System.out.println("Render preview");
    }
    public int getPageSize(){
        return pageSize;
    }
    public int getOrientation(){
        return orientation;
    }

}
