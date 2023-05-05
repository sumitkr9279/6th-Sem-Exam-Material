#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n)
{
    Sleep(1);
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            Sleep(1);
            int notTaken = 0 + dp[ind - 1][cap];

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];

            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n - 1][W];
}

int main()
{
    int n, w;
    cout << "Enter no.of items and capacity" << endl;
    cin >> n >> w;
    cout << "Enter the value of items and their weights" << endl;
    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }

    auto start = clock();

    int ans = knapsack(w, wt, val, n);
    cout << "Max value gain: " << ans << endl;

    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    cout << "Time taken by function: " << setprecision(10) << fixed << duration << " seconds" << endl;
}