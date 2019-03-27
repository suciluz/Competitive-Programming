#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int d[6][3001], T, N, B;
struct {int c,v,t;} pc[1001];
unordered_set <int> tp;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>T>>N;
    for(int i=1; i<=N; i++) {
        cin>>pc[i].c>>pc[i].v>>pc[i].t; tp.insert(pc[i].t);
    }
    cin>>B;
    for(int i=1; i<=T; i++) {
        for(int j=B; j>=0; j--) {
            for(int k=1; k<=tp.size(); k++) {
                if(pc[i].c<=j) {
                    if(d[k][j] < d[k][j-pc[i].c]+pc[i].v) {
                        d[j] = d[j-pc[i].c]+pc[i].v; taken[pc[i].t] = 1;
                    }
                }
            }
        }
    }
    bool pos = 1;
    for(int i=1; i<=T; i++)
        if(!taken[i]) pos = 0;
    if(!pos) cout<<-1<<fin;
    else cout<<d[B]<<fin;
}
