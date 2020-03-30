#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	vector<int> arr(t);
	for(int i = 0;i < t;i++){
		cin >> arr[i];
	}
	int ans = 1;
	int cnt = 0;
	for(int i = 1;i < t;i++){
		if(arr[i] >= arr[i - 1])ans++;
		else ans = 1;
		cnt = max(ans,cnt);
	}
	cout << max(ans,cnt);
}
