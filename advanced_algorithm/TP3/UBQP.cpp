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
#define MAX_MOVES 20

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
  for (int i = 0; i< size ; i++) {
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,1); // distribution in range [1, 6]
    random[i] = (int)dist6(rng);
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
  int * bestNeighbour = new int[size];
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
        bestNeighbour[i] = X[i] ;
      }
    }
    X[k]=abs((X[k]-1)%2) ;
  }
  return bestNeighbour;
}

int * steepestHillClimbing(int size, int * Q, int * X, int max_attempts, int constraint) {
  int * bestResult = new int [size];
  for (size_t t = 0; t < max_attempts; t++) {
    X = randomS(size) ;
    for (size_t i = 0; i < size; i++) {
      cout << X[i] << " ";
    }
    int total = 0;
    for (size_t i = 0; i < size; i++) {
      total += X[i];
    }
    if (total < constraint)
    {
      cout << "Constraint not respected : " << total << "<" << constraint <<endl;
    }
    else {
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
  }

  return bestResult;
}

int UBQPtabuMethod(int size, int * Q, int * X, int max_attempts) {
  int * bestResult = randomS(size);
  int * s = new int[size];
  int Tabu[max_attempts] ;
  for (size_t i = 0; i < max_attempts; i++) {
    Tabu[i] = 50000;
  }
  int nb_moves = 0 ;
  bool STOP = false ;
  int index = 0;
  bool inside = false;
  do {
    inside = false ;
    for (size_t i = 0; i < max_attempts; i++) {
      if (Tabu[i] == evaluate(size, Q, bestResult)) {
        inside =  true ;
      }
    }
    if (inside) {
      cout << "Result already in Tabu" << endl ;
    }
    else {
      s = bestNeighbour(size, Q, bestResult) ;
      Tabu[index] = evaluate(size, Q, bestResult);
      if (evaluate(size, Q, s) < evaluate(size, Q, bestResult)) {
        for (size_t i = 0; i < size; i++) {
          bestResult[i] = s[i];
        }
      }
    }
    nb_moves ++ ;
    index ++;
  }
  while (nb_moves <= max_attempts) ;
  int min = 50000;
  for (size_t i = 0; i < max_attempts; i++) {
    if (Tabu[i]<min) {
      min = Tabu[i];
    }
  }
  return min;
}

int * readFile (int * size, int * p) {
  ifstream file("graphe12345.txt");
  string sizeS;
  file >> sizeS ;
  *size = atoi (sizeS.c_str());
  string pS;
  file >> pS;
  *p = atoi (pS.c_str());
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
  int p = 0;
  int * Q =  readFile(&size, &p) ;
  cout << "SIZE SIZE " << size << endl ;
  int * S= new int (size);



  cout << "Steepest Hill Climbing method with random :" << endl  ;
  int * a = steepestHillClimbing(size, Q, S, 15, p);
  for (size_t i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl << evaluate(size, Q, a) << endl ;

  int b =  UBQPtabuMethod(size, Q, S, 30) ;
  cout << b << endl;
  /*int * a = bestNeighbour(SIZE, Q, S);
  cout << endl << evaluate(SIZE, Q, a) << endl;*/
    return 0;
}
