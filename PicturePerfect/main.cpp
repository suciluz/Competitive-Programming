#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int solve (int n) {
    int mxf = -1;
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i==0) mxf = max(mxf,i);
    }
    return mxf;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    for(;;) {
        int n; cin>>n; if(!n)break;
        int a = solve(n), b = n/a;
        cout<<"Minimum perimeter is "<<2*a+2*b<<" with dimensions "<<a<<" x "<<b<<fin;
    }
}




