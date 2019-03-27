#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int n,G,ans=0;
unordered_map <string,int> mp;
int g[10][10];
void gflip (int i, int j) {
    for(int x = i; x<i+2; x++) {
        for(int y = j; y<j+2; y++) {
            g[x][y] = !g[x][y];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>G;
    for(int t=0; t<G; t++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                char tmp; cin>>tmp;
                if(tmp=='R') g[i][j] = 1;
                else g[i][j] = 0;
            }
        }
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-1; j++) {
                if(g[i][j]) gflip(i,j);
            }
        }

        string tmp = "";
        for(int i = 0; i<n; i++) {
            tmp = tmp + to_string(g[n-1][i]);
        }
        for(int i = n-2; i>=0; i--) {
            tmp = tmp + to_string(g[i][n-1]);
        }
        mp[tmp]++;
    }
    for(auto &i: mp) {
        int N = i.second;
        ans += N*(N-1) / 2;
    }
    cout<<ans<<fin;
}
/*
    Make n-1 x n-1 square all 0 and compare the out row/column using bitmask / hashmap
*/
