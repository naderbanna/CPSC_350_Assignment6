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


  getline(numFile, line);
  int arrSize = stoi(line);

  double * values;
  values = new double[arrSize];

  for(int i = 0; getline(numFile, line); ++i){
    values[i] = stod(line);;
  }


  for (int i = 0; i < numDouble; i++){
    cout << values[i] << endl;
  }

  delete values;
  return 0;
};
