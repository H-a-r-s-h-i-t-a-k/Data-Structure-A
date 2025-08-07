#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long num, i = 0, ans = 0;

    cin >> num;
    while (num != 0)
    {
        long long bit = num & 1;
        ans = (bit * pow(10, i)) + ans;
        num = num >> 1;
        i++;
    }
    cout << ans << endl;
    return 0;
}
class Solution
{
public:
    string decToBinary(int n)
    {
        // code here
        // B
        // RUTE FORSE
        // 1 APPROCH
        // STEP 1 DIVIDE BY 2
        // STEP 2 STORE REMAINDER
        // STEP 3 REPEAT ABOVE PROCESS UNTIL N!=0
        // STEP 4 REVERSE THE ANSWER

        // string ans ="";
        // while(n!=0){
        //     int rem=n%2;
        //     n=n/2;
        //     if(rem){
        //         ans="1"+ans;
        //     }else{
        //         ans="0"+ans;
        //     }
        // }
        // return ans;

        // approach 2;

        // step 1 divide /2 using right shift operator
        // step 2 store the even odd using num&1  check last bit set or not
        // step 3 repeat above process
        // step 4 reverse the ans

        unsigned long long ans = 0;
        int i = 0;
        while (n != 0)
        {
            int bit = n & 1;
            ans = bit * pow(10, i) + ans;
            n = n >> 1;
            i++;
        }
        return to_string(ans);
    }
};