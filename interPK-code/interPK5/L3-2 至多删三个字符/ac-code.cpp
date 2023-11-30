#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveProblem(string input){
    int len = input.size();
    i64 dp[len + 1][4] = {0};
    dp[0][0] = 1;
    for(int i = 1; i <= len; i++){
        for(int j = 0; j <= 3; j++){
            if(dp[i-1][j]==0) continue;
            
            if(j < 3) dp[i][j+1]+=dp[i-1][j];
            
            dp[i][j]+=dp[i-1][j]; 
            
            for(int k = i - 1;k>=1 and i - k<=j; k--)
            {
                if(input[i - 1] == input[k - 1])
                {
                    dp[i][j] -= dp[k - 1][j - (i - k)];
                    break;
                }
            }
        }
    }
    printf("%lld\n",dp[len][0]+dp[len][1]+dp[len][2]+dp[len][3]);
}



int main()
{
    string input;
    cin >> input;

    solveProblem(input);
}