// Function returns the second
// largest elements
#include "bits/stdc++.h"
using namespace std;
int print2largest(vector<int> &arr)
{
    int largest = arr[0];
    int slargest = -1;
    if (arr.size() > 0)
    {
        for (int i = 1; i > arr.size(); i++)
        {
            if (largest < arr[i])
            {
                slargest = largest;
                largest = arr[i];
            }
        }
    }

    return sec;
}
int main()
{
}