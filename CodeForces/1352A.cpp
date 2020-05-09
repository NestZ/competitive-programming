#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> ans;
		int curr = 0;
		while(n > 0){
			if(n % 10 != 0){
				ans.push_back(n % 10 * pow(10, curr));
			}
			n /= 10;
			curr++;
		}
		cout << ans.size() << endl;
		for(int i : ans)cout << i << ' ';
		cout << endl;
	}
}
