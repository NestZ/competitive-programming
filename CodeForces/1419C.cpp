#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, x;cin >> n >> x;
		int diff = 0;
		int mx = INT_MIN;
		int mn = INT_MAX;
		bool one = false;
		vector<int> arr(n);
		for(int i = 0;i < n;i++){
			int temp;cin >> temp;
			diff += temp - x;
			if(temp == x)one = true;
			mx = max(mx, temp);
			mn = min(mn, temp);
		}
		if(mx == mn && mx == x)cout << 0;
		else if(one || diff == 0)cout << 1;
		else cout << 2;
		cout << endl;
	}
}
