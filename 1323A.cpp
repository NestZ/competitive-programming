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
		int e = 0;
		int o = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] & 1)o++;
			else e++;
		}
		vector<int> ans;
		if(e > 0){
			for(int i = 0;i < n;i++){
				if(!(arr[i] & 1)){
					ans.push_back(i + 1);
					break;
				}
			}
		}
		else if(o >= 2){
			int cnt = 0;
			for(int i = 0;i < n;i++){
				if(arr[i] & 1){
					ans.push_back(i + 1);
					cnt++;
					if(cnt == 2)break;
				}
			}
		}
		if(ans.size() == 0)cout << -1;
		else{
			cout << ans.size() << endl;
			for(int i : ans)cout << i << ' ';
		}
		cout << endl;
	}
}
