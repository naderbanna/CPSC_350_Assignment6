#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <iomanip>

using namespace std;


int main(int argc, char** argv){

  //create file of random doubles
  fstream numFile;
  numFile.open("randomNumbers.txt");
  int min = 0;
  int max = 25;
  int numDouble = 10;
  random_device rd;
  default_random_engine eng(rd());
  uniform_real_distribution<double> distr(min, max);

  numFile << numDouble << endl;
  for(int i = 0; i < numDouble; ++i){
    numFile << setprecision(4) << distr(eng) << "\n";
  }

  numFile.close();


  //read file and input into array
  numFile.open("randomNumbers.txt");
  string line = "";

  double * values;
  //values = new int [];
  getline(numFile, line);
  values = new double[stoi(line)];

  //string line = "";
  for(int i = 0; getline(numFile, line); ++i){
    double numV = stod(line);
    values[i] = numV;

  }


  for (int i = 0; i < numDouble; i++){
    cout << values[i] << endl;
  }
  cout << "end" << endl;
  return 0;
};
