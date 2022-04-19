#include <iostream>

using namespace std;

// 에라토스테네스의 체 알고리즘으로 풀어볼 것. 
// 현 방법 : 브루트포스 + 개선된 소수판별법


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = n; i <= m; i++){
        bool isP = true;
        if(i == 1) isP = false;
        else if( i == 2) isP = true;
        else if(i % 2 == 0) isP = false;
        else
        {
            for (int j = 3; j * j <= i; j += 2)
            {
                if (i % j == 0)
                    isP = false;
            }
        }

        if(isP) cout << i << '\n';
    }

    return 0;
}