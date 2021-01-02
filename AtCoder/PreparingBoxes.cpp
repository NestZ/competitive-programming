#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int cnt = 0;
	vector<int> p(n + 1);
	vector<int> ans(n + 1);
	for(int i = 1;i <= n;i++)cin >> p[i];
	for(int i = n;i >= 1;i--){
		int sum = 0;
		int cur_index = 2 * i;
		while(cur_index <= n){
			sum += ans[cur_index];
			cur_index += i;
		}
		if(sum % 2 != p[i]){
			ans[i] = 1;
			cnt++;
		}
	}
	cout << cnt << endl;
	if(cnt > 0){
		for(int i = 1;i <= n;i++){
			if(ans[i] != 0)cout << i << ' ';
			if(i == n)cout << endl;
		}
	}
}
