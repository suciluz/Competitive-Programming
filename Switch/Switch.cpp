#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
#define INF 0x3f3f3f3f
int n, ans = 0;
vector<int> row;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0, tmp; i<n; i++) { cin>>tmp; row.push_back(tmp); }
    bool done = 0;
    while(!done) {
        int pl=0, pr=0, cntl=0, cntr=0; bool t1=0, t2=0;
        for(int i=0; i<n; i++) {
            if(i==n-1) { cntl = INF; break;}
            if(row[i]) {
                cntl++;
                if(!row[i+1]) {
                    pl = i+1; break;
                }
            }
        }
        for(int i=n-1; i>=0; i--) {
           if(!i) { cntr = INF; break;}
            if(row[i]) {
                cntr++;
                if(!row[i-1]) {
                    pr = i-1; break;
                }
            }
        }
        if(!cntl) cntl = INF;
        if(!cntr) cntr = INF;
        if(cntl <= cntr) row[pl] = 1;
        else row[pr] = 1;
        done = 1;
        //for(int i=0; i<n; i++) cout<<row[i]<<" "; cout<<fin;
        for(int i=0; i<n; i++) {
            int idx=i;
            for(; row[idx] && idx<=n-1 ;idx++)
            if(idx-i >= 3)
                for(int j=i; j<=idx; j++) row[j] = 0;
            //cout<<"   "<<i<<fin;
        }
        for(int i=0; i<n; i++)
            if(row[i]) done = 0;
        ans++;
    }
    cout<<ans<<fin;
}


