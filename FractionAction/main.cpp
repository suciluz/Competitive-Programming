#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);
    int n, d; cin>>n>>d;
    for(int i=2; i<=min(n,d); i++) {
        if(n%i==0 && d%i==0) { n/=i; d/=i; }
    }
    int q = n/d;
    int r = n-q*d;
    if(r==0 && n!=0) cout<<q<<fin;
    else if(n==0) cout<<0<<fin;
    else if(q!=0) cout<<q<<" "<<r<<"/"<<d<<fin;
    else cout<<r<<"/"<<d<<fin;
}

