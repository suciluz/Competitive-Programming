#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int solve (int x) {
    int ans=0;
    for(int i=1; i<=x; i++) {
        int y = (int) sqrt(pow(x,2)-pow(i,2));
        ans += 4*y;
    }
    ans += 4*x;
    return ++ans;
}
int main() {
    ios_base::sync_with_stdio(0); int x;
    cin>>x;
    while(x!=0) {
        cout<<solve(x)<<fin;
        cin>>x;
    }
}
