#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    double x,y; cin>>x>>y;
    long double tmp = x/2;
    long double ans = 1LL * tmp * y;
    cout<<fixed;
    cout<<setprecision(1);
    cout<<ans<<fin;
}


