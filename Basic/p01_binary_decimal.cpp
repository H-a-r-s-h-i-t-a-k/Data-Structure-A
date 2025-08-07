

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, i = 0, ans = 0;

    cin >> num;
    while (num != 0)
    {
        int digit = num % 10;
        if (digit == 1)
            ans = ans + pow(2, i);
        num = num / 10;
        i++;
    }
    cout << ans << endl;
    return 0;
}
class Solution
{
public:
    int binaryToDecimal(string &b)
    {
        // Code here.step
        // step 1 pick last bit  and also count digit from least significant digit
        // step 2 if last bit set then add in  result using in form of 2 pow digit count
        // step 3 return ans;

        // int res=0;
        // int c=0;
        // int n=b.size()-1;
        // while(n!=-1)
        // {
        //     int digit=b[n]-'0';
        //     if(digit){
        //         res+=pow(2,c);
        //     }
        //     c++;
        //     n--;

        // }
        int decimalNumber = 0;
        for (size_t i = 0; i < b.length(); i++)
        {
            decimalNumber = decimalNumber * 2 + (b[i] - '0');
        }

        return decimalNumber;

        //      int dec_num = 0;
        //   int power = 0 ;
        // int n = b.length() ;

        //   for(int i = n-1 ; i>=0 ; i--){
        //   if(b[i] == '1'){
        //     dec_num += (1<<power) ;
        //   }
        //   power++ ;
        // }

        // return dec_num;
    }
};