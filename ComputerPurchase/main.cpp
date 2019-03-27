#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int main() {
    ios_base::sync_with_stdio(0);
    int n,mx,mn; string a1,a2,com; cin>>n;
    if(n>0) {
        int a,b,c,s; cin>>a1>>a>>b>>c; a2="";
        s = 2*a+3*b+c;
        mx = s; mn =-1;
        for(int i=1; i<n; i++) {
            cin>>com>>a>>b>>c;
            s = 2*a+3*b+c;
            if(s>mx || (s==mx &&com.compare(a1)<0)) {mn = mx; mx = s; a2 = a1; a1 = com;}
            else if(s>mn || (s==mn &&com.compare(a2)<0)) {mn = s; a2 = com;}
        }
    }
    if(n==1) cout<<a1<<end;
    else cout<<a1<<end<<a2<<end;
}
