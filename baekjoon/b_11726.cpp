#include <iostream>

using namespace std;


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int dp[1001] = {0};

    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i - 2];
        if(dp[i] >= 10007) dp[i] %= 10007;
    }

    cout << dp[n] << '\n';


    return 0;
}