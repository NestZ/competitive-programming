#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	cout << (n * n + 1) / 2 << endl;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if((i + j) % 2 == 0)cout << 'C';
			else cout << '.';
		}
		cout << endl;
	}
}
