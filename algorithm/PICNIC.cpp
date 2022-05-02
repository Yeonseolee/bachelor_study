#include <iostream>
#include <cstring>

// 해멘 부분 : areFriends 값 받을 때 순서가 바뀌어도 상관없어야한다는 점을 놓침.


using namespace std;

// 친구인지의 여부
bool areFriends[10][10];

// taken[10] : true 면 이미 짝지어진

// 사전 순으로 짝 해결
int countP(bool taken[10], int n){

    int firstFree = -1;

    for(int i = 0; i<n; i++){
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }

    // cout << "\n" << firstFree << "\n";
    // for(int i = 0; i < 10; i++) cout << taken[i] << " ";
    // cout << "\n";


    // 기저사례
    if(firstFree == -1) return 1;

    int ret = 0;

    for(int pairWith = firstFree+1; pairWith < n; pairWith++){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countP(taken, n);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    // cout << "ret is : " << ret << '\n';
    return ret;
}



int main(void){
    int c, n, m;
    cin >> c;
    for(int i = 0; i <c; i++){
        int ans = 0;
        cin >> n >> m;

        // 배열들 초기화
        bool taken[10] = {0,};
        for(int j = 0; j<10; j++){
            memset(areFriends[j], 0, sizeof(bool)*10);
        }


        for(int j = 0; j < m; j++){
            int f1, f2;
            cin >> f1 >> f2;

            // (0,3) == (3, 0) 같아야함.
            areFriends[f1][f2] = true;
            areFriends[f2][f1] = true;
        }

        // for(int j = 0; j < 10; j++){
        //     for(int k = 0; k < 10; k++){
        //         cout << areFriends[j][k] << " ";
        //     }
        //     cout << '\n';
        // }

        ans = countP(taken, n);

        cout << ans << '\n';

    }

    return 0;
}