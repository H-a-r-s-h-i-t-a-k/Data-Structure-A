#include <bits/stdc++.h>
using namespace std;
int solveBruteForce(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    return arr[n - 1];
}
int solverecursive(vector<int> arr)
{
    int lar = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > lar)
            lar = arr[i];
    }
    return lar;
}
int main()
{
    vector<int> arr = {1,
                       8,
                       7,
                       56,
                       90};
    cout << "BruteForce method: " << solveBruteForce(arr) << endl;
    cout << "solverecursive method: " << solverecursive(arr) << endl;
}