#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <iomanip>
#include <ctime>
#include "algorithms.h"

using namespace std;

int main(int argc, char** argv){

  //create file of random doubles
  fstream numFile;
  numFile.open("randomNumbers.txt", ios::out | ios::trunc);

  int min = 0;
  int max = 100;
  int numDouble = 1000;

  random_device rd;
  default_random_engine eng(rd());
  uniform_real_distribution<double> distr(min, max);

  //input random generated number into test file
  numFile << numDouble << endl;
  for(int i = 0; i < numDouble; ++i){
    numFile << setprecision(4) << distr(eng) << "\n";
  }
  numFile.close();



  //read file and input into array
  numFile.open("randomNumbers.txt");
  string line = "";
  //read first line and assign array size
  getline(numFile, line);
  int arrSize = stoi(line);

  //initial array
  double * values;
  values = new double[arrSize];
  //input file items into array
  for(int i = 0; getline(numFile, line); i++){
    values[i] = std::stod(line);
  }

  numFile.close();

  //copy array 5 times for each sorting algo
  //quick sort
  double * quickSort;
  quickSort = new double[arrSize];
  for (int i = 0; i < arrSize; i++){
    quickSort[i] = values[i];
  }
  // //merge sort
  double * mergeSort;
  mergeSort = new double[arrSize];
  for (int i = 0; i < arrSize; i++){
    mergeSort[i] = values[i];
  }
  // //selection sort
  double * selectionSort;
  selectionSort = new double[arrSize];
  for (int i = 0; i < arrSize; i++){
    selectionSort[i] = values[i];
  }
  // //insertion sort
  double * insertionSort;
  insertionSort = new double[arrSize];
  for (int i = 0; i < arrSize; i++){
    insertionSort[i] = values[i];
  }
  // //bubble sort
  double * bubbleSort;
  bubbleSort = new double[arrSize];
  for (int i = 0; i < arrSize; i++){
    bubbleSort[i] = values[i];
  }

  int low = 0;
  int high = arrSize;


  //algorithms::QuickSort(quickSort, 0, high - 1);

  //algorithms::MergeSort(values, low, high-1);

  clock_t sStart = clock();
  algorithms::SelectionSort(selectionSort, high);
  printf("Selection Sort time taken: %.8fs\n", (double)(clock() - sStart)/CLOCKS_PER_SEC);

  clock_t iStart = clock();
  algorithms::InsertionSort(insertionSort, high);
  printf("Insertion Sort time taken: %.8fs\n", (double)(clock() - iStart)/CLOCKS_PER_SEC);


  clock_t bStart = clock();
  algorithms::BubbleSort(bubbleSort, high);
  printf("Bubble Sort time taken: %.8fs\n", (double)(clock() - bStart)/CLOCKS_PER_SEC);


  //print array
  // cout << "Quick Sort: " << endl;
  // for (int i = 0; i < arrSize; i++){
  //   cout << quickSort[i] << endl;
  // }
  // cout << "Merge Sort: " << endl;
  // for (int i = 0; i < arrSize; i++){
  //   cout << mergeSort[i] << endl;
  // }
  // cout << "Selection Sort: " << endl;
  // for (int i = 0; i < arrSize; i++){
  //   cout << selectionSort[i] << endl;
  // }
  // cout << "Insertion Sort: " << endl;
  // for (int i = 0; i < arrSize; i++){
  //   cout << insertionSort[i] << endl;
  // }
  // cout << "Bubble Sort: " << endl;
  // for (int i = 0; i < arrSize; i++){
  //   cout << bubbleSort[i] << endl;
  // }



  delete values;
  delete quickSort;
  delete mergeSort;
  delete selectionSort;
  delete insertionSort;
  delete bubbleSort;

  return 0;
};
