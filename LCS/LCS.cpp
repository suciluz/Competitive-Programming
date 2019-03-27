#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[3001][3001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s, t; cin>>s>>t;
    for(int i=0; i<=s.length(); i++) {
        for(int j=0; j<=t.length(); j++) {
            if(i==0 || j==0) d[i][j] = 0;
            else if (s[i-1] == t[j-1]) d[i][j] = d[i-1][j-1] +1;
            else d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    string ans = "";
    int i = s.length(), j = t.length();
    while(i>0 && j>0) {
        if(s[i-1]==t[j-1]) {
            ans+=s[i-1]; i--; j--;
        }
        else if(d[i-1][j] > d[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<fin;
}
