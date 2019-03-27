#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
bool check (int x, int y) {
    for(int i=2; i<=min(x,y); i++) {
        if(!(x%i) && !(y%i)) return 0;
    } return 1;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int a,b,c,d;cin>>a>>b>>c>>d;
    ll ans = 0;
    for(int i=a; i<=b; i++) {
        for(int j=c; j<=d; j++) {
            if(check(i,j)) ans++;
        }
    }
    cout<<ans<<fin;
    cout<<check(2,2);
}
