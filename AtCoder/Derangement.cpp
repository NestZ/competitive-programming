#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int ans = 0;
	int cnt = 0;
	vector<int> arr(n);
	vector<int> p;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		if(arr[i] == i)cnt++;
		else{
			if(cnt > 0)p.push_back(cnt);
			cnt = 0;
		}
	}
	if(cnt > 0)p.push_back(cnt);
	for(int i : p){
		if(i > 1)ans += (i + 1) / 2;
		else ans++;
	}
	cout << ans << endl;
}
