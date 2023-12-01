#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
const double EARTH_RADIUS = 6371.0;
const double PI = 3.14;
class Element
{
public:
    /* virtual void print()
     {
         cout << "Abstract class virtual print function." << endl;
     }*/
    virtual double norm() = 0;
    virtual void print() = 0;
    virtual ~Element(){};
};
class Point : public Element
{
public:
    double _x;
    double _y;

public:
    double norm() override
    {
        return sqrt(_x * _x + _y * _y);
    }
    void print() override
    {
        cout << "\nClass type - Point\n";
        cout << "Point - ( " << _x << " , " << _y << " )"
             << "\n";
        cout << "Printing norm function -" << norm();
    }
    void setCoords(double x, double y);
    void printCoords() const;
    double distFrom(Point &p) const;
    Point();                   // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p);           // This is the COPY constructor
                               // ~Point();                  // This is the destructor
};
Point::Point()
{
    cout << "\nDefault Constructor of Point class is called.\n";
    this->_x = 0;
    this->_y = 0;
}
Point::Point(double x, double y)
{
    cout << "\nParameterised constructor is called.\n";
    this->_x = x;
    this->_y = y;
}
Point::Point(Point &p)
{
    cout << "\nCopy constructor is called.\n";
    this->_x = p._x;
    this->_y = p._y;
}
void Point::setCoords(double x, double y)
{
    cout << "Set coordinates member function called!\n";
    this->_x = x;
    this->_y = y;
}
void Point::printCoords() const
{
    cout << "\n( " << this->_x << " , " << this->_y << " )";
}
double Point::distFrom(Point &p) const
{
    cout << "\nDistance from function of Point class called!\n";
    return sqrt(pow(this->_x - p._x, 2) + pow(this->_y - p._y, 2));
}
class _Vector : public Element, public Point
{
    string direction;

public:
    double norm() override
    {
        return sqrt(_x * _x + _y * _y);
    }
    void print() override
    {
        cout << "\nClass type - Vector\n";
        cout << "Point - ( " << _x << " , " << _y << " )"
             << "\n";
        cout << "Direction - " << direction << "\n";
        cout << "Printing norm function -" << norm();
    }
    _Vector()
    {
        cout << "Default constructor of _Vector class called!\n";
    }
    _Vector(double x_l, double y_l)
    {
        cout << "2 - arg constructor called!\n";
        // _x = x_l;
        // _y = y_l;
        // here we can call set coords of point also to set x and y - check
        setCoords(x_l, y_l);
    }
    _Vector(double x_l, double y_l, string add_l) : Point(x_l, y_l)
    {
        cout << "Derived class constructor called!";
        _x = x_l;
        _y = y_l;
        direction = add_l;
    }
    void print_loc()
    {
        cout << "\n( " << _x << " , " << _y << " )";
        cout << "\nAddress - " << direction << "\n";
    }
    /*double distFrom_loc(Location &l)
    {
        cout << "\nDistance from function of location class called!\n";
        return distFrom(l);
    }*/
    _Vector(string s1, string s2) : Point() // we are changing signature of constructor so that compiler distinguised
    // between the two default constructor (so called default becuse when we provide argument it is no more deafult)
    {
        cout << "Over riding default constructor.\n";
    }
    double distFrom(_Vector &loc)
    {
        cout << "\nDistFrom function of location class called!\n";
        double angle = acos(sin(this->_x * (M_PI / 180)) * sin(loc._x * (M_PI / 180)) + cos(this->_x * (M_PI / 180)) * cos(loc._x * (M_PI / 180)) * cos(loc._y * (M_PI / 180) - this->_y * (M_PI / 180)));
        return angle * EARTH_RADIUS * M_PI;
    }
};
class Point_N : public Element
{
    double *arr;
    int n;

public:
    double norm() override
    {
        double ans = 0.0;
        for (int i = 0; i < n; i++)
        {
            ans += arr[i] * arr[i];
        }
        return ans;
    }
    void print() override
    {
        cout << "\nClass type - Point_N";
        cout << "\nPrinting Point_N ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\nPrinting norm function - " << norm();
    }
    Point_N(int size)
    {
        n = size;
        arr = new double[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0.0;
        }
    }
    Point_N(vector<int> values, int size)
    {
        n = size;
        arr = new double[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = values[i];
        }
    }

    // ~Point_N(){}
};
void slow_Sort(vector<double> &arr)
{
    int n = arr.size();
    int i, j;
    double temp;
    for (i = 1; i < n; i++)
    {
        // temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > arr[i])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[i];
    }
}
void fast_sort(vector<double> &arr)
{
    int l = 0, r = arr.size();
    if (l < r)
    {

        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        // fast_merge_sort(arr, l, m);
        // fast_merge_sort(arr, m + 1, r);

        // merge(arr, l, m, r);
    }
}
int main()
{

    Point p1(1.2, 1.4);
    p1.print();
    _Vector v1(1.2, 1.8, "right");
    v1.print();

    // Point_N n2(3);
    // n2.norm();
    // n2.print();

    vector<int> values = {1, 2, 3, 4, 5};
    Point_N n3(values, 5);
    n3.norm();
    n3.print();

    // Element* object[1000];
    // vector for storing norms of all objects
    int k = 100;
    vector<double> norms_of_obs;
    for (int i = 0; i < k; i++)
    {
        if (i % 3 == 0)
        {
            Point p;
            p.setCoords(rand() % 100, rand() % 100);
            norms_of_obs.push_back(p.norm());
        }
        else if (i % 3 == 1)
        {
            _Vector v;
            v.setCoords(rand() % 100, rand() % 100);
            norms_of_obs.push_back(v.norm());
        }
        else if (i % 3 == 2)
        {
            int size_n = 2 + rand() % 9;
            vector<int> temp_values(size_n);
            for (int i = 0; i < size_n; i++)
            {
                temp_values[i] = rand() % 100;
            }
            Point_N n_arr(temp_values, size_n);
            norms_of_obs.push_back(n_arr.norm());
        }
    }
    cout << "\nPrinting norms of objects - "
         << "\n";
    for (auto it : norms_of_obs)
    {
        // cout << it << " ";
    }
    cout << endl;
    // sort(norms_of_obs.begin(), norms_of_obs.end());
    clock_t start, end;
    start = clock();

    slow_Sort(norms_of_obs);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // time_taken=time_taken*pow(10,6);
    cout << "\nPrinting norms of objects after sorting - "
         << "\n";
    for (auto it : norms_of_obs)
    {
        // cout << it << " ";
    }

    int k_100 = 10;
    vector<double> norms_of_obs_100;
    for (int i = 0; i < k_100; i++)
    {
        if (i % 3 == 0)
        {
            Point p;
            p.setCoords(rand() % 100, rand() % 100);
            norms_of_obs_100.push_back(p.norm());
        }
        else if (i % 3 == 1)
        {
            _Vector v;
            v.setCoords(rand() % 100, rand() % 100);
            norms_of_obs_100.push_back(v.norm());
        }
        else if (i % 3 == 2)
        {
            int size_n = 2 + rand() % 9;
            vector<int> temp_values(size_n);
            for (int i = 0; i < size_n; i++)
            {
                temp_values[i] = rand() % 100;
            }
            Point_N n_arr(temp_values, size_n);
            norms_of_obs_100.push_back(n_arr.norm());
        }
    }
    cout << "\nPrinting norms of objects - "
         << "\n";
    for (auto it : norms_of_obs_100)
    {
        // cout << it << " ";
    }
    cout << endl;
    // sort(norms_of_obs.begin(), norms_of_obs.end());
    clock_t start_100, end_100;
    start_100 = clock();

    slow_Sort(norms_of_obs_100);
    end_100 = clock();
    double time_taken_100 = double(end_100 - start_100) / double(CLOCKS_PER_SEC);
    // time_taken=time_taken*pow(10,6);
    cout << "\nPrinting norms of objects after sorting - "
         << "\n";
    for (auto it : norms_of_obs_100)
    {
        // cout << it << " ";
    }
    cout << "\nTime taken for k = 100 -> " << time_taken << "\n";
    cout << endl;
    cout << "\nTime taken for - k = 10000 -> " << time_taken_100 << "\n";
    cout << endl;
}