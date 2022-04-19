#include <iostream>
#include <stack>
#include <vector>
#include <iterator>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    stack<int> s;
    vector<char> p;

    cin >> n;

    int before = 0, after = 0, last = 0; // before = 선 입력값, after = 후 입력값
    bool isSequence = true;

    for (int i = 1; i <= n; i++)
    {
        before = after;
        cin >> after;

        if (before > after)
        {
            if (!s.empty() && s.top() == after)
            {
                p.push_back('-');
                // cout << after << " -\n";
                s.pop();
            }
            else
            {
                isSequence = false;
            }
        }
        else
        {
            for (int j = last + 1; j <= after; j++)
            {
                s.push(j);
                p.push_back('+');
                // cout << j << " +\n";
                if (j == after)
                {
                    last = s.top();
                    s.pop();
                    p.push_back('-');
                    // cout << last << " == " << j << " -\n";
                }
            }
        }
    }

    // for(int i = 0; i<p.size(); i++){
    //     copy(p.begin(), p.end(), ostream_iterator<char>(cout,"\n"));
    // }

    if (isSequence)
    {
        for (char i : p)
        {
            cout << i << '\n';
        }
    } 
    else cout << "NO";

    return 0;
}
