#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
bool check (int x) {
    int cnt = 0;
    for(int i=1; i<=x; i++) {
        if(!(x%i)) cnt++;
    }
    if(cnt==4) return 1;
    else return 0;
}
int solve (int a, int b) {
    int cnt =0 ;
    for(int i=a; i<=b; i++) {
        if(check(i)) cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int a,b; cin>>a>>b;
    cout<<"The number of RSA numbers between "<<a<<" and "<<b<<" is "<<solve(a,b)<<fin;
}


