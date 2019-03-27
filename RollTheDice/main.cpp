#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m,cnt=0; cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i+j==10) cnt++;
        }
    }
    if(cnt==1) cout<<"There is 1 way to get the sum 10."<<fin;
    else cout<<"There are "<<cnt<<" ways to get the sum 10."<<fin;
}
