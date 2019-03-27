#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
typedef pair<short int,short int> pi;
vector<pi> adj[2010][2010];
char g[2010][2010]; int ind[2010][2010];
int n,m;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>g[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j]=='.') ind[i][j]=0;
            else if(g[i][j] =='N') {
                for(int k=i; k>=0; k--) {
                    if(g[k][j] != '.') {
                        ind[k][j]++; adj[i][j].push_back({k,j});
                    }
                    if(k<i && g[k][j]=='N') break;
                }
            }
            else if(g[i][j] =='S') {
                for(int k=i; k<n; k++) {
                    if(g[k][j] != '.') {
                        ind[k][j]++; adj[i][j].push_back({k,j});
                    }
                    if(k>i && g[k][j]=='S') break;
                }
            }
            else if(g[i][j] =='E') {
                for(int k=j; k<m; k++) {
                    if(g[i][k] !='.') {
                        ind[i][k]++; adj[i][j].push_back({i,k});
                    }
                    if(k>j && g[i][k]=='E') break;
                }
            }
            else {
                for(int k=j; k>=0; k--) {
                    if(g[i][k] !='.') {
                        ind[i][k]++; adj[i][j].push_back({i,k});
                    }
                    if(k<j && g[i][k]=='W') break;
                }
            }
        }
    }
    queue <pi> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(ind[i][j]==1) q.push({i,j});
        }
    }
    stack <pi> st;
    while(!q.empty()) {
        pi u = q.front(); q.pop();
        st.push(u);
        for(auto v : adj[u.first][u.second]) {
            if(--ind[v.first][v.second] == 1) q.push({v.first,v.second});
        }
    }
    while(!st.empty()) {
        cout<<"("<<st.top().first<<","<<st.top().second<<")"<<fin;
        st.pop();
    }
}
