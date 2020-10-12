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
		vector<int> lock(n);
		vector<int> fr;
		vector<int> lo;
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i < n;i++)cin >> lock[i];
		for(int i = 0;i < n;i++){
			if(lock[i] == 1)lo.push_back(arr[i]);
			else fr.push_back(arr[i]);
		}
		sort(fr.rbegin(), fr.rend());
		int fri = 0;
		int loi = 0;
		for(int i = 0;i < n;i++){
			if(lock[i] == 1)cout << lo[loi++];
			else cout << fr[fri++];
			cout << ' ';
		}
		cout << endl;
	}
}
