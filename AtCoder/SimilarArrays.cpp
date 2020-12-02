#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;
int ans = 0;
vector<int> arr(10);

void dfs(int pos, int pro){
	if(pos == n){
		if(pro % 2 == 0)
			ans++;
		return;
	}
	dfs(pos + 1, pro * (arr[pos] - 1));
	dfs(pos + 1, pro * arr[pos]);
	dfs(pos + 1, pro * (arr[pos] + 1));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 0;i < n;i++)cin >> arr[i];
	dfs(0, 1);
	cout << ans << endl;
}
