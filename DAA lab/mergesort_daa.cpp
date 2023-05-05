#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r)
{
    Sleep(1);
    int n1 = mid + 1 - l;
    int n2 = r - mid;
    vector<int> strt(n1), end(n2);
    for (int i = 0; i < n1; i++)
        strt[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        end[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (strt[i] < end[j])
        {
            arr[k] = strt[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = end[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = strt[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = end[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &arr, int l, int r)
{
    Sleep(1);
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    merge(arr, l, mid, r);
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
    mergesort(arr, 0, n - 1);
    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    for (auto x : arr)
        cout << x << " ";
    cout<<"\n";    
    cout << fixed << "Time taken by function: " << setprecision(20) << fixed << duration << " seconds" << endl;
}