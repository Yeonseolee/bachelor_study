#include <iostream>

using namespace std;

// 분할만 이뤄지는 예제


// 분할 정복에서 합병하는 과정이 없는데 있는 줄 알고 
// 합병에서 처리하는 과정 생각하다가 시간 버림

// 분할했을 때 인덱스 처리에 대해 미숙해서 
// 각 대각선 끝 좌표 다쓰려다가 복잡해져서 시간 버림

int wCnt = 0, bCnt = 0;

// 분할 : n = 종이 길이

int arr[128][128];
void calc(int x, int y, int n){
    
    int first = arr[y][x];
    int isSame = 0;

    for(int i = y; i< y+n; i++) {
        for(int j = x; j < x + n; j++){

            if(first != arr[i][j]){
                isSame = -1;
                break;
            }
            if(isSame == -1) break;
        }
    }

    if(isSame == 0){
        if(first == 1) bCnt++;
        else wCnt++;
    } else {
        int nX = x + n / 2;
        int nY = y + n / 2;
        // n1
        calc(x, y, n / 2);
        // n2
        calc(nX, y, n / 2);
        // n3
        calc(x, nY, n / 2);
        // n4
        calc(nX, nY, n / 2);
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;

    for(int i = 0; i< n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }


    calc(0, 0, n);

    cout << wCnt << "\n" << bCnt;

    return 0;
}
