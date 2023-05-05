#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void heapify(vector<int> &arr, int N, int i)
{
    int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < N && arr[l] > arr[largest])
    largest = l;
  if (r < N && arr[r] > arr[largest])
    largest = r;
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, N, largest);
  }
}

void heapSort(vector<int> &arr, int N)
{
    Sleep(1);
  for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = clock();    
    heapSort(arr, n);
    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    cout<<"Sorted array\n";
    for (auto x : arr)
        cout << x << " ";
    cout<<"\n";    
    cout<<"Time taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;  
}

// 4
// 10 7 8 11