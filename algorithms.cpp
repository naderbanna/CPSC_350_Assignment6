#include <string>
#include <iostream>
#include "algorithms.h"

int algorithms::Partition(double * arr, int low, int high){
  int midpoint = (low + (high - low))/2;
  double pivot = arr[midpoint];

  bool done = false;
  while(!done){
    while(arr[low] < pivot){
      low += 1;
    }

    while(pivot < arr[high]){
      high -= 1;
    }

    if(low >= high){
      done = true;
    }else{
      double temp = arr[low];
      arr[low] = arr[high];
      arr[high] = temp;

      low += 1;
      high -= 1;
    }
  }
  std::cout << "partition: " << pivot << std::endl;
  return high;
}

void algorithms::QuickSort(double * arr, int low, int high){

  std::cout << "low - high: " << low << " , " << high << std::endl;

  if(low < high){
    int lowEndIndex = Partition(arr, low, high);
    QuickSort(arr, low, lowEndIndex);
    if(low < high){
      QuickSort(arr, lowEndIndex + 1, high);
    }
  }


}

//merge sort

void algorithms::Merge(double * arr, int i, int j, int k){
  int mergedSize = k - i + 1;
  int mergePos = 0;
  int leftPos = 0;
  int rightPos = 0;
  double * mergedNumbers;
  mergedNumbers = new double[mergedSize];

  leftPos = 1;
  rightPos = j + 1;

  while(leftPos <= j && rightPos <= k){
    if(arr[leftPos] <= arr[rightPos]){
      mergedNumbers[mergePos] = arr[leftPos];
      ++leftPos;
    }
    else{
      mergedNumbers[mergePos] = arr[rightPos];
      ++rightPos;
    }
    ++mergePos;
  }

  while(leftPos <= j){
    mergedNumbers[mergePos] = arr[rightPos];
    ++rightPos;
    ++mergePos;
  }
  for(mergePos = 0; mergePos < mergedSize; ++mergePos){
    arr[i + mergePos] = mergedNumbers[mergePos];
  }
}

void algorithms::MergeSort(double * arr, int i, int k){
  int j = 0;

  if(i < k){
    j = (i+k)/2;

    MergeSort(arr, i, j);
    MergeSort(arr, j + 1, k);

    Merge(arr, i, j, k);
  }
}

//selection sorting
void algorithms::SelectionSort(double * arr, int numSize){
  int i = 0;
  int j = 0;
  int indexSmallest = 0;
  double temp = 0.0;

  for(i = 0; i < numSize - 1; ++i){
    indexSmallest = i;
    for(j = i + 1; j < numSize; ++j){
      if(arr[j] < arr[indexSmallest]){
        indexSmallest = j;
      }
    }

    temp = arr[i];
    arr[i] = arr[indexSmallest];
    arr[indexSmallest] = temp;
  }
}


//insertionSort
void algorithms::InsertionSort(double * arr, int numSize){
  int i = 0;
  int j = 0;
  double temp = 0.0;

  for(i = 1; i < numSize; ++i){
    j = i;
    while(j>0 && arr[j] < arr[j-1]){
      temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      --j;
    }
  }
}

void algorithms::BubbleSort(double * arr, int numSize){
  for (int i = 0; i < numSize - 1; i++){
    for(int j = 0; j < numSize - i - 1; j++){
      if (arr[j] > arr[j+1]){
        double temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
