#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k, cnt=0;;
    cin>>n>>k;
    int coins[n];
    for(int i=0; i<n; i++) cin>>coins[i];
    for(int i=n-1; i>-1; i--) {
        int quotient = k/coins[i];
        cnt += quotient;
        k-=quotient*coins[i];
    }
    if(k==0) cout<<cnt<<'\n';
    else cout<<-1<<'\n';
}
