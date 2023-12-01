#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
class point{
    private:
    static int count;
    double x;
    double y;

    static double tolerance;
    public:
    void setCoords(double x,double y);
    void printCoords();
    double distanceFrom(point&p);
    // point();
    // point(point&p);
    // const int the argument means the point p cant be modified inside the class
    point operator + (point p) ;  //this is overloaded operator class return type point argument point
    bool operator < (const point& p) const;
    bool operator > (const point& p) const;
    bool operator == (const point& p) const;
    point operator*(const double&p)const;
    double operator[](int index)const;
    friend ostream & operator<<(ostream&out, point&c);
    static void setTolerance(double tol);
    point linearCombine(const point&p,double s){
        point q;
        q=p*(1-s)+*(this)*s;
        return q;
    }
    double l2norm(); 
    static int getcount;
};

  double point::tolerance=0;
ostream& operator << (ostream& out, point &c)
{
  double norm=c.l2norm();
  out<<"Point ( "<<c.x<<" , "<<c.y<<" ) norm = "<<norm<<endl;
   return out;
}
  double point::operator[](int index)const{
          if(index==0){
            return this->x;
          }
          if(index==1){
            return this->y;
          }
          return 7.2;
  }
  double point::l2norm(){
    return sqrtf(pow(this->x,2)+pow(this->y,2));
  }

  void point::setTolerance(double tol){
    tolerance=tol;
  }
  point point::operator*(const double&p)const{
    point t;
    t.x=this->x*p;
    t.y=this->y*p;
    return t;
  }
point point::operator+(point p) {
    point result;
    result.x = this->x + p.x;
    result.y = this->y + p.y;
    return result;
}
 void point::setCoords(double x,double y){
     this->x=x;
     this->y=y;
}
void point::printCoords(){
    cout<<this->x<<" "<<this->y<<endl;
}
bool point::operator<(const point&p)const{
      double d2=pow(p.x,2)+pow(p.y,2);
      double d1=pow(this->x,2)+pow(this->y,2);
      if(d1<d2){
        return true;
      }
      return false;
}
bool point::operator>(const point&p)const{
      double d1=pow(this->x,2)+pow(this->y,2);
      double d2=pow(p.x,2)+pow(p.y,2);
      if(d1>=d2){
        return true;
      }
      return false;
}
bool point::operator==(const point&p)const{
      double d2=pow(p.x,2)+pow(p.y,2);
      double d1=pow(this->x,2)+pow(this->y,2);
       if((d1-d2)<tolerance){
         return true;
       }
      return false;
}
void insertionSort(point arr[],int n){
    for (int i = 1; i < n; i++) {
        point key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1]=key;
    }
}
void randomize(point arr[],int n){
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i].setCoords(rand()%100,rand()%100);
    }
}
int main()
{   
    point arr[4];
    point p1,p2,p3,p4;
    p1.setCoords(10.0,7.3);
    p2.setCoords(6.2,3.5);
    p4.setCoords(8.3,6.4);
    p3=p1+p2;
    p1.setTolerance(1);
    arr[0]=p1,arr[1]=p2,arr[2]=p3,arr[3]=p4;
    p3.printCoords();
    bool less=p1<p2;
    bool greater=p1>p2;
    bool equal=p1==p2;
    point t=p1.linearCombine(p2,.5);
    // t.printCoords();
    point t2=p1*2;
    // t2.printCoords();
    double x=p1[0],y=p1[1];
    cout<<x<<" "<<y<<" p1 coord"<<endl;
    cout<<p1.l2norm()<<" ecludian dist"<<endl;
    // cout<<less<<" "<<greater<<" "<<equal<<endl;
    // cout<<p1<<endl;
    // insertionSort(arr,4);
    // for(int i=0;i<4;i++){
    //   cout<<arr[i]<<endl;
    // }
  point arr1[10],arr2[100],arr3[1000],arr4[10000];
    randomize(arr1,10);
    randomize(arr2,100);
    randomize(arr3,1000);
    randomize(arr4,10000);
    auto start = high_resolution_clock::now();
    insertionSort(arr1,10);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function for 10 points: "
         << duration.count() << " microseconds" << endl;
    start = high_resolution_clock::now();
    insertionSort(arr2,100);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function for 100 points: "
         << duration.count() << " microseconds" << endl;
    start = high_resolution_clock::now();
    insertionSort(arr3,1000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function for 1000 points: "
         << duration.count() << " microseconds" << endl;
    start = high_resolution_clock::now();
    insertionSort(arr4,10000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function for 10000 points: "
         << duration.count() << " microseconds" << endl;
    return 0;
}