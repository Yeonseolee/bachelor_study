#include <iostream>
#include <vector>

// 아니 시발 이것도 탐색이고 지랄이야
// 완전탐색으로 구현 -> 시간 초과

using namespace std;

int main(void) {

    int n, m;
    vector<int> sangun, card;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sangun.push_back(tmp);
    }
    
    cin >> m;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }

    for(int x : card){
        int cnt = 0;
        for(int y : sangun){
            if(x == y) cnt++;
        }
        cout << cnt << " ";
    }

    return 0;
}