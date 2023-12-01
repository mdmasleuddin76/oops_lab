#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double rand_gen()
{
    double lower_bound = 0, upper_bound = 100;
    uniform_real_distribution<double> unif(lower_bound, upper_bound);
    default_random_engine re;
    return unif(re);
}

class Element
{
public:
    virtual void print() = 0;
    virtual double norm() = 0;
};

class PointN : public Element
{
    double *pointArray;
    int dimension;

public:
    PointN();
    PointN(int, double *);
    virtual ~PointN();

    // Overriding
    void print() override;
    double norm() override;

    void generate_random_points();
};

PointN::PointN() : dimension(2), pointArray(nullptr)
{
    pointArray = new double[2];
}
PointN::PointN(int _dim, double *_arr = nullptr) : dimension(_dim)
{
    pointArray = new double[dimension];
    if (_arr != nullptr)
    {
        for (int i = 0; i < dimension; i++)
        {
            *(pointArray + i) = *(_arr + i);
        }
    }
}
PointN::~PointN()
{
    dimension = 0;
    cout << "Dogg" << endl;
    // double *ptr = pointArray;
    // delete pointArray;
    pointArray = nullptr;
    // ptr = nullptr;
}

void PointN::print()
{
    cout << "PointN Class with dimensions = " << dimension << endl;
    cout << "Points : ";
    for (int i = 0; i < dimension; i++)
    {
        cout << *(pointArray + i) << ", ";
    }
    cout << endl;
    cout << "Norm = " << norm() << endl;
}

double PointN::norm()
{
    double temp = 0;
    for (int i = 0; i < dimension; i++)
    {
        temp += pow(pointArray[i], 2);
    }
    return temp;
}

void PointN::generate_random_points()
{
    for (int i = 0; i < dimension; i++)
    {
        pointArray[i] = rand_gen();
    }
}

//
class Point : public Element
{
    double _x, _y;

public:
    Point();
    Point(double x, double y) : _x(x), _y(y){};
    void print() override;
    double norm() override { return pow(_x, 2) + pow(_y, 2); };
};
class Vector : public Element
{
    double _x, _y, _z;

public:
    Vector() : _x(0), _y(0), _z(0){};
    Vector(double x, double y, double z) : _x(x), _y(y), _z(z){};
    void print() override;
    double norm() override { return pow(_x, 2) + pow(_y, 2) + pow(_z, 2); };
};
class Line : public Element
{
    double _length;

public:
    Line() : _length(0){};
    Line(double len) : _length(len){};
    void print() override;
    double norm() override { return pow(_length, 2); };
};

void Point ::print()
{
    cout << "Point Class" << endl;
    cout << "Points : " << _x << ", " << _y << endl;
    cout << "Norm = " << norm() << endl;
}

void Vector ::print()
{
    cout << "Vector Class" << endl;
    cout << "Points : " << _x << ", " << _y << ", " << _z << endl;
    cout << "Norm = " << norm() << endl;
}

void Line ::print()
{
    cout << "Line Class" << endl;
    cout << "Length = " << norm() << endl;
}