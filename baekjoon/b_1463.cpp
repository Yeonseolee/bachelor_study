#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001] = {0};
int op02(int x){

    if(x == 1) {
        return 0;
    }

    if(dp[x] != 0) return dp[x];

    if(x % 6 == 0){
        dp[x]++;
        dp[x] += min(op02(x/3), op02(x/2));
    }else if (x % 3 == 0){
        dp[x]++;
        dp[x] += min(op02(x/3), op02(x-1));
    } else if (x % 2 == 0){
        dp[x]++;
        dp[x] += min(op02(x/2), op02(x -1));
    } else {
        dp[x]++;
        dp[x] += op02(x-1);
    }

    return dp[x];
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = op02(n);

    cout << ans;

    return 0;
}
