#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d, sum;cin >> d >> sum;
	vector<pair<int, int>> arr;
	vector<int> curr(d);
	for(int i = 0;i < d;i++){
		int a, b;cin >> a >> b;
		arr.push_back({a, b});
		curr[i] = a;
		sum -= a;
	}
	if(sum < 0)return cout << "NO", 0;
	for(int i = 0;i < d;i++){
		if(arr[i].second - arr[i].first <= sum){
			sum -= arr[i].second - arr[i].first;
			curr[i] = arr[i].second;
		}
		else{
			curr[i] += sum;
			sum = 0;
		}
	}
	if(sum != 0)return cout << "NO", 0;
	cout << "YES" << endl;
	for(int i : curr)cout << i << ' ';
}
