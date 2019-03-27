#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'

string valid (string s) {
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') { cnt+=1;}
        else { cnt-=1; }
        if(cnt<0) return "NO";
    }
    if(cnt==0) return "YES";
    else return "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) {
        string s; cin>>s;
        cout<<valid(s)<<end;
    }
}

//Paranthesis question
