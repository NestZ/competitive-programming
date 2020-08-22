#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 5;
	int e = 0;
	for(int i = 0;i < n;i++, e++){
		for(int j = 0;j < 2 * n - 1;j++){
			if(j == n - 1 - i)e = 0;
			if(j <= n - 1 + i && j >= n - 1 - i && ((e % 2) == 0))cout << '$';
			else if(j > n - 1 + i)break;
			else cout << ' ';
			e++;
		}
		cout << endl;
	}
}
