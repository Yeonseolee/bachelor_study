#include <iostream>
#include <cstring>

using namespace std;

// 완전탐색 버전
int tmp[2];
int fibonaccci(int x){
    if(x == 0) {
        tmp[0]++;
        return 0;
    }
    else if(x == 1) {
        tmp[1]++;
        return 1;
    }
    
    return fibonaccci(x-1) + fibonaccci(x-2);
}

//f0 계산하는
int ansF0[40] = {0};

int fiboF0(int x){
    if(x == 0) {
        ansF0[0] = 1;
        return 1;
    }
    else if(x == 1) {
        ansF0[1] = 0;
        return 0; 
    }

    int& ret = ansF0[x];

    if(ret != 0) return ansF0[x];

    return ansF0[x] = fiboF0(x-1) + fiboF0(x-2);

}

//f1 계산하는
int ansF1[40] = {0};

int fiboF1(int x){
    if(x == 0) {
        ansF1[0] = 0;
        return 0;
    } else if(x == 1) {
        ansF1[1] = 1;
        return 1; 
    }

    int& ret = ansF1[x];

    if(ret != 0) return ansF1[x];

    return ansF1[x] = fiboF1(x-1) + fiboF1(x-2);
}

int ans[40][2] = {0};
void fibo(int x){
    if(x == 0){
        ans[0][0] = 1;
        return ;
    } else if(x == 1){
        ans[1][1] = 1;
        return ;
    } else if(ans[x][0] != 0 && ans[x][1] != 0) {return ;}
    else {
        fibo(x-1);
        fibo(x-2);
        ans[x][0] += ans[x-1][0] + ans[x-2][0];
        ans[x][1] += ans[x-1][1] + ans[x-2][1];
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;

    for(int i = 0; i<t; i++){
        cin >> n;
        fiboF0(n); fiboF1(n);
        cout << ansF0[n] << " " << ansF1[n] << '\n';
    }

    return 0;
}