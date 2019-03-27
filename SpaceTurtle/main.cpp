#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
ll sx,sy,sz,tx,ty,tz,ans;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>sx>>sy>>sz>>tx>>ty>>tz;
    //ll tmp = 0x3f3f3f3f3f3f3f3f;
    int d; char dir;
    tx-=sx; ty-=sy; tz-=sz;
    ans = tx*tx + ty*ty + tz*tz;
    do {
        cin>>d>>dir;
        ll prev = tx;
        tx-=d;
        if(prev*tx<0) ans = min(ans, ty*ty+tz*tz);
        else ans = min(ans, tx*tx + ty*ty + tz*tz);
        if(dir=='L') {
            swap(tx,ty); ty = -ty;
        }
        else if(dir=='R') {
            swap(tx,ty); tx = -tx;
        }
        else if(dir=='U') {
            swap(tx,tz); tz = -tz;
        }
        else {
            swap(tx,tz); tx = -tx;
        }
    } while(dir!='E');
    cout<<fixed<<setprecision(2)<<sqrt(ans)<<fin;
}


