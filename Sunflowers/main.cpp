#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define end '\n'
int n;
int main()
{
    ios_base::sync_with_stdio(0); cin>>n;
    int arr[n][n], arr2[n][n], arr3[n][n], arr4[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    bool valid=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(arr[i][j]>=arr[i][j+1]) valid = 0;
            if(arr[j][i]>=arr[j+1][i]) valid=0;
        }
    }
    if(valid) {
        for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<end;
        }
    }

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[j][n-1-i] = arr[i][j];
		}
	}
	valid=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(arr2[i][j]>=arr2[i][j+1]) valid = 0;
            if(arr2[j][i]>=arr2[j+1][i]) valid=0;
        }
    }
    if(valid) {
        for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr2[i][j]<<" ";
        }
        cout<<end;
        }
    }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr3[n-1-i][n-1-j] = arr[i][j];
		}
	}
	valid=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(arr3[i][j]>=arr3[i][j+1]) valid = 0;
            if(arr3[j][i]>=arr3[j+1][i]) valid=0;
        }
    }
    if(valid) {
        for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr3[i][j]<<" ";
        }
        cout<<end;
        }
    }


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr4[n-1-j][i] = arr[i][j];
		}
	}
	valid=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(arr4[i][j]>=arr4[i][j+1]) valid = 0;
            if(arr4[j][i]>=arr4[j+1][i]) valid=0;
        }
    }
    if(valid) {
        for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr4[i][j]<<" ";
        }
        cout<<end;
        }
    }

}
