#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fin '\n'
int t,g, ans=0;
typedef pair<int, int> pi;
map <pi, bool> mp;
bool check (vector<int> p) {
    for(int i=1; i<=4; i++) {
        if(i!=t && p[t] <= p[i]) return 0;
    } return 1;
}
void solve (vector<int> p) {

    bool done = 1;
    for(auto i: mp) {
        if(!i.second) {
            done = 0;
            int a = i.first.first, b = i.first.second;
            mp[{a,b}] = 1;
            //for(int k=1; k<=4; k++) cout<<p[k]<<" ";

            p[a]+=3; solve(p); p[a]-=3;
            p[a]++; p[b]++; solve(p); p[a]--; p[b]--;
            p[b]+=3; solve(p); p[b]-=3;

            mp[{a,b}] = 0;
            goto fi;
        }

    }
    fi:;
    if(done)
        if(check(p)) ans++;


}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>t>>g;
    vector <int> points(5);
    mp[{1,2}] = 0; mp[{1,3}] = 0; mp[{1,4}] = 0; mp[{2,3}] = 0; mp[{2,4}] = 0; mp[{3,4}] = 0;
    for(int i=0,a,b,s1,s2; i<g; i++) {
        cin>>a>>b>>s1>>s2;
        mp[{min(a,b), max(a,b)}] = 1;
        if(s1>s2) points[a]+=3;
        else if(s1==s2) {points[a]++; points[b]++;}
        else points[b]+=3;

    }

    solve(points);
    cout<<ans<<fin;
}
