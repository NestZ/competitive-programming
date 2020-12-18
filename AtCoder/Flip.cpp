#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;cin >> n >> m >> k;
	vector<bool> ans(1000001, false);
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			int flip = i * m + j * n - i * j - i * j;
			ans[flip] = true;
		}
	}
	if(ans[k])cout << "Yes";
	else cout << "No";
	cout << endl;
}
