import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

abstract class Element {
    abstract double norm();

    abstract void print();
};

class Sorter extends Thread {
    private PointN[] points;

    public Sorter(PointN[] points) {
        this.points = points;
    }

    public void run() {
        PointN.bubbleSort(points);
    }
}

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

class Third {
    public static void merge(PointN[] left, PointN[] right, PointN[] result) {
        int i = 0, j = 0, k = 0;
        int leftSize = left.length;
        int rightSize = right.length;

        while (i < leftSize && j < rightSize) {
            if (left[i].norm() < right[j].norm()) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }

        while (i < leftSize) {
            result[k++] = left[i++];
        }

        while (j < rightSize) {
            result[k++] = right[j++];
        }
    }

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
        PointN p = new PointN(new double[] { 1.0, 2.0, 3.0 });
        p.print();
        long start1 = System.currentTimeMillis();
        PointN[] parr1 = new PointN[10];
        random(parr1);
        PointN[] parr = new PointN[10];
        System.arraycopy(parr1, 0, parr, 0, parr1.length);
        PointN.bubbleSort(parr1);
        printall(parr1);
        long end1 = System.currentTimeMillis();
        System.out.println("Time taken: " + (end1 - start1) + "ms");




        long start = System.currentTimeMillis();
        PointN[] left = Arrays.copyOfRange(parr, 0, 5);
        PointN[] right = Arrays.copyOfRange(parr, 5, 10);
        Sorter s1 = new Sorter(right);
        Sorter s2 = new Sorter(left);
        s1.start();
        s2.start();
        try {
            s2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {
            s1.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        merge(left, right, parr);
        printall(parr);
        long end = System.currentTimeMillis();
        System.out.println("Time taken: " + (end - start) + "ms");



        long start2 = System.currentTimeMillis();
        PointN[] parr2 = new PointN[10000];
        random(parr2);
        PointN[] left2 = Arrays.copyOfRange(parr2, 0, 5000);
        PointN[] right2 = Arrays.copyOfRange(parr2, 5000, 10000);
        Sorter s12 = new Sorter(right);
        Sorter s22 = new Sorter(left);
        s12.start();
        s22.start();
        try {
            s22.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {
            s12.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        merge(left2, right2, parr2);
        // printall(parr2);
        long end2 = System.currentTimeMillis();
        System.out.println("Time taken: " + (end2 - start2) + "ms");


    }
}