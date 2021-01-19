#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> arr(n);
	deque<int> dq;
	vector<int> res;
	bool fst = true;
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n / 2;i++){
		if(fst){
			dq.push_front(arr[i]);
			dq.push_back(arr[n - i - 1]);
		}
		else{
			dq.push_front(arr[n - i - 1]);
			dq.push_back(arr[i]);
		}
		fst = !fst;
	}
	if(n & 1){
		int abs_f = abs(dq.front() - arr[n / 2]);
		int abs_b = abs(dq.back() - arr[n / 2]);
		if(abs_f > abs_b)dq.push_front(arr[n / 2]);
		else dq.push_back(arr[n / 2]);
	}
	for(int i = 0;i < n;i++){
		res.push_back(dq.front());
		dq.pop_front();
	}
	ll ans = 0;
	for(int i = 0;i < n - 1;i++)
		ans += abs(res[i] - res[i + 1]);
	cout << ans << endl;
}
