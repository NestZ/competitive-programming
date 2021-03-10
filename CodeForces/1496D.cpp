#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> arr(n + 2);
	vector<int> pu(n + 2);
	vector<int> l(n + 2);
	vector<int> r(n + 2);
	for(int i = 1;i <= n;i++)cin >> arr[i];
	if(arr[2] < arr[1]){
		pu[1] = true;
		arr[0] = INT_MIN;
	}
	else arr[0] = INT_MAX;
	if(arr[n - 1] < arr[n]){
		pu[n] = true;
		arr[n + 1] = INT_MIN;
	}
	else arr[n + 1] = INT_MAX;
	for(int i = 2;i <= n - 1;i++){
		if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
			pu[i] = true;
	}
	int mx = 0;
	int mx_cnt = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(arr[i + 1] > arr[i])cnt++;
		else{
			if(pu[i])l[i] = cnt + 1;
			cnt = 0;
		}
		if(!pu[i])l[i] = cnt;
		mx = max(mx, l[i]);
	}
	cnt = 0;
	for(int i = n;i >= 1;i--){
		if(arr[i - 1] > arr[i])cnt++;
		else{
			if(pu[i])r[i] = cnt + 1;
			cnt = 0;
		}
		if(!pu[i])r[i] = cnt;
		mx = max(mx, r[i]);
	}
	for(int i = 1;i <= n;i++){
		if(l[i] == mx)mx_cnt++;
		if(r[i] == mx)mx_cnt++;
	}
	bool ans = true;
	if(mx_cnt > 2)ans = false;
	else if(mx_cnt == 2){
		ans = false;
		for(int i = 1;i <= n;i++){
			if(l[i] == mx && l[i] == r[i]){
				if(mx % 2 == 1)ans = true;
			}
		}
	}
	else if(mx_cnt == 1){
		ans = false;
	}
	if(ans)cout << 1;
	else cout << 0;
	cout << endl;
}
