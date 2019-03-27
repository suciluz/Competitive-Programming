#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
string s1="",s2=""; int n;
bool check (string a) {
    return a == s2;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>s1>>s2;
    string ss1 = s1;
    bool pos = 0;
    if(s1==s2){cout<<"YES"<<fin; return =0;}
    for(int k=0; k<n-1; k++) {
        if(s1[k]==s1[k+1]) {
                if(s1[k] == 'F') s1[k] = s1[k+1] = 'A';
                else s1[k] = s1[k+1] = 'F';
        }
        if(check(s1)) pos = 1;
        s1 = ss1;
        for(int i=k; i<n-1; i++) {
            if(s1[i]==s1[i+1]) {
                if(s1[i] == 'F') s1[i] = s1[i+1] = 'A';
                else s1[i] = s1[i+1] = 'F';
            }
            if(check(s1)) pos = 1;
        }
        if(check(s1)) pos = 1;
        s1 = ss1;
    }
    if(pos) cout<<"YES"<<fin;
    else cout<<"NO"<<fin;
}


