#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<pair<int, int>> arr(n);
		bool flag = true;
		for(int i = 0;i < n;i++){
			int a, b;cin >> a >> b;
			arr[i] = make_pair(a, b);
		}
		for(int i = 0;i < n;i++){
			if(arr[i].second > arr[i].first)flag = false;
			if(i > 0){
				if(arr[i].first < arr[i - 1].first || arr[i].second < arr[i - 1].second)flag = false;
				if(arr[i].second - arr[i - 1].second > arr[i].first - arr[i - 1].first)flag = false;
			}
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
