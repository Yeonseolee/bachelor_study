#include <iostream>

using namespace std;

int combiRecur(int n, int k){
    if(k == 0 || n == k) {
        return 1;
    } else {
        return combiRecur(n-1, k-1) + combiRecur(n-1, k);
    }

}

int main(void){
    int n, k, result;
    cin >> n >> k;

    result = combiRecur(n, k);
    cout << result;
    return 0;
}