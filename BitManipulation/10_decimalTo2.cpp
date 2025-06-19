#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    string baseNeg2(int n)
    {
        if (n == 1 || n == 0)
        {
            return to_string(n);
        }
        return baseNeg2(-(n >> 1)) + to_string(n & 1);
    }
    string base2(int n)
    {
        if (n == 1 || n == 0)
        {
            return to_string(n);
        }
        return baseNeg2((n >> 1)) + to_string(n & 1);
    }
};