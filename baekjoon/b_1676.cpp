#include <iostream>

using namespace std;
// 5의 약수 개수 세기
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, ans = 0;
    cin >> n;

    for(int i = 5; i<=n; i+=5){
        // cout << "[i]: " << i << "\n";
        int tmp = i, cnt =0;
        for(int j=5; j<=i; j*=5){
            // cout << "(j): " << j << '\n';
            if(tmp % 5 == 0) {
                tmp /= 5;
                cnt++;
            }
            // cout << "tmp: "<< tmp << " | cnt: " << cnt << "\n";
        }
        ans += cnt;
    }
    cout << ans;

    return 0;
}