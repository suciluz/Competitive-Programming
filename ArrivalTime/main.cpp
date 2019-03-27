#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
string in;
int main()
{
    ios_base::sync_with_stdio(0); int h,m;
    cin>>in;
    h = stoi(in.substr(0,2)); m = stoi(in.substr(3,2));
    double tmin = h*60+m;
    double dis = 240, elapse = 0;
    while(dis>0) {
        tmin++;
        if( (tmin>=420&&tmin<600) || (tmin>=900&&tmin<1140)) {
            //dis -= dis/240;
            dis--;
        }
        else {
            dis-=2;
        }
    }

    h = (int) tmin/60; m = (int) tmin%60; m = m/10*10;
    int ah = h%24;

    if(ah<10) {
        if(m<10) cout<<0<<ah<<":"<<0<<m<<end;
        else cout<<0<<ah<<":"<<m<<end;
    }else{
         if(m<10) cout<<ah<<":"<<0<<m<<end;
        else cout<<ah<<":"<<m<<end;
    }

}




