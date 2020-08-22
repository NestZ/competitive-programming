#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 2 * n - 1;j++){
			if(j <= n - 1 + i && j >= n - 1 - i)cout << '*';
			else if(j > n - 1 - i)break;
			else cout << ' ';
		}
		cout << endl;
	}
}
