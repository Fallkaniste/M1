#include <iostream>
using namespace std;

void recur(int x, int a)
{
  cout << x << " ";
  if (x>0&&a==1)
  {
    recur(x-1,a);
  }
  if (x==0)
  {
    recur(x+1,a-1);
  }
  if (x<100&&a==0)
  {
    recur(x+1,a);
  }
}

int main()
{
  int a = 100 ;
  recur(a,1);
  return 0;
}
