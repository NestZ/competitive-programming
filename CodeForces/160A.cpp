#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	int sum = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());
	int csum = 0;
	int ans = 0;
	for(int i = n - 1;i >= 0;i--){
		csum += arr[i];
		ans++;
		if(csum > sum / 2)return cout << ans, 0;
	}
}
