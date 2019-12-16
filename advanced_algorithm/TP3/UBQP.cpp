#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define SIZE 6
#define MAX_MOVES 10

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

int * randomS(int size) {
  int * random = new int[size];
  srand (time(NULL));
  for (int i = 0; i< size ; i++) {
    random[i] = rand() % 2;
  }
  return random;
}

int * bestNeighbour(int size, int * Q, int * X) {
  int temp[size][size] ;
   for (size_t i = 0; i < size; i++) {
     for (size_t j = 0; j < size; j++) {
       temp[i][j] = Q[i*size + j];
     }
   }
  int neighbourResult[size] ;
  int a = 0;
  int * test = new int[size];
  int min = 50000;
  for (size_t k = 0; k < size; k++) {
    int result = 0;
    X[k]=(X[k]+1)%2 ;
    for (size_t i = 0; i < size; i++) {
      for (size_t j = 0; j < size; j++) {
        result = result +temp[i][j] * X[i] * X[j];
      }
    }
    neighbourResult[k] = result ;
    if (result < min) {
      min = result ;
      for (size_t i = 0; i < size; i++) {
        test[i] = X[i] ;
      }
    }
    X[k]=abs((X[k]-1)%2) ;
    cout << result << " " ;
  }
  cout << endl ;
  return test;
}


// TODO
// Fix rand so it can give more than  a rand per sec
int * steepestHillClimbing(int size, int * Q, int * X, int max_attempts) {
  int * bestResult;
  for (size_t t = 0; t < max_attempts; t++) {
    X = randomS(size) ;
    /*if (t == 0) {
      for (size_t i = 0; i < SIZE; i++) {
        bestResult[i] = X[i];
      }
    }*/
    int nb_moves = 0;
    bool STOP = false ;
    do {
      int * X2 = bestNeighbour(SIZE, Q, X) ;
      if (evaluate(SIZE, Q, X2)<evaluate(SIZE, Q, X)) {
        for (size_t i = 0; i < SIZE; i++) {
          X[i] = X2[i];
        }
      }
      else {
        STOP = true ;
      }
      nb_moves ++ ;
    }
    while ((nb_moves <= MAX_MOVES)||!STOP);
    /*if (evaluate(SIZE, Q, X)<evaluate(SIZE, Q, bestResult)) {
      for (size_t i = 0; i < SIZE; i++) {
        bestResult[i] = X[i];
      }
    }*/
  }

  return X;
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
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      Q[i*6 + j] = Qflat[i][j];
    }
  }
  int S[6] = {1, 1, 0, 1, 0, 0};


  int * a = steepestHillClimbing(SIZE, Q, S, 5);
  for (size_t i = 0; i < SIZE; i++) {
    cout << a[i] << endl;
  }
  cout << endl << evaluate(SIZE, Q, a) << endl ;
  /*int * a = bestNeighbour(SIZE, Q, S);
  cout << endl << evaluate(SIZE, Q, a) << endl;*/
    return 0;
}
