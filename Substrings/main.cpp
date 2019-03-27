#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n; string s;
string suffix[5010];
int LCP (string s1, string s2) {
    int cnt = 0;
    for(int i=0; i<min(s1.length(), s2.length()); i++) {
        if(s1.at(i) != s2.at(i)) return cnt;
        cnt++;
    } return cnt;
}
int solve (string s) {
    int len = s.length();
    for(int i=0; i<len; i++) {
        suffix[i] = s.substr(i,len-i);
    }
    sort(suffix,suffix+len);
    int cnt = suffix[0].length();
    for(int i=1; i<len; i++) {
        cnt += (suffix[i].length() - LCP(suffix[i],suffix[i-1]));
    }
    return ++cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>s;
        cout<<solve(s)<<fin;
    }
}
