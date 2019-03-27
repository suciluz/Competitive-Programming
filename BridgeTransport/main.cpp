#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int w,n,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin>>w>>n; int psum[n]; bool pass = 1;
    for(int i=0; i<n; i++) {
        cin>>psum[i];
        if(i>0) psum[i] = psum[i-1]+psum[i];
    }
    for(int i=0; i<=n-1; i++ ) {
        if(i<3) {
            if(psum[i]>w) {ans = i; pass=  0; break;}
        }
        else {
            int weight = psum[i];
            if(i>3) weight -= psum[i-4];
            if(weight>w) { ans = i; pass=0; break;}
        }
    }
    if(pass) cout<<n<<end;
    else cout<<ans<<end;
}
