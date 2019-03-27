#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
bool isPrime (int x) {
    bool val = 1;
    for(int i=2; i<=sqrt(x); i++) {
        if(x%i==0) val = 0;
    }
    return val;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,cost = 0,a,b; cin>>n;
    while(n>1) {
        if(isPrime(n)) {n-=1; cost+=n;}
        else {
            int tmp = -1;
            for(int i=2; i<n; i++) {
                if(n%i==0) {tmp = max(tmp,i);}
            }
            n-=tmp; cost+=n/tmp;
        }
        cout<<n<<" ";
    }
    cout<<cost<<fin;
}
