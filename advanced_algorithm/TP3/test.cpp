#include <iostream>
#include <string>
#include <fstream>

int main()
{
    using namespace std;

    ifstream file("./partition6.txt");
    if(file.is_open())
    {
      string sizeS;
      file >> sizeS ;
      int size = atoi (sizeS.c_str());
      string p;
      file >> p;
      string myArray[size*size];

      for(int i = 0; i < size*size; ++i)
      {
          file >> myArray[i];
      }
    }

}
