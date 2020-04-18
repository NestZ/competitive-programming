#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		map<int, pair<int,int>> m;
		vector<int> arr(n);
		bool flag = false;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(m[arr[i]].first == 0)m[arr[i]] = make_pair(1, i);
			else m[arr[i]] = make_pair(m[arr[i]].first + 1, m[arr[i]].second);
			if(m[arr[i]].first > 1 && i - m[arr[i]].second > 1){
				flag = true;
			}
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
