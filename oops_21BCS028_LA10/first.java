import java.util.ArrayList;
abstract class Element {
    abstract double norm();

    abstract void print();
};
class PointN extends Element {
    private ArrayList<Double> coords = new ArrayList<Double>();

    public PointN() {
        coords = new ArrayList<Double>();
    }

    public PointN(double[] array) {
        coords = new ArrayList<Double>();
        for (double value : array) {
            coords.add(value);
        }
    }

    @Override
    public double norm() {
        double sum = 0.0;
        for (double coord : coords) {
            sum += coord * coord;
        }
        return sum;
    }

    @Override
    void print() {

        System.out.print("PointN: (");
        for (int i = 0; i < coords.size(); i++) {
            System.out.print(coords.get(i));
            if (i < coords.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("), Norm: " + norm());
    }

};

class first {
    public static void main(String[] args) {
                PointN p = new PointN(new double[] { 1.0, 2.0, 3.0 });
        p.print();
    }
}