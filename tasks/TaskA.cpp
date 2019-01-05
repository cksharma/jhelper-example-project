#include <bits/stdc++.h>
using namespace std;

class TaskA {
public:
    void solve(std::istream& in, std::ostream& out) {
        string s; in >> s;
        for(int i = 0; i < 5; ++i) {
            string str; in >> str;
            for(int j = 0; j < 2; ++j) if(s[j] == str[j]) {
                out << "YES"<< endl;
                return;
            }
        }
        out << "NO" << endl;
    }
};
