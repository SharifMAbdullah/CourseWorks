package AbstractFacory;

public class PMWidgetFactory extends WidgetFactory{
    @Override
    public Scrollbar createScrollBar() {
        return null;
    }

    @Override
    public Window createWindow() {
        return null;
    }
}
