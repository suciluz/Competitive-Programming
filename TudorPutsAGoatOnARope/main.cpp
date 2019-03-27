#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int x,y,xx1,yy1,xx2,yy2;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>x>>y>>xx1>>yy1>>xx2>>yy2;
    double ans;
    if(x < xx1 && y <= yy2 && y>= yy1 ) {
        ans = xx1 - x;
    }
    else if(x >= xx1 && x <= xx2 && y < yy1) {
        ans = yy1 - y;
    }
    else if(x > xx2 && y <= yy2 && y >= yy1) {
        ans = x - xx2;
    }
    else if(x >= xx1 && x <= xx2 && y > yy2) {
        ans = y - yy2;
    }
    else {
        if(x <= xx1 && y >= yy2) {
            ans = sqrt(pow(x-xx1, 2) + pow(y-yy2, 2));
        }
        else if(x <= xx1 && y <= yy1) {
            ans = sqrt(pow(x-xx1, 2) + pow(y-yy1, 2));
        }
        else if(x >= xx2 && y <= yy1) {
            ans = sqrt(pow(x-xx2, 2) + pow(y-yy1, 2));
        }
        else {
            ans = sqrt(pow(x-xx2, 2) + pow(y-yy2, 2));
        }
    }
    cout<<fixed;
    cout<<setprecision(3);
    cout<<ans<<fin;
}


