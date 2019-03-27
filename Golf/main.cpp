#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[5281], c[32],dis,cnum;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>dis>>cnum; memset(d,0x3f,sizeof(d));
    for(int i=0; i<cnum; i++) cin>>c[i]; d[0] = 0;
    for(int i=1; i<=dis; i++) {
        for(int j=0; j<cnum; j++) {
            if(c[j] <= i) {
                d[i] = min(d[i], d[i-c[j]]+1);
            }
        }
    }
    if(d[dis]!=0x3f3f3f3f) cout<<"Roberta wins in "<<d[dis]<<" strokes."<<fin;
    else cout<<"Roberta acknowledges defeat."<<fin;
}
