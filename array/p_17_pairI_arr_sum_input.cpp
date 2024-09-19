
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int getPairsCount(int arr[], int n, int k)
{
    int c = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int b = k - arr[i];
        if (m[b])
        {
            c += m[b];
        }
        m[arr[i]]++;
    }
    return c;
}

int main()
{
    int N = 4, K = 6, arr[] = {1, 5, 7, 1};
    cout << getPairsCount(arr, N, K);
}