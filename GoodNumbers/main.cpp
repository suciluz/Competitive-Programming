#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int digSum (int x) {
    int sum = 0;
    while(x!=0) {
        sum=sum+x%10;
        x=x/10;
    }
    return sum;
}
bool isPrime(int x) {
    bool val = 1;
    if(x==1) return 0;
    for(int i=2; i<=sqrt(x); i++) {
        if(x%i==0) val = 0;
    }
    return val;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n; int cnt = 0;
    for(int i=0; i<n; i++) {
        int in; cin>>in; int k = digSum(in);
        if(isPrime(in) && isPrime(k)) cnt++;
    }
    cout<<cnt<<fin;
}

