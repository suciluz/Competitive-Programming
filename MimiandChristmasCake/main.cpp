#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int n,cnt=0;
bool isPrime(int k) {
    bool b = 1; if(k==1) return 0;
    for(int i=2; i<=sqrt(k); i++) if(k%i==0) b = 0;
    return b;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n; int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n; i++) if(isPrime(arr[i])) cnt++;
    cout<<cnt<<end;
}


