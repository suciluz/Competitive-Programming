#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    int cnt = 0;
    if(n<=5) for(int i=0; i<=n/2; i++) cnt++;
    else if(n==6) cnt = 3;
    else if (n==7 || n==8) cnt = 2;
    else cnt = 1;
    cout<<cnt<<fin;
}

