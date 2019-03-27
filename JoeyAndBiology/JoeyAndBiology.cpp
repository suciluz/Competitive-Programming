#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int d[1001][1001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m; cin>>n>>m; string s1,s2; cin>>s1>>s2;
    for(int i=0; i<=s1.length(); i++) {
        for(int j=0; j<=s2.length(); j++) {
            if(i==0&&j) {
               int u1 = i,u2 = j-1;
                for(int k=1; k<4; k++) if(j-k>=0 && d[u1][u2] > d[i][j-k]) { u1 = i; u2=  j-k; }
                d[i][j] = d[u1][u2]+1;
            }
            else if(j==0&&i) {
                int u1 = i-1,u2 = j;
                for(int k=2; k<4; k++) if(i-k>=0 && d[u1][u2] > d[i-k][j]) { u1 = i-k; u2 = j; }
                d[i][j] = d[u1][u2]+1;
            } else if(!j&&!i) d[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) d[i][j] = d[i-1][j-1];
            else if(s1[i-1] != s2[j-1]) { int u1 = i-1,u2 = j;
                for(int k=2; k<4; k++) if(i-k>=0 && d[u1][u2] > d[i-k][j]) { u1 = i-k; u2 = j; }
                for(int k=1; k<4; k++) if(j-k>=0 && d[u1][u2] > d[i][j-k]) { u1 = i; u2=  j-k; }
                if(d[i-1][j-1] < d[u1][u2] ) { u1=i-1; u2=j-1;}
                d[i][j] = d[u1][u2]+1;
            }
        }
    }
    cout<<d[s1.length()][s2.length()]<<fin;
}
