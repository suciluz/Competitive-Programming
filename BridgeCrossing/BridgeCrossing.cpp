#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[500], dur[101], group[10000];
string name[101];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int m, q; cin>>m>>q; memset(d,0x3f,sizeof(d));
    for(int i=0; i<q; i++) cin>>name[i]>>dur[i]; d[0]=0;
    for(int i=0; i<q; i++) {
            int tmp = -1;
        for(int j=0; j<m && i+j<=q; j++) {
            tmp = max(tmp,dur[i+j]);
            if(d[i]+tmp<d[i+j+1]) {
                d[i+j+1] = tmp+d[i]; group[i+j+1]=i;
            }
        }
    }
    cout<<"Total Time: "<<d[q]<<fin; int idx= 0;
    for(int i=10000-1;;i--) {
        if(group[i]!=0) {idx=i+1; group[idx] = q; break;}
    }
    string ans = "";
    for(int i=q;;i=group[i]) {
        string tmp = "";
        for(int j=group[i];j<i;j++) tmp = tmp+" "+name[j];
        ans = tmp+ans;
        ans = "\n"+ans;
        if(i==0) break;
    }
    cout<<ans<<fin;
}
