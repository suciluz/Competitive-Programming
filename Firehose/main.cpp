#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
const int cir = 1000000;
int H=0,k,ans=0,h[1000];
bool check (int x) {
    int val = INT_MAX;
    for(int i=0; i<H; i++) {
        int cnt=0, max_gap=0,p1,p2;
        for(int j=0; j<H; j++) {
            p2 = (i+j)%H;
            if(p2==0) p1 = H-1;
            else p1 = p2-1;
            max_gap += (h[p2]-h[p1]+cir)%cir;
            if(max_gap>x*2) {cnt++; max_gap=0;}
        }
        val = min(val,cnt);
    }
    return val<=k;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>H;
    for(int i=0; i<H; i++) cin>>h[i];
    sort(h,h+H);
    cin>>k;
    int lo = 0, hi = cir, mid = 0;
    while(lo<=hi) {
        mid = (lo+hi)/2;
        if(check(mid)) { ans = mid; hi = mid-1;}
        else lo = mid+1;
    }
    cout<<ans<<fin;
}
