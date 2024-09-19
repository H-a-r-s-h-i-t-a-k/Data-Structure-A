#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ispossible(int n, int k, vector<int> &stalls, int mid)
{
    int lastvisit = stalls[0];
    int cowcount = 1;
    for (int i = 0; i < n; i++)
    {
        if ((stalls[i] - lastvisit) >= mid)
        {
            cowcount++;
            if (cowcount == k)
                return true;
            lastvisit = stalls[i];
        }
    }
    return false;
}
int aggressive_cow(int n, int k, vector<int> &stalls)
{

    int s = 0;

    int ans = -1;
    int e = stalls[n - 1] - stalls[0];
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (ispossible(n, k, stalls, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    return aggressive_cow(n, k, stalls);
}
int main()
{
    int n, k;
    vector<int> stalls;
    cin >> n >> k;
    while (n--)
    {
        int num;
        cin >> num;
        stalls.push_back(num);
    }
    cout << solve(n, k, stalls);
}