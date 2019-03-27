#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[1001][1001];
int D,I,r; string s1,s2;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>D>>I>>r>>s1>>s2;
    for(int i=0; i<=s1.length(); i++) {
        for(int j=0; j<=s2.length(); j++) {
            if(i==0) d[i][j] = j*I;
            else if(j==0) d[i][j] = i*D;
            else if(s1.at(i-1)==s2.at(j-1)) d[i][j] = d[i-1][j-1];
            else if(s1.at(i-1)!=s2.at(j-1)) d[i][j] = min(d[i-1][j]+D,min(d[i][j-1]+I,d[i-1][j-1]+r));
        }
    }
    cout<<d[s1.length()][s2.length()]<<fin;
}
