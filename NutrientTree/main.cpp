#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL); int sum = 0;
    for(int i=3; i<=1e5; i++) {
        double x = pow(2,i) +1, y = pow(x,0.5); int z = (int)pow(x,0.5);
       // cout<<y<<" "<<z<<" "<<(y==z)<<fin;
        if(y==z) cout<<i<<" "<<z<<fin; sum+=z;
    }
    cout<<sum;
}


