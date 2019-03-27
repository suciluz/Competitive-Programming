#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
double g[1000][1000];
double cg [1000][1000];
int n,m;
double check (double x) {
    double sum2 = 0;
    memset(cg,0,sizeof(cg));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cg[i][j] = g[i][j]*x;
            sum2 += cg[i][j];
        }
    }
    return sum2/(n*m);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    double sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>g[i][j];
            sum+=g[i][j];
        }
    }
    double avg = sum / (n*m);

    if(avg == 0.48) cout<<"correctly exposed"<<fin;
    else if (avg < 0.48) {
        cout<<"underexposed"<<fin;
        double hi = 480, lo = 0, ans =0 ;
        while (lo <= hi) {
            double mid = (hi+lo) / 2;
            if(check(mid) <0.49 && check(mid) > 0.47) {ans = mid; break;}
            else if(check(mid) > 0.48) hi = mid-1;
            else lo = mid+1;
            cout<<mid<<" ";
        }
        cout<<ans<<fin;
    }
    else {
        cout<<"overexposed"<<fin;
        double hi = 480, lo = 0, ans =0 ;
        while (lo <= hi) {
            double mid = (hi+lo) / 2;
            if(check(mid)) {ans = mid; hi = mid-1;}
            else lo = mid + 1;
        }
        cout<<ans<<fin;
    }
}


