#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<int> arr(300005, 0);
int n;

bool peak(int i){
	if(i == 0 || i == n - 1)return false;
	if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])return true;
	if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1])return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		cin >> n;
		vector<int> p(n);
		int cnt = 0;
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 1;i < n - 1;i++){
			if(peak(i)){
				cnt++;
				p[i] = 1;
			}
		}
		int ans = cnt;
		for(int i = 1;i < n - 1;i++){
			int arr_t = arr[i];
			int cur = cnt;
			cur -= (p[i - 1] + p[i] + p[i + 1]);
			arr[i] = max(arr[i - 1], arr[i + 1]);	
			if(peak(i - 1))cur++;
			if(peak(i))cur++;
			if(peak(i + 1))cur++;
			ans = min(ans, cur);

			cur = cnt;
			cur -= (p[i - 1] + p[i] + p[i + 1]);
			arr[i] = min(arr[i - 1], arr[i + 1]);
			if(peak(i - 1))cur++;
			if(peak(i))cur++;
			if(peak(i + 1))cur++;
			ans = min(ans, cur);
			arr[i] = arr_t;
		}
		cout << ans << endl;
	}
}
