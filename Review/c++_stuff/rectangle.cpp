#include <iostream>
using namespace std;

class Rectangle {
  private:
    int width;
    int height;
  public:
    Rectangle(int w, int h);
    int getPerimeter();
    int getSurface();
    friend void printRectangle(Rectangle R);
};

Rectangle::Rectangle(int w, int h)
{
  width=w;
  height=h;
}

int Rectangle::getPerimeter() {
  return (this->width*2+this->height*2);
}
int Rectangle::getSurface() {
  return (this->width*this->height);
}

void printRectangle(Rectangle R) {
  for (size_t i = 0; i < R.width; i++) {
    for (size_t j = 0; j < R.height; j++) {
      cout<<"*";
    }
    cout<<endl;
  }
}

int main() {
  int width = 5;
  int height = 3;
  Rectangle R(width, height);
  printRectangle(R);
  cout <<endl <<"Perimeter = " << R.getPerimeter()<<endl;
  cout << "Surface = " << R.getSurface()<<endl;
  return 0;
}
