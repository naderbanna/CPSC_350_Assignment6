#include <iostream>

class algorithms{
  public:
    static void QuickSort(double * arr, int low, int high);
    static void MergeSort(double * arr, int i, int k);
    static void SelectionSort(double * arr, int numSize);
    static void InsertionSort(double * arr, int numSize);
    static void BubbleSort(double * arr, int numSize);
    // void MergeSort();
    // void SelectionSort();
    // void InsertionSort();
    // void BubbleSort();
  private:
    static int Partition(double * arr, int low, int high);
    static void Merge(double * arr, int i, int j, int k);
};
