#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 배열의 최대 사이즈 보통 int 기준 100,000 이 최대인 듯. 저번에 막힌 부분
// 참고 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=amy_hmy&logNo=221028600832


// 근처 인덱스가 같은 값을 가지는지 확인하는 함수

int hasCard(const vector<int>& arr, int& x, int& index){
    int ans = 1;
    int before = index - 1, after = index + 1;
    while(arr[after] == x ){
        ans++;
        after++;
    }

    while(arr[before] == x){
        ans++;
        before--;
    }

    return ans;
}

// 이분 탐색 구현
int BSearchRecur(const vector<int>& arr, int x, int start, int end) {

    if(start > end) return 0;

    int mid = (start + end) / 2;
    if(arr[mid] == x) {
        return hasCard(arr, x, mid);
    }
    else if(arr[mid] < x) BSearchRecur(arr, x, mid + 1, end );
    else BSearchRecur(arr, x, start, mid -1);

}


int BSearch(const vector<int>& arr, int x, int n){
    int start = 0, end = n-1;
    int mid;

    while(start <= end)
    {
        mid = (start + end) / 2;

        if(arr[mid] == x) {
            return hasCard(arr, x, mid);
        }
        else if(arr[mid] < x) start = mid + 1;
        else end = mid -1;

    }
    return 0;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    vector<int> arr, sangen;
    cin >> n;

    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    sort(arr.begin(), arr.end());

    cin >> m;

    for(int i = 0; i<m; i++){
        int target;
        cin >> target;
        sangen.push_back(target);
    }

    for(int x : sangen){
        cout << BSearch(arr, x, n) << ' ';
    }

    // for(int x : sangen){
    //     int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    //     int u = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    //     if(l != u) cout << u - l << ' ';
    //     else cout << "0 ";
    // }

    return 0;
}

