#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    int c1 = 0, c2= 0;
    for(int i=0; i<n; i++) {
        double in;
        cin>>in;
        if(round(in) == (int) in) c1++;
        else c2++;
    }
    cout<<c2<<fin<<c1<<fin;
}
