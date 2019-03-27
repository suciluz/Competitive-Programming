#include <bits/stdc++.h>
using namespace std;
#define fin '\n'
int n,sx,sy,ex,ey,ans=0; double INF = (double) INT_MAX;
typedef pair<int,int> pi;
vector<pi> coor;

bool check (double px, double py, double cx, double cy) {
    if(sx==ex) {
        if(px==cx) {
            return px==sx && max(py,cy) >= sy && min(py,cy) <= ey;
        }
        else if(py==cy) {
            for(double x = min(px,cx); x<= max(px,cx); x+=1) {
                return x==sx && py <= ey && py >= sy;
            }
        }
        else {
            double c = (cy-py)/(cx-px), d = -px*c + py, yi = c*sx +d;
            return yi <= ey && yi >= sy;
        }
    }
    else {
        if(px==cx) {
            double tmp = (ey-sy)/(ex-sx)*(px-sx)+sy;
            return tmp <= max(py,cy) && tmp >= min(py,cy)
            && tmp <= ex && tmp >= sx;
         }
        else if(py==cy) {
            for(double x = min(px,cx); x<= max(px,cx); x+=1) {
                double tmp = (ey-sy)/(ex-sx)*(x-sx)+sy;
                if(tmp == py && tmp <= ey && tmp >= sy) return 1;
            } return 0;
        }
        else {
            double a = (ey-sy)/(ex-sx), b = -sx*a + sy;
            double c = (cy-py)/(cx-px), d = -px*c + py;
            if(a==c) {
                return b==d && max(cx,px) <= ex && min(cx,px) >= sx && max(cy,py) <= ey && min(cy,py) >= sy;
            }
            else {
                double xi = (d-b)/(a-c);
                double tmp1 = a*xi + b, tmp2 = c*xi +d;
                return tmp1 == tmp2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>sx>>sy>>ex>>ey>>n;
    for(int i=0; i<n; i++) {
        int c,tx,ty; cin>>c>>tx>>ty; coor.push_back({tx,ty}); bool trig = 0;
        for(int i=1,x,y; i<c; i++) {
            int px = coor.back().first, py = coor.back().second; cin>>x>>y;
            if(check(px,py,x,y)) {ans++; trig = 1; break;}
        }
        int px = coor.back().first, py = coor.back().second;
        if(check(px,py,tx,ty) && !trig) ans++;
    }
    cout<<ans<<fin;
}

