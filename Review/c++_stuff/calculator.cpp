#include <iostream>
using namespace std;

void Add(int x,int y)
{
  cout << "Result : " << x+y << endl;
}

void Substract(int x,int y)
{
  cout << "Result : " << x-y << endl;
}

void Multiply(int x,int y)
{
  cout << "Result : " << x*y << endl;
}

void Divide(int x,int y)
{
  cout << "Result : " << (float)x/(float)y << endl;
}

void Modulus(int x,int y)
{
  cout << "Result : " << x%y << endl;
}

int main()
{
  int choice, x, y;
  bool calc = 1;
  char answer;

  while (calc==1)
  {
    system("clear");
    cout << endl <<" MENU " << endl
    << "1. Add" << endl
    << "2. Subtract" << endl
    << "3. Multiply"<< endl
    << "4. Divide "<< endl
    << "5. Modulus" << endl;

    cout << endl << " Please enter your choice :" << endl;
    cin >> choice;

    cout << endl << " Please enter your two numbers :" << endl;
    cin >> x;
    cin >> y;

    switch (choice)
      {
        case 1:
          Add(x,y);
          break;

        case 2:
          Substract(x,y);
          break;

        case 3:
          Multiply(x,y);
          break;

        case 4:
          Divide(x,y);
          break;

        case 5:
          Modulus(x,y);
          break;

        default:
              return -1;
      }
      cout << endl << "Continue (y/n) ?"<<endl;
      cin >> answer ;

      if(answer =='y'){
        calc=1;
      }
      else{
        calc=0;
      }
  }
  return 0;
}
