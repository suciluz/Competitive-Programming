#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
string s1="", s2="";
void binary1 (unsigned n) {
    if(n>1) binary1(n/2);
    s1 += to_string(n%2);
}
void binary2 (unsigned n) {
    if(n>1) binary2(n/2);
    s2 += to_string(n%2);
}
bool check (int n) {
    bool val= 0,val2 = 0;
    if(s1.length() >= n+1) {
        if(s1.at(s1.length()-1-n) == '1') val = 1;
    }
    if(s2.length() >=  n+1) {
        if(s2.at(s2.length()-1-n) == '1') val2 = 1;
    }
    return (val && val2) || (!val && !val2);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m,k; cin>>n>>m>>k; int b=0, p=0;
    binary1(n); binary2(m);
    for(int i=0; i<k; i++) {
        if(check(i)) p++;
        else b++;
    }
    cout<<b<<" "<<p<<fin;
    //cout<<s1<< " "<<s2;
}


