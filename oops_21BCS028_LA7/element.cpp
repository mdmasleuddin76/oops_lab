#include <bits/stdc++.h>
using namespace std;

class Element {
   public:
    virtual void print() = 0;
};

class Point : public Element {
   public:
    void print() { cout << "Print function from Point" << endl; }
};
class Vector : public Element {
   public:
    void print() { cout << "Print function from Vector" << endl; }
};
class Location : public Point {};

int main() {
    cout << __FILE__ << endl << endl;
    Point p;
    Vector v;
    Location l;
    cout << "Calling print function from Point, Vector and Location "
            "respectively : \n";
    p.print();
    v.print();
    l.print();
    cout << endl;
}

// Questions :
// 1. Declare an abstract class called Element with a pure virtual function
// called print.

// 2. Modify the Point and Vector classes in your code to inherit from the class
// Element pub- licly. Provide an implementation for the print function for each
// one of them.

// 3. Speculate, if you can you call the print function from an object of type
// Location. Why or why not? Try it and see. What is the result?

// Answers :

// 1. Done
// 2. Done
// 3. Yes, we can call the print function from an object of type Location.
// Because Location is a child class of Point and Point is a child class of
// Element. So, Location is also a child class of Element. So, we can call the
// print function from an object of type Location.