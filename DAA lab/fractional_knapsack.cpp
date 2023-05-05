#include <bits/stdc++.h>
#include<windows.h>
using namespace std;

struct Item
{
    int value, weight;
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &arr, int N)
{
    Sleep(1);
    sort(arr.begin(), arr.end(), cmp);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main()
{
    int W, N;
    cout << "Enter Knapsack capacity W: ";
    cin >> W;

    cout << "Enter no. of items: ";
    cin >> N;

    vector<int> value(N), weight(N);
    cout << "Enter weight and value of " << N << " items:\n";
    for (int i = 0; i < N; i++)
        cin >>weight[i]>> value[i];
    
    auto start = clock();
    vector<Item> arr;
    for (int i = 0; i < N; i++)
    {
        struct Item temp = {value[i], weight[i]};
        arr.push_back(temp);
    }
    double ans = fractionalKnapsack(W, arr, N);
    cout << "Max Value: " << ans << "\n";
    float duration = clock() - start;
    duration = (duration) / CLOCKS_PER_SEC;
    cout << fixed << "Time taken by function: " << setprecision(20) << fixed << duration << " seconds" << endl;
    return 0;
}