#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,x,ans; scanf("%d",&n);scanf("%d",&x); ans = x;
    for(int i=1; i<n; i++) {
        scanf("%d",&x);
        ans ^= x;
    }
    printf("%d\n",ans);
    return 0;
}

