#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

void swap(int* a, int* b)
{
 int t = *a;
 *a = *b;
 *b = t;
}

int partition(vector<int> &arr, int low, int high)
{
    Sleep(1);
 int pivot = arr[high]; // pivot
 int i
  = (low
  - 1);
 for (int j = low; j <= high - 1; j++) {
  if (arr[j] < pivot) {
   i++;
   swap(&arr[i], &arr[j]);
  }
 }
 swap(&arr[i + 1], &arr[high]);
 return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    Sleep(1);
 if (low < high) {
  int pi = partition(arr, low, high);
  quickSort(arr, low, pi - 1);
  quickSort(arr, pi + 1, high);
 }
}

void printArray(vector<int> &arr, int size)
{
 int i;
 for (i = 0; i < size; i++)
  cout << arr[i] << " ";
    cout<<"\n";
 cout << endl;
}

int main()
{
    int n;
    cout << "enter the number of terms: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = clock();
 quickSort(arr, 0, n - 1);     
    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    for (auto x : arr)
        cout << x << " ";
    cout<<"\n";    
    cout << fixed << "Time taken by function: " << setprecision(20) << fixed << duration << " seconds" << endl;
}