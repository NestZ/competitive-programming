#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		map<int, int> m;
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i < n;i++)m[arr[i]]++;
		int mxs = -1;
		int mxn = -1;
		bool s = true;
		for(int i = 0;i <= 100;i++){
			if(m[i] == 1)s = false;
			if(m[i] >= 1){
				if(s)mxs = max(mxs, i);
				mxn = max(mxn, i);
			}
			if(m[i] == 0)break;
		}
		cout << mxs + 1 + mxn + 1 << endl;
	}
}
