#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    ll n,ans; cin>>n;
    if(n%2==0) {ll temp=n/2;ans=temp*temp*2;}
    else {ll temp=n/2;ans=temp*(temp+1)*2;}
    cout<<ans<<'\n';
}
