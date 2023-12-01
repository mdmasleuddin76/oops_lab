#include <bits/stdc++.h>

#include "../../oops_21BCS052_LA4-LA5_report/source_code/complete_point_class/points_header.h"
using namespace std;

/***********************************START_OF_CLASS_DEFINITION_AND_IMPLEMENTATION**********************************************/

class Location : public Point {
    string _address;
    static constexpr double PI = M_PI;
    static constexpr double RADIUS_OF_EARTH = 6371;

   public:
    Location();
    Location(double, double, string);
    Location(double, double);
    // const Location& giving error check it
    // fixed by making getCords function of Point class const (as it should be)
    // My thought is that like if we pass reference of const member to
    // non const function it makes compiler's gears throttle and throw error
    // Something like that is happening ＼💤（´Ｏ｀）／
    double distFrom(const Location &);
    void getData();
    ~Location();
};

double Location::distFrom(const Location &loc) {
    pair<double, double> cordThis = getCords();
    pair<double, double> cordThat = loc.getCords();
    cout << cordThis.first << ", " << cordThis.second << endl;
    cout << cordThat.first << ", " << cordThat.second << endl;
    double mThis = cordThis.second / cordThis.first;
    double mThat = cordThat.second / cordThat.first;
    double angle = (mThis - mThat) / (1 + mThat * mThis);
    angle = atan(angle);
    double distance = fabs(angle) * PI * RADIUS_OF_EARTH;
    return distance;
}

Location::Location(double x, double y, string address)
    : Point(x, y), _address(address) {
    cout << "Parametrised Location Constructor\n";
}
Location::Location(double x, double y) : Point(x, y) {
    cout << "Parametrised Location Constructor\n";
}
Location::Location() : _address("DEFAULT_ADDRESS") {
    cout << "Default Location Constructor\n";
}
Location::~Location() {
    cout << "Destructor Location is called for : " << _address << endl;
}
void Location::getData() {
    cout << "Address : " << _address << endl << "Coords : ";
    printCoords();
}

/***********************************END_OF_CLASS_DEFINITION_AND_IMPLEMENTATION**********************************************/

void questionOnePartOne();
void questionOnePartTwo();
void questionTwo();
int main() {
    cout << __FILE__ << endl << endl;
    questionOnePartOne();
    cout << endl;
    questionOnePartTwo();
    cout << endl;
    questionTwo();
    cout << endl;
    return 0;
}

void questionOnePartOne() {
    cout << "Question 1 Part 1" << endl;
    Location loc(4, 65, "HelloDogg");
    Location locDefault;
    loc.getData();
    Location locWithCoords(1.25, 56);
    locWithCoords.getData();
    locDefault.getData();
}

void questionOnePartTwo() {
    // distFrom mofdified
    cout << "Question 1 Part 2" << endl;
    Location loc1(1.2, 2.5, "loc1");
    Location loc2(1.2, 7.9, "loc2");
    double dist = loc1.distFrom(loc2);
    cout << dist << endl;
}

void questionTwo() {
    cout << "Question 2" << endl;
    Location arr[] = {
        Location(28.66992, 77.29162, "Shahadra mandi, eastern"),
        Location(28.68991, 77.30672, "GTB Brossing, eastern"),
        Location(28.68991, 77.25796, "kalash nagar pusta, eastern"),
        Location(28.64789, 77.29509, "jagatpuri red light, eastern"),
        Location(28.65005, 77.31381, "ISBT Ananad Vihar, eastern"),
        Location(28.67069, 77.26678, "Seelampur T-oint, eastern"),
        Location(28.7111, 77.26034, "khajori chowk, eastern"),
        Location(28.70129, 77.29146, "loni gol chakkar, eastern"),
        Location(28.61812, 77.32086, "kondii Bridge, eastern"),
        Location(28.63583, 77.28713, "nirman vihar, eastern")};

    double totalDist = 0;
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
        totalDist += arr[i].distFrom(arr[i - 1]);
    }
    cout << "Total Distance = " << totalDist << endl;
}