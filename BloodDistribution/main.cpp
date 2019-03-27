#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int u[8], p[8], ans = 0;
void distribute (int ux, int px) {
    int take = min(u[ux],p[px]);
    u[ux]-=take; p[px]-=take;
    ans += take;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<8; i++) cin>>u[i];
    for(int i=0; i<8; i++) cin>>p[i];
    for(int i=0; i<8; i++) {
        if(i==1) {
            distribute(1,1);
        }
        else if(i==2) {
            distribute(2,2);
        }
        else if(i==3) {
            distribute(3,3); distribute(2,3); distribute(1,3);
        }
        else if(i==4) {
            distribute(2,4); distribute(4,4);
        }
        else if(i==5) {
            distribute(5,5); distribute(4,5); distribute(1,5);
        }
        else if(i==6) {
            for(int j=6; j>0; j-=2) distribute(j,i);
        } else if(i==7) {
            for(int j=7; j>=1; j--) distribute(j,i);
        }
        distribute(0,i);
    }
    cout<<ans<<fin;
}
