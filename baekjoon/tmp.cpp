#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<string>& arr, int left, int mid, int right){

    int L = left, R = mid+1;
    vector<string> sorted;

    while (L <= mid && R <= right)
    {
        if(arr[L].length() == arr[R].length()){
            if(arr[L].compare(arr[R]) == 0){
                sorted.push_back(arr[L++]);
                R++;
            } else if(arr[L].compare(arr[R]) < 0) {
                sorted.push_back(arr[L++]);
            } else {
                sorted.push_back(arr[R++]);
            }
        }
        else {
            if (arr[L].length() < arr[R].length()) {
                sorted.push_back(arr[L++]);
            } else {
                sorted.push_back(arr[R++]);
            }
        }
    }

    if( L > mid){
        for(int i = R; i<= right; i++)
            sorted.push_back(arr[i]);
    } else {
        for(int i = L; i<= mid; i++)
            sorted.push_back(arr[i]);
    }

    for(int i = left; i<= right; i++)
        arr[i] = sorted[i];

}

void m_sort(vector<string>& arr, int left, int right) {

    if(left < right){
        int mid = (left + right) /2;

        m_sort(arr, left, mid);
        m_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> arr;
    string tmp;
    for(int i = 0; i<n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    m_sort(arr, 0, n-1);

    cout << "\n\n";
    
    for(int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}