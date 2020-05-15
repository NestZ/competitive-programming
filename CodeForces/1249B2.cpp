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
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			arr[i]--;
		}
		vector<int> used(n);
		vector<int> ans(n);
		for(int i = 0;i < n;i++){
			if(!used[i]){
				vector<int> curr;
				while(!used[i]){
					curr.push_back(i);
					used[i] = true;
					i = arr[i];
				}
				for(int j : curr)ans[j] = curr.size();
			}
		}
		for(int i = 0;i < n;i++)cout << ans[i] << ' ';
		cout << endl;
	}
}
