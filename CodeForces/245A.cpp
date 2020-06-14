#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<pair<int, int>> arr(2);
	for(int i = 0;i < 2;i++){
		arr[i].first = 0;
		arr[i].second = 0;
	}
	for(int i = 0;i < n;i++){
		int t, x, y;cin >> t >> x >> y;
		t--;
		arr[t].first += x;
		arr[t].second += y;
	}
	for(int i = 0;i < 2;i++){
		if(arr[i].first >= (arr[i].first + arr[i].second + 1) / 2)cout << "LIVE";
		else cout << "DEAD";
		cout << endl;
	}
}
