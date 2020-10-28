/*
ID: nestz
LANG: C++14
TASK: barn1
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("barn1.out", "w", stdout);
	freopen("barn1.in", "r", stdin);
	
	int m, s, c;cin >> m >> s >> c;
	vector<int> arr(c);
	vector<int> diff;
	for(int i = 0;i < c;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 1;i < c;i++)diff.push_back(arr[i] - arr[i - 1]);
	sort(diff.rbegin(), diff.rend());
	vector<int> blocked;
	for(int i = 0;i < min(m - 1, int(diff.size()));i++)blocked.push_back(diff[i]);
	int ans = 0;
	int cnt = 0;
	for(int i = 1;i < c;i++){
		int cur_dif = arr[i] - arr[i - 1];
		bool ig = false;
		for(int &dif : blocked){
			if(cur_dif == dif){
				dif = -1;
				ig = true;
				ans += cnt + 1;
				cnt = 0;
				break;
			}
		}
		if(!ig)cnt += arr[i] - arr[i - 1];
	}
	ans += cnt + 1;
	cout << ans << endl;
}
