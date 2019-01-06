#include <bits/stdc++.h>
using namespace std;

class AGennadyAndACardGame {
public:
    void solve(istream& cin, ostream& cout) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        cout.setf(ios::fixed); cout.precision(20);
        string s; cin >> s;
        for(int i = 0; i < 5; ++i) {
            string str; cin >> str;
            for(int j = 0; j < 2; ++j) if(s[j] == str[j]) {
                cout << "YES"<< endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
};
