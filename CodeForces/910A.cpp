#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;cin >> n >> d;
	string s;cin >> s;
	vector<int> arr;
	for(int i = 0;i < n;i++){
		if(s[i] == '1')arr.push_back(i);
	}
	if(s[0] == '0' || s[n - 1] == '0')return cout << -1, 0;
	int len = arr.size();
	int ans = 0;
	int curr = 0;
	int lim = d;
	for(int i = 0;i < len - 1;i++){
		if(arr[i + 1] <= lim)curr = i + 1;
		else{
			if(arr[i] + d < arr[i + 1])return cout << -1, 0;
			curr = i + 1;
			ans++;
			lim = arr[i] + d;
			i--;
		}
	}
	cout << ans + 1;
}
