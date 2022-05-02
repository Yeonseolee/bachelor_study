#include <iostream>
#include <cstring>

using namespace std;

int cache[40];
int fibonaccci(int x){
    if(x == 0) {
        cache[0]++;
        return 0;
    }
    else if(x == 1) {
        cache[1]++;
        return 1;
    }

    int& ret = cache[x];

    // if(ret != -1) {
    //     cout << x << " ";
    //     return ret;
    // }

    return fibonaccci(x-1) + fibonaccci(x-2);
}


int main(void){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;

    for(int i = 0; i<t; i++){
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cache[0] = 0; cache[1] = 0;
        int tmp = fibonaccci(n);
        // cout << fibonaccci(n) << '\n';
        cout << cache[0] << " " << cache[1] << '\n';
    }
}