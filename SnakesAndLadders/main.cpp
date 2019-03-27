#include <bits/stdc++.h>
using namespace std;
#define fin '\n'

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int cur = 1, x;
    while(1) {
        cin>>x;
        if(!x) { cout<<"You Quit!"<<fin; return 0; }
        if(cur+x==9) cur = 34;
        else if(cur+x==40) cur = 64;
        else if(cur+x==67) cur = 86;
        else if(cur+x==54) cur = 19;
        else if(cur+x==90) cur = 48;
        else if(cur+x==99) cur = 77;
        else if(cur+x <= 100) cur += x;
        cout<<"You are now on square "<<cur<<fin;
        if(cur==100) { cout<<"You Win!"<<fin; return 0; }
    }
}


