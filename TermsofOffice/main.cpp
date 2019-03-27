#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int x,y; cin>>x>>y;
    for(x; x<=y; x+=60) {
        cout<<"All positions change in year "<<x<<fin;
    }
}
