#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int r,c,k, cus=0;
    cin>>r>>c>>k;
    int seats[r][c]; int p[k];
    for(int i=0; i<k; i++) cin>>p[i];
    int n = sizeof(p)/sizeof(p[0]);
    sort(p,p+n);
    int mx = ceil(k/r); cout<<mx<<'\n';
    int my= k/mx; if(my==0) my=1;
    int ind = k-1;
    /*for(int i=0; ind>=0; i++) {
        for(int j=0; j<mx; j++) {
            seats[i][j]=p[ind]; ind--;
            if(i>0) {cus+=(seats[i-1][j]-seats[i][j]+1);
            seats[i][j]++;
            }
        }
    }
    cout<<cus<<'\n';*/
    return 0;
}

/*
ios_base::sync_with_stdio(0);
    int r,c,k, cus=0;
    cin>>r>>c>>k;
    int seats[r][c]; int p[k];
    for(int i=0; i<k; i++) cin>>p[i];
    int n = sizeof(p)/sizeof(p[0]);
    sort(p,p+n);
    int mx = k/r;if(mx==0)mx=1;
    int my= k/mx;if(my==0)my=1;
    int ind = k-1;
    for(int i=0; i<my; i++) {
        for(int j=0; j<mx; j++) {
            seats[i][j]=p[ind]; ind--;
            if(i>0) cus+=(seats[i-1][j]-seats[i][j]+1);
            seats[i][j]++;
        }
    }
    cout<<cus<<'\n';
    return 0;
*/
