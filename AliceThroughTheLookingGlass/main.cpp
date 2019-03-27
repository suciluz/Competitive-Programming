#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        bool crystal=false;
        int lvl,x,y;
        cin>>lvl>>x>>y;
        bool fin=false;
        for(int i=lvl; i>0 &&!fin; i--) {
                int sz = (int)pow(5,i-1);
                int nx = x/sz, ny = y/sz;
                if (nx > 0 && nx < 4 && ny ==0) {crystal=true;fin=true;}
                if (nx==2 && ny == 1) {crystal=true;fin=true;}
                if(((nx==1||nx==3)&&ny==1) || (nx == 2 && ny == 2)) { x%=sz;y%=sz;}
        }
        if(crystal) cout<<"crystal"<<'\n';
        else cout<<"empty"<<'\n';
    }
    return 0;
}
