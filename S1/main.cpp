#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int g[2][2];

void hflip () {
    swap(g[0][0], g[1][0]);
    swap(g[0][1], g[1][1]);
}

void vflip () {
    swap(g[0][0], g[0][1]);
    swap(g[1][0], g[1][1]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    g[0][0] = 1; g[0][1] =2; g[1][0] = 3; g[1][1] = 4;
    string s; cin>>s;

    for(int i=0; i<s.length(); i++) {
        char ins = s.at(i);
        if(ins=='H') {
            hflip();
        }
        else {
            vflip();
        }
    }
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cout<<g[i][j]<< " ";
        }cout<<fin;
    }

}


