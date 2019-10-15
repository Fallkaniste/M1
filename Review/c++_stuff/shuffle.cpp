#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int tab[9]={1,2,3,4,5,6,7,8,0};
int matrix[3][3];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getNumber(int index)
{
  srand (time(NULL));
  if (index!=0)
  {
    int number = rand() % index ;
    swap(tab[number], tab[index]) ;
    return tab[index];
  }
  return tab[0];
}

void shuffleMatrix()
{
  int index=8;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      index--;
      matrix[i][j]=getNumber(index);
    }
    matrix[2][2] = 0;
  }
}

bool verifyMatrix()
{
  int temp=0;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      tab[temp]=matrix[i][j];
      temp++;
    }
  }
  for (size_t i = 0; i < 7; i++) {
    if(tab[i]!=tab[i+1]-1){
      return 1;
    }
  }
  return 0;
}

void printMatrix()
{
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void moveNumbers()
{
  int i0,j0, top, bot, left, right;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if(matrix[i][j]==0)
      {
        i0=i;
        j0=j;
      }
    }
  }
    cout << "POS DE 0 : " <<i0<<" "<<j0<< endl;
    cout << matrix[i0][j0]<<endl;
    cout <<"Available numbers :"<< endl;

    bot=matrix[i0][j0-1];
    top=matrix[i0][j0+1];
    right=matrix[i0+1][j0];
    left=matrix[i0-1][j0];
    if(j0-1>=0)
    {
      cout << bot <<" ";
    }
    if(j0+1<=2)
    {
      cout << top <<" ";
    }
    if(i0+1<=2)
    {
      cout << right <<" ";
    }
    if(i0-1>=0)
    {
      cout << left <<" ";
    }

    int number;
    cout << "Please enter the number to move :" << endl;
    cin >> number;
    while(number!=top&&number!=bot&&number!=left&&number!=right)
    {
      cout << "Please enter an available number to move :" << endl;
      cin >> number;
    }
    if (number==top)
    {
      swap(matrix[i0][j0], matrix[i0][j0+1]);
    }
    else if(number==bot)
    {
      swap(matrix[i0][j0], matrix[i0][j0-1]);
    }
    else if(number==left)
    {
      swap(matrix[i0][j0], matrix[i0-1][j0]);
    }
    else if(number==right)
    {
      swap(matrix[i0][j0], matrix[i0+1][j0]);
    }
    else
    {
      cout<<"the number you entered isn't available"<<endl;
    }
}

int main()
{
  shuffleMatrix();
  while(verifyMatrix())
  {
    system("clear");
    printMatrix();
    moveNumbers();
  }
 cout <<endl<< "GAME OVER, CONGRATULATION" << '\n';
}
