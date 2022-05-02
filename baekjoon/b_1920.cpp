#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



// 탐색 : 이진 탐색으로 구현하면 정렬까지 필요..
// 탐색 공부 필요

int BSearch(vector<int> &arr, int key){

    int start = 0, end = arr.size() -1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;

        if(arr[mid] == key) return 1;
        else if(arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }

    return 0;
}

int main(void) {

    int n, m, i;
    vector<int> arr, s;
    cin >> n;
    for(i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    for(i = 0; i<m; i++){
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    for(int x : s){
        cout << BSearch(arr, x) << "\n";
    }


    return 0;
}

