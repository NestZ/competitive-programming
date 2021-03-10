#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> arr(n);
		set<int> s;
		int mx = 0;
		int mex = -1;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			s.insert(arr[i]);
			mx = max(mx, arr[i]);
		}
		sort(arr.begin(), arr.end());
		for(int i = 0;i < n;i++){
			if(arr[i] != i){
				mex = i;
				break;
			}
		}
		if(k == 0)cout << n;
		else{
			if(mex != -1){
				if(s.count((mex + mx + 1) / 2) == 0)cout << n + 1;
				else cout << n;
			}
			else cout << n + k;
		}
		cout << endl;
	}
}
