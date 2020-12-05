#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, y;cin >> n >> y;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n - i;j++){
			int k = n - i - j;
			if(i * 10000 + j * 5000 + k * 1000 == y){
				return cout << i << ' ' << j << ' ' << k << endl, 0;
			}
		}
	}
	cout << "-1 -1 -1\n";
}
