#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    map<string , int> dogamList;
    vector<string> pocketmon;
    int n, m; cin >> n >> m;

    for(int i = 0; i<n; i++)
    {   string name;
        cin >> name;
        dogamList.insert({name, i+1});
        pocketmon.push_back(name);
    }
    
    for(int i = 0; i<m; i++){
        char value[21];
        cin >> value;
        if(atoi(value)){
            cout << pocketmon[atoi(value)-1] << '\n';
        } else {
            cout << dogamList[(string)value] << '\n';
        }
    }


    return 0;
}
