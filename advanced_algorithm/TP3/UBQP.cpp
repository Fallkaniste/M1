#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int bestNeighbour(int size, int * Q, int *X) {
  int temp[size][size] ;
   for (size_t i = 0; i < size; i++) {
     for (size_t j = 0; j < size; j++) {
       temp[i][j] = Q[i*size + j];
     }
   }

    int neighbourResult[size] ;

    int a = 0;

    for (size_t k = 0; k < size; k++) {
      int result = 0;
      X[k]=(X[k]+1)%2 ;
      for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
          result = result +temp[i][j] * X[i] * X[j];
        }
      }
      neighbourResult[k] = result ;
      X[k]=abs((X[k]-1)%2) ;
      cout << result << " " ;
    }
    cout << endl ;

    int min = *min_element(neighbourResult + 0, neighbourResult + (size-1)) ;
    return min;
}

int evaluate(int size, int * Q, int * X) {
  int temp[size][size] ;
   for (size_t i = 0; i < size; i++) {
     for (size_t j = 0; j < size; j++) {
       temp[i][j] = Q[i*size + j];
     }
   }
  int result = 0;
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      result = result +temp[i][j] * X[i] * X[j];
    }
  }
  return result;
}

int * randomX(int size) {
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




  int X[6] = {1, 1, 0, 1, 0, 0};
  for (size_t i = 0; i < 6; i++) {
    cout << X[i] << endl;
  }
  int a = bestNeighbour(6, Q, X);
  cout << endl << a ;
  cout << endl << endl << endl << abs((-1)%2) ;

    return 0;
}
