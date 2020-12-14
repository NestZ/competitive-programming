#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		bool z = false;
		int cnt_minus = 0;
		int mn_abs = INT_MAX;
		int sum = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int num;cin >> num;
				mn_abs = min(abs(num), mn_abs);
				if(num == 0)z = true;
				if(num < 0)cnt_minus++;
				sum += abs(num);
			}
		}
		if(z || cnt_minus % 2 == 0)cout << sum;
		else cout << sum - 2 * mn_abs;
		cout << endl;
	}
}
