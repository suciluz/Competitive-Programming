#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int ways[7],n;
    for(int i=0; i<7; i++) ways[i]=1;
    cin>>n;
    for(int i=1; i<=n-1; i++) {
        int x; cin>>x;
        ways[x]=ways[x]*(ways[i]+1);
    }
    cout<<ways[n]<<'\n';
    return 0;
}
