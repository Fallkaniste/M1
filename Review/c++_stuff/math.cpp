#include <iostream>
using namespace std;

int main()
{
  int x,y;

  cout << " Please enter x :" << endl;
  cin >> x;
  cout << " Please enter y :" << endl;
  cin >> y;

  int p = x*y;
  int s = x+y;

  int total = 2*s+p*(s-x)*(p+y);

  cout << "The total is  " << total << endl;
  return 0;
}
