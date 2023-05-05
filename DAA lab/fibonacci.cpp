



// C++ program for Fibonacci Series
// using Dynamic Programming
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

vector<int> series;
int fib(int n)
{
    Sleep(1);
    int f[n + 2];
    int i;

    f[0] = 0;
    f[1] = 1;
    series.push_back(0);
    series.push_back(1);

    for (i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        series.push_back(f[i]);
    }
    return f[n];
}

// Driver code
int main()
{
    int n;
    cout << "Enter no. of terms: ";
    cin >> n;
    auto start = clock();
    fib(n);
    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++)
        cout << series[i] << " ";
    
    cout << "\nTime taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;
    return 0;
}