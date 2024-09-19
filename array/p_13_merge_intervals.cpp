
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++)
    {
        int f = intervals[i][0], s = intervals[i][1];

        if (!res.empty() && f <= res.back()[1])
        {
            if (s > res.back()[1])
            {
                res.back()[1] = s;
            }
        }
        else
            res.push_back(intervals[i]);
    }

    return res;
}

int main()
{
    vector<vector<int>> intv = {{1, 4}, {2, 9}, {3, 6}, {8, 56}, {45, 55}};

    merge(intv);
    for (auto it : intv)
    {
        cout << it[0] << " " << it[1] << endl;
    }
}