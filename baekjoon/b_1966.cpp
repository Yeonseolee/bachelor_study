#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

struct Doc
{
    int data;
    bool isSpot;
};


int main(void){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int c;
    cin >> c;

    for(int i = 0; i<c; i++){
        int n, m;
        queue<Doc> s;
        cin >> n >> m;

        int* importance = new int[n];

        for(int j = 0; j<n; j++){
            Doc doc;
            cin >> doc.data;

            if(j == m) doc.isSpot = true;
            else doc.isSpot = false;

            s.push(doc);
            importance[j] = doc.data;
        }

        sort(importance, importance+n);

        int ans = 0, index = n-1;
        bool isAns = false;

        while(true){

            if(importance[index] == s.front().data) {

                if(s.front().isSpot == true){
                    ans++;
                    break;
                } 

                ans++;
                index--;
                s.pop();

            } else {
                Doc tmp = s.front();
                s.pop();
                s.push(tmp);
            }

        }

        cout << ans << '\n';

        delete[] importance;
    }

    return 0;
}

