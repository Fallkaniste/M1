#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <random>

using namespace std;

#define SIZE 6
#define MAX_MOVES 5

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
  std::random_device dev;
  int * random = new int[size];
  for (size_t i = 0; i < size; i++) {
    random[i] = i+1 ;
  }
  int temp ;
  int value ;
  for (int i = 0; i< size ; i++) {

    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(i,size-1); // distribution in range [1, 6]
    value = (int)dist6(rng) ;
    temp = random[i] ;
    random[i] = random[value] ;
    random[value] = temp ;
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
  }
  return test;
}

int * steepestHillClimbing(int size, int * Q, int * X, int max_attempts) {
  int * bestResult = new int [size];
  for (size_t t = 0; t < max_attempts; t++) {
    X = randomS(size) ;
    for (size_t i = 0; i < size; i++) {
      cout << X[i] << " ";
    }
    cout << endl ;
    if (t == 0) {
      for (size_t i = 0; i < size; i++) {
        bestResult[i] = X[i];
      }
    }
    int nb_moves = 0;
    bool STOP = false ;
    do {
      int * X2 = bestNeighbour(size, Q, X) ;
      if (evaluate(size, Q, X2)<evaluate(size, Q, X)) {
        for (size_t i = 0; i < size; i++) {
          X[i] = X2[i];
        }
      }
      else {
        STOP = true ;
      }
      nb_moves ++ ;
    }
    while ((nb_moves <= MAX_MOVES)||!STOP);
    if (evaluate(size, Q, X)<evaluate(size, Q, bestResult)) {
      for (size_t i = 0; i < size; i++) {
        bestResult[i] = X[i];
      }
    }
  }

  return bestResult;
}

int * readFile (int * size) {
  ifstream file("tsp101.txt");
  string sizeS;
  file >> sizeS ;
  *size = atoi (sizeS.c_str());
  string listS[(*size)*(*size)];
  int * list = new int[(*size)*(*size)];
  for(int i = 0; i < (*size)*(*size); ++i)
  {
      file >> listS[i];
      list[i] = atoi (listS[i].c_str()) ;
  }
    return list ;
}

int main()
{
  int size = 0;

  int * city =  readFile(&size) ;
  cout << "SIZE: " << size << endl ;
  //whatever value of S
  int * S= randomS(size);
  for (size_t i = 0; i < size; i++) {
    cout << S[i] << " " ;
  }
  //TODO RANDOM solution


  /*
  cout << "Steepest Hill Climbing method with random :" << endl  ;
  int * a = steepestHillClimbing(size, Q, S, 8);
  for (size_t i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl << evaluate(size, Q, a) << endl ;*/
  /*int * a = bestNeighbour(SIZE, Q, S);
  cout << endl << evaluate(SIZE, Q, a) << endl;*/
    return 0;
}
