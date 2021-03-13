#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int pcnt = 0;
	int mcnt = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i] < 0)mcnt++;
		if(arr[i] > 0)pcnt++;
	}
	sort(arr.begin(), arr.end());
	if(mcnt == 0){
		int sum = 0;
		for(int i = 1;i < n;i++)
			sum += arr[i];
		cout << sum - arr[0] << endl;
		int res = arr[0];
		for(int i = 1;i < n - 1;i++){
			cout << res << ' ' << arr[i] << endl;
			res -= arr[i];
		}
		cout << arr[n - 1] << ' ' << res << endl;
	}
	else if(pcnt == 0){
		int sum = 0;
		for(int i = 0;i < n - 1;i++)
			sum += abs(arr[i]);
		cout << sum + arr[n - 1] << endl;
		int res = arr[n - 1];
		for(int i = 0;i < n - 1;i++){
			cout << res << ' ' << arr[i] << endl;
			res -= arr[i];
		}
	}
	else{
		int sum = 0;
		int fst = INT_MAX;
		for(int i = 0;i < n;i++){
			sum += abs(arr[i]);
			if(arr[i] >= 0)fst = min(fst, i);
		}
		cout << sum << endl;
		int res = arr[0];
		for(int i = fst;i < n - 1;i++){
			cout << res << ' ' << arr[i] << endl;
			res -= arr[i];
		}
		cout << arr[n - 1] << ' ' << res << endl;
		res = arr[n - 1] - res;
		for(int i = 1;i < fst;i++){
			cout << res << ' ' << arr[i] << endl;
			res -= arr[i];
		}
	}
}
