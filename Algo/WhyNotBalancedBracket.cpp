#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int cur = 0;
	int ans = 0;
	vector<int> arr;
	string s;cin >> s;
	for(int i = 0;i < n;i++){
		if(s[i] == '(')cur++;
		else cur--;
		arr.push_back(cur);
	}
	if(cur != 0)cout << -1;
	else{
		int cnt = 0;
		bool minus = false;
		for(int i = 0;i < n;i++){
			if(arr[i] < 0){
				minus = true;
				cnt++;
			}
			else if(minus && arr[i] == 0){
				ans += cnt + 1;
				cnt = 0;
				minus = false;
			}
		}
		cout << ans;
	}
	cout << endl;
}
