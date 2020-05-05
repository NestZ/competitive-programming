#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		vector<int> arr(n);
		vector<int> arrt(n);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			arrt[i] = arr[i];
		}
		set<int> s;
		for(int i = 0;i < m;i++){
			int k;cin >> k;
			k--;
			s.insert(k);
		}
		bool flag = true;
		sort(arrt.begin(), arrt.end());
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n - 1;j++){
				if(arr[j] > arr[j + 1] && s.count(j) != 0)swap(arr[j], arr[j + 1]);
			}
		}
		for(int i = 0;i < n;i++){
			if(arr[i] != arrt[i])flag = false;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
