import java.util.ArrayList;
import java.util.Random;

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

    public static void bubbleSort(PointN[] points) {
        int n = points.length;
        boolean swapped;
        do {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (points[i - 1].norm() > points[i].norm()) {
                    // Swap elements
                    PointN temp = points[i - 1];
                    points[i - 1] = points[i];
                    points[i] = temp;
                    swapped = true;
                }
            }
            n--;
        } while (swapped);

    }

};

class second {
    static void printall(PointN[] points) {
        for (int i = 0; i < points.length; i++) {
            points[i].print();
        }
    }

    static void random(PointN[] points) {
        Random random = new Random();
        for (int i = 0; i < points.length; i++) {
            int randomInt1 = random.nextInt(100);
            int randomInt2 = random.nextInt(100);
            int randomInt3 = random.nextInt(100);
            points[i] = new PointN(new double[] { randomInt1, randomInt2, randomInt3 });
        }
    }

    public static void main(String[] args) {
        // PointN p = new PointN(new double[] { 1.0, 2.0, 3.0 });
        // p.print();
        long start = System.currentTimeMillis();
        PointN[] parr = new PointN[10];
        random(parr);
        PointN.bubbleSort(parr);
        printall(parr);
        long end = System.currentTimeMillis();
        System.out.println("Time taken: " + (end - start) + "ms");

        start = System.currentTimeMillis();
        PointN[] parr2 = new PointN[1000];
        random(parr2);
        PointN.bubbleSort(parr2);
        // printall(parr2);
        end = System.currentTimeMillis();
        System.out.println("Time taken: " + (end - start) + "ms");

        start = System.currentTimeMillis();
        PointN[] parr3 = new PointN[10000];
        random(parr3);
        PointN.bubbleSort(parr3);
        // printall(parr2);
        end = System.currentTimeMillis();
        System.out.println("Time taken: " + (end - start) + "ms");

    }
}