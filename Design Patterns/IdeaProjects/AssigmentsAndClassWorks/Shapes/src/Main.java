public class Main {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(5, 4);
        System.out.println(rectangle.getArea());

        Square square = new Square(9);
        System.out.println(square.getArea());

        Shape shape = new Rectangle(2,3);
        System.out.println(shape.getArea());

        Shape shape1 = new Square(2);
        System.out.println(shape1.getArea());


    }
}