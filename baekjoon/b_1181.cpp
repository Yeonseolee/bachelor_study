#include <iostream>
#include <string>

#define M   1234567891


// mod == % 연산 == moduler operator
// 모듈러연산 (분배)법칙 : https://velog.io/@gidskql6671/%EB%82%98%EB%A8%B8%EC%A7%80Modulo-%EC%97%B0%EC%82%B0-%EB%B6%84%EB%B0%B0%EB%B2%95%EC%B9%99
// overflow 주의

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string key;

    cin >> n >> key;
    
    unsigned long convSum = 0;
    unsigned long r = 1;
    for(int i = 0; i < n; i++){
        int a = key[i] - 'a' + 1;
        int ar = (a*r) % M;
        convSum += ar;
        r *= 31;
        r %= M;
    }
    convSum %= M;

    cout << convSum;


    return 0;
}