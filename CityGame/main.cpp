#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[1000][1000],k,m,n,ans;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);cin>>k;
    for(int t=0; t<k; t++) {
        cin>>n>>m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                char tmp; cin>>tmp;
                if(tmp=='F') d[i][j] = 1;
                else d[i][j] = 0;
            }
        }
        for(int i=0,tmp=0; i<n; i++) {
            for(int j=tmp; j<m; j++) {
                if(d[i][j]) {

                }
            }
        }
    }

}
