// Fibonacci Series using Recursion
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int fib(int n)
{
    Sleep(1);
    if ((n == 1) || (n == 0))
        return (n);
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n, i = 1;
    cout << "Enter no. of terms: ";
    cin >> n;
    auto start = clock();
    while (i <= n)
    {
        cout << " " << fib(i);
        i++;
    }
    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    cout << "\nTime taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;
    return 0;
}