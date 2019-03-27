#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
const int inf = 0x3f3f3f3f;
int g[3][3];
int check (int r) {
    int cnt = 0;
    for(int i=0; i<3; i++) {
        if(g[r][i]==inf) cnt++;
    }

    return cnt;
}
int check2 (int c) {
    int cnt = 0;
    for(int i=0; i<3; i++) {
        if(g[i][c] == inf) cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            string tmp; cin>>tmp;
            if(tmp=="X") g[i][j] = inf;
            else {
                g[i][j] = stoi(tmp);
            }
            //cout<<g[i][j]<<" ";
        }//cout<<fin;
    }

    for(int i=0; i<3; i++) {

        if(check(i)==1) {
            if(g[i][1] == inf) g[i][1] = ( g[i][0] + g[i][2] ) / 2;
            else if(g[i][0] == inf) g[i][0] = g[i][1] - (g[i][2] - g[i][1]);
            else g[i][2] = ( g[i][1] - g[i][0] ) + g[i][1];
        }
        else if(check(i)==2) {
            if(g[i][0] != inf) { g[i][1] = g[i][0] + 2; g[i][2] = g[i][1] +2; }
            else if(g[i][1] != inf) {g[i][0] = g[i][1] -2; g[i][2] = g[i][1] + 2;}
            else {g[i][1] = g[i][2] - 2; g[i][0] = g[i][1] -2;}
        }
    }
    for(int i=0; i<3; i++) {
        if(check2(i)==1) {
            if(g[1][i] == inf) g[1][i] = ( g[0][i] + g[2][i]) / 2;
            else if(g[0][i] == inf) g[0][i] = g[1][i] - (g[2][i] - g[1][i]);
            else g[2][i] = ( g[1][i] - g[0][i] ) + g[1][i];
        }
        else if(check2(i)==2) {
            if(g[0][i] != inf) {g[1][i] = g[0][i] + 2; g[2][i] = g[1][i] +2; }
            else if(g[1][i] != inf) {g[0][i] = g[1][i] -2; g[2][i] = g[1][i] + 2;}
            else {g[1][i] = g[2][i] - 2; g[0][i] = g[1][i] -2;}
        }
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<g[i][j]<<" ";
        }cout<<fin;
    }
}


