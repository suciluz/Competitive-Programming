#include <bits/stdc ++.h>
using namespace std;
#define fin '\n'
int arr[401]; bool d[401][401];
/*
interval DP: always time complexity >= O(n^2)
dp[l][r] from l to r what's the answer
dp[l][r] if can be combined from l to r
if possible => sum = al + ... + ar (use psum arr)
if(d[1][p] && d[q][r] && p+1 = q||d[p+1][q-1] && sum(l,p) == sum(q,r))
*/

int sum (int l, int r) {

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;
    for(int i=1,tmp; i<=n; i++) {cin>>tmp; arr[i] = arr[i-1] + tmp; d[i][i] = 1; }
    for(int i=1; i<n; i++) {
        for(int p = 1, q = p+i; q<= n; p++,j++) {

        }
    }
}

int N, values[401], ans = 0;
bool dp[401][401];

int main() {
    scan(N);

    for (int i = 1; i <= N; i++) {
        scan(values[i]);
        dp[i][i] = true;
        ans = max(ans, values[i]);
        values[i] += values[i - 1];
    }

    for (int offset = 1; offset < N; offset++) {
        for (int i = 1, j = i + offset; j <= N; i++, j++) {
            int l = i, r = j;
            while (l < r && !dp[i][j]) {
                int left = values[l] - values[i - 1], right = values[j] - values[r - 1];
                if (left == right) {
                    if (dp[i][l] && (l + 1 == r ? true : dp[l + 1][r - 1]) && dp[r][j]) {
                        dp[i][j] = true;
                        ans = max(ans, values[j] - values[i - 1]);
                    }
                    l++, r--;
                } else if (left < right) {
                    l++;
                } else if (left > right) {
                    r--;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
