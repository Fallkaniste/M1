#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int evaluate(int size, int * Q, int * X) {
  int temp[size][size] ;
   for (size_t i = 0; i < size; i++) {
     for (size_t j = 0; j < size; j++) {
       temp[i][j] = Q[i*size + j];
     }
   }
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
    cout << temp[i][j] << " ";
    }
    cout << endl ;
  }

}

int * initialSolution(int size) {
  int * random = new int[size];
  srand (time(NULL));
  for (int i = 0; i< size ; i++) {
    random[i] = rand() % 2;
  }
  return random;
}

int main()
{
  int Qflat[6][6] = {{-17, 10, 10, 10, 0, 20},
                    {10, -18, 10, 10, 10, 20},
                    {10, 10, -29, 10, 20, 20},
                    {10, 10, 10, -19, 10, 10},
                    {0, 10, 20, 10, -17, 10},
                    {20, 20, 20, 10, 10, -28}};

  int * Q = new int[36];

  for (size_t i = 0; i < 6; i++) {
    for (size_t j = 0; j < 6; j++) {
      Q[i*6 + j] = Qflat[i][j];
    }
  }
  int * X = initialSolution(6);
  for (size_t i = 0; i < 6; i++) {
    cout << X[i] << endl;
  }
  evaluate(6, Q, X);
    return 0;
}
