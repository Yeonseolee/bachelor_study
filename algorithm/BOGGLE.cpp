#include <iostream>
#include <string>

using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

string board[5];

bool inRange(int y, int x){
    if(0 <= y && y <= 4 && 0 <= x && x <= 4) return true;
    else return false;
}

bool hasWord(int y, int x, const string& word){
    // 기저사례 1: 시작 위치가 범위 밖이면 실패
    if(!inRange(y, x)) {
        cout << "fail 01 \n";
        return false;
    }
    // 기저사례 2: 첫 글자가 일치하지 않으면 실패
    if(board[y][x] != word[0]) {
        cout << "fail 02 : " << board[y][x] << " \n";
        return false;
    }
    // 기저사례 3: 글자 개수가 1이면 성공
    if(word.size() == 1) {
        cout << board[y][x] << " \n";
        return true;
    }

    for(int i = 0; i < 8; ++i){
        int nextY = y + dy[i], nextX = x + dx[i];

        if(hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    cout << "fail 03 | ";
    return false;
}

int main(void) {

    int c;
    int n;
    cin >> c;
    string test;

    for(int i = 0; i < 5; i++){
        cin >> board[i];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    cin >> n;



    for(int i = 0; i< n; i++){
        cin >> test;

        bool ans = false;

        for(int y = 0; y < 5; y++){
            for(int x = 0; x < 5; x++){
                if(hasWord(y, x, test)) {
                    ans = true;
                    goto EXIT;
                }
            }
        }
        
        EXIT:
            if(ans) cout << "YES\n";
            else cout << "NO\n";
    }

    

    return 0;
}