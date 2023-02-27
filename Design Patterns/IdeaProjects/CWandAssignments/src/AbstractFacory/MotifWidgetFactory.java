package AbstractFacory;

public class MotifWidgetFactory extends WidgetFactory{
    @Override
    public Scrollbar createScrollBar() {
        return new MotifScrollbar();
    }

    @Override
    public Window createWindow() {
        return new MotifWindow();
    }
}
