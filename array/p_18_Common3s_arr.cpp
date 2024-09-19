
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    // code here.
    set<int> v;
    vector<int> v1;
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            v.insert(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else
            k++;
    }

    for (auto x : v)
        v1.push_back(x);
    if (v.size() == 0)
        v1.push_back(-1);
    return v1;
}

int main()
{
    int n1 = 6;
    int A[] = {1, 5, 10, 20, 40, 80};
    int n2 = 5;
    int B[] = {6, 7, 20, 80, 100};
    int n3 = 8;
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> ans;
    ans = commonElements(A, B, C, n1, n2, n3);
    for (auto i : ans)
        cout << i << " ";
}