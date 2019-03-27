#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int n,x,y,cnt=0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>x>>y;
    int lo = x, hi = y,mid=0;
    while(lo<=hi) {

        mid = (lo+hi)/2;

        cnt++;
        if(mid<n)  {
            lo = mid;
        }
        else if(mid>n) {
            hi = mid;
        }
        else if(mid==n) {
            break;
        }
    }
    cout<<cnt<<fin;
}
