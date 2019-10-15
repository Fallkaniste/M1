#include <iostream>
using namespace std;

class Counter {
  private:
    int value=0;
  public:
    void increment();
    void decrement();
    friend void displayValue(Counter C);
};

void Counter::increment()
{
  this->value++;
}

void Counter::decrement()
{
  this->value--;
}

void displayValue(Counter C) {
    cout<<C.value<<endl;
}

int main() {
  Counter c;
  displayValue(c);
  for (size_t i = 0; i < 10; i++) {
    c.increment();
  }
  displayValue(c);
  for (size_t i = 10; i>0 ; i--) {
    c.decrement();
  }
  displayValue(c);
  return 0;
}
