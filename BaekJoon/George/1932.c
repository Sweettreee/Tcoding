#include <stdio.h>
#define SIZE 505

int triangle[SIZE][SIZE]={0,};
int dp[SIZE][SIZE]={0,};
int max=0;

void DP(int n)
{
    dp[0][0] = triangle[0][0];

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j<i){
                if(j==0)
                    dp[i][j] = dp[i-1][j] + triangle[i][j]; // first 
                else{
                    dp[i][j] = (dp[i-1][j]>dp[i-1][j-1]) ? dp[i-1][j] + triangle[i][j] : dp[i-1][j-1] + triangle[i][j]; // middle
                }
            }
            else
                dp[i][j] = dp[i-1][j-1] + triangle[i][j]; // last
            if(i==n-1 && dp[i][j]>max){
                max = dp[i][j];
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }
    DP(n);
    printf("%d\n", max);

    return 0;
}
