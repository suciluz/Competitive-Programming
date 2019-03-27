#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int I,N,J;
int diff[100003];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>I>>N>>J; int cnt = 0;
    for(int i=0,xi,xf,k; i<J; i++) {
        cin>>xi>>xf>>k;
        diff[xi] += k; diff[xf+1] -= k;
    }
    for(int i=1; i<=I; i++) {
        diff[i] += diff[i-1];
        if (diff[i] < N) cnt++;
    }
    cout<<cnt<<fin;
}
