#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;cin >> n >> k;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i == j)cout << k << ' ';
			else cout << 0 << ' ';
		}
		cout << endl;
	}
}
