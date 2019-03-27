#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int R,X,Y,b=INT_MAX,bi,star1[3],star2[3],star3[3];
int dis (int x, int y) {
    return (X-x)*(X-x) + (Y-y)*(Y-y);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>R>>X>>Y;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==0) {cin>>star1[j]; if(j==2&&b>star1[i]) {b=star1[i]; bi = i;} }
            if(i==1) {cin>>star2[j]; if(j==2&&b>star2[i]) {b=star2[i]; bi = i;} }
            if(i==2) {cin>>star3[j]; if(j==2&&b>star3[i]) {b=star3[i]; bi = i;} }
        }
    }
    if(bi==0) {
        if(dis(star1[0],star1[1])>=R*R) cout<<"Time to move my telescope!"<<fin;
        else cout<<"What a beauty!"<<fin;
    }
    else if(bi==1) {
        if(dis(star2[0],star2[1])>=R*R) cout<<"Time to move my telescope!"<<fin;
        else cout<<"What a beauty!"<<fin;
    }
    else {
        if(dis(star3[0],star3[1])>=R*R) cout<<"Time to move my telescope!"<<fin;
        else cout<<"What a beauty!"<<fin;
    }
}
