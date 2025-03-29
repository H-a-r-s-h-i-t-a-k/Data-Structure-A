#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void solve(int num, vector<string> &map)
{
    if (num == 0)
        return;

    int rem = num % 10;
    num = num / 10;
    solve(num, map);
    cout << map[rem] << " ";
}
int main()
{
    int num = 87446;
    if (num == 0)
    {
        cout << "zero";
        return 0;
    }
    vector<string> map = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    solve(num, map);

    return 0;
}