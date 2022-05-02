#include <iostream>

using namespace std;

int dp[11]= {0};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i<=11; i++){

        if (i == 1) dp[i] = 1;
        else if (i == 2) dp[i] = 2;
        else if (i == 3) dp[i] = 4;
        for (int j = 4; j <= 11; j++) {
            dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
        }
    }

    int t, n;
    cin >> t;

    for(int i = 0; i<t; i++){
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}