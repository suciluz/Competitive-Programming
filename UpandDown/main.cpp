#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int a,b,c,d,s,bry=0,nik=0; cin>>a>>b>>c>>d>>s;
    int q1 = s/(a+b), r1 = s-q1*(a+b), ex1;
    if(r1<=a) ex1 = r1;
    else ex1 = a - (r1-a);
    bry = q1*a - q1*b + ex1;
    int q2 = s/(c+d), r2 = s-q2*(c+d), ex2;
    if(r2<=c) ex2 = r2;
    else ex2 = c - (r2-c);
    nik = q2*c - q2*d + ex2;
    if(bry > nik) cout<<"Nikky"<<fin;
    else if(bry==nik) cout<<"Tied"<<fin;
    else cout<<"Byron"<<fin;
}
