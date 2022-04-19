#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<int> joseph;

    for(int i = 1; i <=n; i++) joseph.push(i);

    cout << "<";
    while(!joseph.empty()){
        for(int i = 0; i < k-1; i++){
            joseph.push(joseph.front());
            joseph.pop();
        }
        if(joseph.size() == 1) cout << joseph.front();
        else cout << joseph.front() << ", ";
        
        joseph.pop();
    }
    cout << ">";





    return 0;
}