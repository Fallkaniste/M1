#include <iostream>
#include <math.h>

using namespace std;

class Point {
  private:
    int x=0;
    int y=0;
  public:
    Point(int x, int y);
    void displayCartesian();
    friend void compare(Point A, Point B);
    friend void distance(Point A, Point B);
    friend void middle(Point A, Point B);
};

Point::Point(int x, int y)
{
  this->x=x;
  this->y=y;
}
void Point::displayCartesian()
{
  cout << "X coordinate : " << this->x << endl << "Y coordinate :"<<this->y<<endl;
}
void compare(Point A, Point B)
{
  if(A.x==B.x&&A.y==B.y)
  {
    cout << "Points are identical" << endl;
  }
  else
  {
    cout << "Points are not identical" << endl;
  }
}
void distance(Point A, Point B)
{
  cout << "The distance between this two points is : " << sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y)) << endl;
}
void middle(Point A, Point B)
{
  cout << "The middle point is {"<<(float)(A.x+B.x)/2<<";"<<(float)(A.y+B.y)/2<<"}"<<endl;
}

int main() {
  Point P(4,2);
  Point V(3,5);
  cout << endl;
  std::cout << "First point :" << '\n';
  P.displayCartesian();
  cout << endl;
  std::cout << "Second point :" << '\n';
  V.displayCartesian();
  cout << endl;
  compare(P,V);
  cout << endl;
  distance(P,V);
  cout << endl;
  middle(P,V);
  cout << endl;
  return 0;
}
