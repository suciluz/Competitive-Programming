#include <bits/stdc++.h>
using namespace std;
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int a,b,c,t,cnt=0; cin>>a>>b>>c>>t;
    for(int i=0; i<=t/a; i++) {
        for(int j=0; j<=t/b; j++) {
            for(int k=0; k<=t/c; k++) {
                if(i*a + j*b + k*c <= t && i+j+k > 0) {
                    cnt++;
                    cout<<i<<" Brown Trout, "<<j<<" Northern Pike, "<<k<<" Yellow Pickerel"<<fin;
                }
            }
        }
    }
    cout<<"Number of ways to catch fish: "<<cnt<<fin;
}


