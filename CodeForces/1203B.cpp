#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(4 * n);
		set<int> s;
		bool flag = true;
		for(int i = 0;i < 4 * n;i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		for(int i = 0;i < n * 2;i+=2){
			if(arr[i] != arr[i + 1] || arr[4 * n - i - 1] != arr[4 * n - i - 2])flag = false;
			s.insert(arr[i] * arr[4 * n - i - 1]);
		}
		if(!flag || s.size() > 1)cout << "NO";
		else cout << "YES";
		cout << endl;
	}
}
