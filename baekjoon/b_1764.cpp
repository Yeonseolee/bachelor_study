#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false );
    cin.tie(NULL);

    set<string> hear, ans;

    int n, m, i;
    cin >> n >> m;
    string tmp;
    for(i = 0; i<n; i++){
        cin >> tmp;
        hear.insert(tmp);
    }

    cout << "\nhear : " << '\n';
    for(string x : hear) cout << x << " ";

    cout << "\n =========== \n";
    // set<string>::iterator iter;
    for(i = 0; i<m; i++){
        cin >> tmp;
        if(hear.find(tmp) != hear.end()) ans.insert(tmp);
    }

    cout << '\n';
    cout << ans.size() << '\n';
    for(string x : ans){
        cout << x << '\n';
    }

}