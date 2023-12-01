class Point implements Element {
    private double _x, _y;

    public Point() {
        // System.out.println("Default constructor");
        _x = 0;
        _y = 0;
    }

    public Point(double x, double y) {
        // System.out.println("Parameterized constructor");
        _x = x;
        _y = y;
    }

    public double get_x() {
        return _x;
    }

    public double get_y() {
        return _y;
    }

    public double distFrom(Point p) {
        System.out.print("Distance from : ");
        p.printPoint();
        return Math.sqrt(_x * p._x + _y * p._y);
    }

    public Point midPoint(Point p) {
        System.out.print("Mid Point : ");
        p.printPoint();
        this.printPoint();
        double newX = (_x + p._x) / 2;
        double newY = (_y + p._y) / 2;
        return new Point(newX, newY);
    }

    @Override
    public void printPoint() {
        System.out.println("x = " + _x + ", " + "y = " + _y);
    }
}
