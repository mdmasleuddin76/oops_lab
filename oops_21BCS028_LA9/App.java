public class App {
    public static void main(String[] args) {
        Point p1 = new Point();
        p1.printPoint();
        Point p2 = new Point(12.5, 25);
        p2.printPoint();
        p1.distFrom(p2);
        Point p3 = p1.midPoint(p2);
        p3.printPoint();

        Point point_cloud[] = new Point[10000];
        for (int i = 0; i < 10000; i++) {
            point_cloud[i] = (new Point(Math.random() * 100, Math.random() * 100));
        }
        double centroid_x = 0, centroid_y = 0;
        for (int i = 0; i < point_cloud.length; i++) {
            centroid_x += point_cloud[i].get_x();
            centroid_y += point_cloud[i].get_y();
        }
        centroid_x /= 10000;
        centroid_y /= 10000;
        System.out.print("Centroid Cords : ");
        System.out.println("x = " + String.format("%.2f", centroid_x) + ", y = " + String.format("%.2f", centroid_y));

        // Problem - 3

        Element ref = new Point(12, 24);
        System.out.println("InstanceOf Point = " + (ref instanceof Point));
        System.out.println("InstanceOf Element = " + (ref instanceof Element));
        System.out.println("InstanceOf App = " + (ref instanceof App));
        Point casted_el = (Point) ref;
        casted_el.printPoint();

        Element element_cloud[] = new Element[10000];
        for (int i = 0; i < 10000; i++) {
            element_cloud[i] = (new Point(Math.random() * 100, Math.random() * 100));
        }
        double centroid_x_new = 0, centroid_y_new = 0;
        for (int i = 0; i < element_cloud.length; i++) {
            centroid_x_new += ((Point) element_cloud[i]).get_x();
            centroid_y_new += ((Point) element_cloud[i]).get_y();
        }
        centroid_x_new /= 10000;
        centroid_y_new /= 10000;
        System.out.println("Centroid Cords : ");
        System.out.println("x = " + String.format("%.2f", centroid_x_new) + ", y = " +
                String.format("%.2f", centroid_y_new));

        // Trying ****
        Element exp = new Point(1, 2);
        Point newExp;
        if (!(exp instanceof Point)) {
            return;
        }
        newExp = (Point) exp;
        newExp.printPoint();
    }
}
