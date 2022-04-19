#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    
    int ans = 0;

    for(int i = 1; i<=n; i++){
        int sum = i, num = i;
        while (num > 0)
        {
            sum += num %10;
            num /= 10;
        }

        if(sum == n){
            ans = i;
            break;
        }
        
    }

    cout << ans;

    return 0;
}