#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

class Point
{
    double _x;
    double _y;

public:
    // Constructors
    Point() : _x(0.0), _y(0.0) {}
    Point(double x, double y) : _x(x), _y(y) {}

    // Destructor
    ~Point() {}

    // Member function to calculate Euclidean distance from the origin
    double l2Norm() const
    {
        return sqrt(_x * _x + _y * _y);
    }

    // Overload the stream out operator <<
    friend ostream &operator<<(ostream &os, const Point &p)
    {
        os << "Point (" << p._x << "," << p._y << "), Norm = " << p.l2Norm();
        return os;
    }

    // Subscript operator for l-value
    double &operator[](int index)
    {
        if (index == 0)
            return _x;
        else if (index == 1)
            return _y;
        else
            throw out_of_range("Index out of range");
    }

    // Subscript operator for r-value (const)
    const double &operator[](int index) const
    {
        if (index == 0)
            return _x;
        else if (index == 1)
            return _y;
        else
            throw out_of_range("Index out of range");
    }
};

int main()
{
    Point p1(1, 2);
    cout << p1 << endl;

    // Using the subscript operator as an l-value
    p1[0] = 3.0;
    p1[1] = 4.0;
    cout << "Updated point: " << p1 << endl;

    double x = p1[0];
    cout << x;
    return 0;
}