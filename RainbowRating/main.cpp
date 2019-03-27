#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
ll d[2][5];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s1,s2 = "love";cin>>s1;
    //if(s1.size()<=3) {cout<<0<<fin; return 0;}
    //if(s1.size()==4 && s1!=s2) {cout<<0<<fin; return 0;}
    for(int i=0; i<=s1.size(); i++) d[0][i] = 0;
    for(int i=0; i<=1; i++) d[i][0] = 1;
    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=4; j++) {
            if(s1[i-1]==s2[j-1]) d[i%2][j] = d[(i-1)%2][j] + d[(i-1)%2][j-1];
            else d[i%2][j] = d[(i-1)%2][j];
        }
    }
    cout<<d[s1.size()%2][4];
}

