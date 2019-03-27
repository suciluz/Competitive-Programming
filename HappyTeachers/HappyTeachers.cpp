#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n,s;
struct {int x, y, z; } p[51];
int d[2][1001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>p[i].x>>p[i].y>>p[i].z;
    } cin>>s;
    for(int i=1; i<=n; i++) {
        for(int k=p[i].x,dur=1; k>=0; k-=p[i].y, dur++) {
            for(int j=s; j>=0; j--) {
                if(p[i].z<=j) {
                    if(d[0][j-p[i].z]+k > d[0][j]) {
                            d[1][j]=d[1][j-p[i].z]+1;
                            d[0][j] = d[0][j-p[i].z]+k;
                    }
                    else if(d[0][j-p[i].z]+k == d[0][j]) {  d[1][j] = min(d[1][j-p[i].z]+dur,d[1][j]); }
                    d[0][j] = max(d[0][j], d[0][j-p[i].z]+k);
                }
            }
        }

    }
    cout<<d[0][s]<<fin<<d[1][s]<<fin;
}
