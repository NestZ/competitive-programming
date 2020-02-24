#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++)cin >> v[i];
	int ans = INT_MAX;
	for(int i = 1;i <= 100;i++){
		int sum = 0;
		for(int j = 0;j < n;j++){
			sum += pow(i - v[j], 2);
		}
		ans = min(ans, sum);
	}
	cout << ans;
}
