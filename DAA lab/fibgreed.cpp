// Fibonacci Series using Greedy/iterative Technique
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void fib(int n, vector<int> &series)
{
    Sleep(1);
    int a = 0, b = 1, c, i;
    series.push_back(a);
    series.push_back(b);
    if (n == 0)
        return;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        series.push_back(b);
    }
    return;
}

// Driver code
int main()
{
    int n;
    cout << "Enter no. of terms: ";
    cin >> n;
    vector<int> series;
    auto start = clock();
    fib(n, series);
    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;

    for (int i = 1; i <= n; i++)
        cout << series[i] << " ";

    cout << "\nTime taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;
    return 0;
}