#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

// 다른 사람이 한건데 코드 좋음
// https://www.acmicpc.net/source/42447615

// void merge(string * arr, int left, int mid, int right){
//     int L = left, k = 0;
//     int R = mid + 1;


//     string * sorted = new string[right - left + 1];

//     while(L <= mid && R <= right){
//         if(arr[L].length() == arr[R].length()){
//             if(arr[L].compare(arr[R]) == 0) {
//                 sorted[k++] = arr[L++];
//                 R++; 
//             } else 
//                 sorted[k++] = arr[L].compare(arr[R]) < 0 ? arr[L++] : arr[R++];
//         }
//         else
//             sorted[k++] = arr[L].length() < arr[R].length() ? arr[L++] : arr[R++];
//     }

//     if(L > mid){
//         for(int i = R; i<=right; i++)
//             sorted[k++] = arr[i];
//     } else {
//         for(int i = L; i <= mid; i++)
//             sorted[k++] = arr[i];
//     }
    
//     for (int i = left, k = 0; i <= right; i++, k++)
//         arr[i] = sorted[k];

//     delete[] sorted;
    
// }

// void m_sort(string* arr, int left, int right){

//     if(left < right) {
//         int mid = (left + right) /2;
//         m_sort(arr, left, mid);
//         m_sort(arr, mid+1, right);
//         merge(arr, left, mid, right);
//     }
// }

struct comp
{
    bool operator()(const string &a, const string &b) const
    {
        if (a.size() < b.size()) { 
            return true;
        }
        else if (a.size() > b.size()) {
            return false;
        }
        else {
            return a.compare(b) < 0;
        }
    }
};


int main(void)
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    set<string, comp> arr;

    for(int i = 0; i<n; i++){
        string tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
    
    cout << '\n';
    
    for(string x : arr){
        cout << x << '\n';
    }

    return 0;
}