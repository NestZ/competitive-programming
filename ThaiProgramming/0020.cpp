#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> arr(5, 0);
	for(int i = 0;i < 5;i++){
		for(int j = 0;j < 4;j++){
			int t;cin >> t;
			arr[i] += t;
		}
	}
	auto ind = max_element(arr.begin(), arr.end());
	cout << (ind - arr.begin() + 1) << ' ' << *ind;
}
