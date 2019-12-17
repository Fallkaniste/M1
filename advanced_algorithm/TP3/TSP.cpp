#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <random>
#include <math.h>

using namespace std;

#define SIZE 6
#define MAX_MOVES 300

//DONE
float evaluate(int size, int * Q, int * X) {
  int temp[size][size] ;
   for (size_t i = 0; i < size; i++) {
     for (size_t j = 0; j < 3; j++) {
       temp[i][j] = Q[i*3 + j];
     }
   }
  float result =sqrt(temp[X[0]-1][1]*temp[X[0]-1][1] + temp[X[0]-1][2]*temp[X[0]-1][2]);
  result += sqrt(temp[X[size-1]-1][1]*temp[X[size-1]-1][1] + temp[X[size-1]-1][2]*temp[X[size-1]-1][2]) ;
  for (size_t i = 0; i < size-1; i++) {
    result += sqrt((temp[X[i]-1][1]-temp[X[i+1]-1][1]) * (temp[X[i]-1][1]-temp[X[i+1]-1][1]) + (temp[X[i]-1][2]-temp[X[i+1]-1][2]) * (temp[X[i]-1][2]-temp[X[i+1]-1][2]));
  }
  return result;
}

//DONE
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

//DONE
int * TSPbestNeighbour(int size, int * Q, int * X) {
  int numberNeighbours = 0;
  for (size_t i = 0; i < size; i++) {
    numberNeighbours += i ;
  }
  int neighbourResult[size] ;
  int a = 0;
  int * bestNeighbour = randomS(size);
  int min = 50000;
  int temp ;
  int result;
  for (size_t k = 0; k < numberNeighbours; k++) {
    for (size_t i = k; i < size; i++) {
      temp = X[k] ;
      X[k] = X[i] ;
      X[i] = temp;
      result = evaluate(size, Q, X);
      //cout << "Iteration k=" << k << " i=" << i << " result : " << result << endl;
      if (result < min) {
        min = result ;
        for (size_t i = 0; i < size; i++) {
          bestNeighbour[i] = X[i];
        }
      }
      temp = X[k] ;
      X[k] = X[i] ;
      X[i] = temp;
    }
  }
  return bestNeighbour;
}

//DONE
int * TSPsteepestHillClimbing(int size, int * Q, int * X, int max_attempts) {
  int * bestResult = new int [size];
  for (size_t t = 0; t < max_attempts; t++) {
    X = randomS(size) ;
    /*for (size_t i = 0; i < size; i++) {
      cout << X[i] << " ";
    }*/
    cout << "another one" <<endl ;
    if (t == 0) {
      for (size_t i = 0; i < size; i++) {
        bestResult[i] = X[i];
      }
    }
    int nb_moves = 0;
    bool STOP = false ;
    do {
      int * X2 = TSPbestNeighbour(size, Q, X) ;
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


int TSPtabuMethod(int size, int * Q, int * X, int max_attempts) {
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
    cout << "Best result so far : "<< (int)evaluate(size, Q, bestResult) << endl;
    inside = false ;
    for (size_t i = 0; i < max_attempts; i++) {
      if (Tabu[i] == (int)evaluate(size, Q, bestResult)) {
        inside =  true ;
      }
    }
    if (inside) {
      cout << "Result already in Tabu" << endl ;
    }
    else {
      s = TSPbestNeighbour(size, Q, bestResult) ;
      if ((int)evaluate(size, Q, s) < (int)evaluate(size, Q, bestResult)) {
        Tabu[index] = (int)evaluate(size, Q, bestResult);
        index ++;
        for (size_t i = 0; i < size; i++) {
          bestResult[i] = s[i];
        }
      }
    }
    nb_moves ++ ;
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

//DONE
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

  int * S= randomS(size);
  //int S[size] = {5,3,4,1,2};
  /*for (size_t i = 0; i < size; i++) {
    cout << S[i] << " " ;
  }

  for (size_t i = 0; i <size*3; i++) {
    if (i%3 == 0) {
      cout << endl ;
    }
    cout << city[i] << " " ;
  }*/

  //float test = evaluate(size, city, S) ;

  int * a = TSPbestNeighbour(size, city, S) ;
  cout << evaluate(size, city, a) << endl;
  /*int * b = TSPsteepestHillClimbing(size, city, S, 10) ;
  cout << evaluate(size, city, b) << endl;*/

  int c =  TSPtabuMethod(size, city, S, 500);
  cout << c << endl ;
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
