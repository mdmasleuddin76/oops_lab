#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;

class Point {
    // Access modifier
   private:
    // 2.private: members are accessible only from within other members of
    // the same class or from their friends. In other words, private members
    // are the exclusive property of a given class.
    double _x;
    double _y;
    static int count;
    static int countTL;
    static int countTR;
    static int countBR;
    static int countBL;
    static const int MAX_COUNT;

    // Access modifier
   public:
    // public: members are accessible from anywhere where the object is
    // visible. This is the least restrictive access level.

    // 3.Scope of member functions is the class they belong to
    // 5.Member function can access all the members of the class or its objects

    // const keyword is used here to make sure that the member function does not
    // modify the object on which it is called.

    // The functions that do not modify the object on which they are called are
    // called accessor functions. The functions that modify the object on which
    // they are called are called mutator functions.
    // accessor functions are often declared as const functions.

    // Declaring these functions as const doesn't allow them to modify the data
    // members of the object. It's a way of indicating that these functions are
    // read-only and won't change the state of the object. This also allows
    // these functions to be called on const objects of the Point class.
    void setCoords(const double x, const double y);
    void printCoords();
    double distFrom(const Point &p) const;
    Point midPoint(const Point &p) const;
    Point();                                // Default constructor
    Point(const double x, const double y);  // Parameterized constructor
    Point(const Point &p);                  // Copy constructor
    ~Point();
    // Destructor
    void incrementCounts();
    void decrementCounts();

    // GETTERS
    double get_x() const { return _x; }
    double get_y() const { return _y; }
};

// static members are initialized before any object of the class can be created.
// they must be initialized outside the class definition.
// static members are like member functions, they are not associated with any
// object of the class. They can be called using the class name and the scope
// resolution operator.
// Memory for static members is allocated only once when the class is defined.
// and shared by all objects of the class.
int Point::count = 0;
int Point::countTL = 0;
int Point::countTR = 0;
int Point::countBR = 0;
int Point::countBL = 0;

// static const members can be initialized outside of the class as well.
const int Point::MAX_COUNT = 100;

Point::Point() {
    cout << "Default constructor called" << endl;
    _x = 0;
    _y = 0;
    count++;
}

Point::Point(const double x, const double y) {
    cout << "Parameterized constructor called" << endl;
    _x = x;
    _y = y;
    count++;
    incrementCounts();
}

Point::Point(const Point &p) {
    cout << "Copy constructor called" << endl;
    _x = p._x;
    _y = p._y;
    count++;
    incrementCounts();
}

double Point::distFrom(const Point &p) const {
    double dx = _x - p._x;
    double dy = _y - p._y;
    return sqrt(dx * dx + dy * dy);
}

Point::~Point() {
    cout << "Point destructor called" << endl;
    count--;
    decrementCounts();
}

void Point::setCoords(const double x, const double y) {
    _x = x;
    _y = y;
}

void Point::printCoords() { cout << "x = " << _x << ", y = " << _y << endl; }

Point Point::midPoint(const Point &p) const {
    Point mid;
    mid._x = (_x + p._x) / 2;
    mid._y = (_y + p._y) / 2;
    return mid;
}

void Point::incrementCounts() {
    if (_x < 0 && _y > 0) {
        countTL++;
    } else if (_x > 0 && _y > 0) {
        countTR++;
    } else if (_x > 0 && _y < 0) {
        countBR++;
    } else if (_x < 0 && _y < 0) {
        countBL++;
    }
    count++;
}

void Point::decrementCounts() {
    if (_x < 0 && _y > 0) {
        countTL--;
    } else if (_x > 0 && _y > 0) {
        countTR--;
    } else if (_x > 0 && _y < 0) {
        countBR--;
    } else if (_x < 0 && _y < 0) {
        countBL--;
    }
    count--;
}

// Statement: const member functions cannot change the state of an object, i.e,
// they cannot change the values of any of the data members.

// Falsification:
// const member functions cannot change the state of only the object on which
// they are called. They can change the state of other objects of the class.

int main() {
    cout << __FILE__ << endl;
    const int width = 100;
    const int height = 100;

    // Create a 2D array of Point objects
    Point points[width][height];

    // Initialize points to be placed on a 100 × 100 grid
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            points[i][j] = Point(i, j);
        }
    }

    // SFML window
    sf::RenderWindow window(sf::VideoMode(800, 800), "2D Visualization");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                // Create a small circle for each point
                sf::CircleShape point(2);
                // Scale for visibility
                point.setPosition(points[i][j].get_x() * 8,
                                  points[i][j].get_y() * 8);
                // Color based on quadrant
                if (points[i][j].get_x() < 50 && points[i][j].get_y() > 50) {
                    point.setFillColor(sf::Color::Red);
                } else if (points[i][j].get_x() > 50 &&
                           points[i][j].get_y() > 50) {
                    point.setFillColor(sf::Color::Green);
                } else if (points[i][j].get_x() > 50 &&
                           points[i][j].get_y() < 50) {
                    point.setFillColor(sf::Color::Blue);
                } else if (points[i][j].get_x() < 50 &&
                           points[i][j].get_y() < 50) {
                    point.setFillColor(sf::Color::Yellow);
                }
                window.draw(point);
            }
        }

        window.display();
    }

    cout << endl;
}

// Run command:
// g++ -c access_modifier.cpp -I /usr/include/SFML/
// g++ access_modifier.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
// ./sfml-app

// Or run command:(single line command)
// g++ -c access_modifier.cpp -I /usr/include/SFML/ && g++ access_modifier.o -o
// sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app