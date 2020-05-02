#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, k;cin >> n >> k;
		vector<int> arr(n);
		set<int> s;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			s.insert(arr[i]);
		}
		if(s.size() > k)cout << -1;
		if(s.size() < k){
			for(int i = 1;i <= n;i++){
				if(s.count(i) == 0){
					s.insert(i);
					if(s.size() == k)break;
				}
			}
		}
		if(s.size() == k){
			cout << k * n << endl;
			for(int i = 0;i < n;i++){
				for(int j : s){
					cout << j << ' ';
				}
			}
		}
		cout << endl;
	}
}
