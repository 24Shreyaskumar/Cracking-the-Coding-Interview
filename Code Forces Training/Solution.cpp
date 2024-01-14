#include <bits/stdc++.h>
using namespace std;

int Solve(string s) {
    int n = s.size();
    string common = "";
    int i = 0;

    for (;i < n; i++) {
        if (s[i] == ':') {
            common += " ";
            continue;
        } 
        else if (s[i] == '/' && s[i+1] == '/') {
            //i++;
            common += " ";
        }
        else {
            
        }
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin>>a>>b;

    cout<<Solve(a, b)<<"\n";

    return 0;
}