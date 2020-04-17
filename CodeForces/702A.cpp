#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int curr = 0;
	int ans = 0;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n - 1;i++){
		if(arr[i] < arr[i + 1])curr++;
		else{
			ans = max(ans, curr);
			curr = 0;
		}
		ans = max(ans, curr);
	}
	cout << ans + 1;
}
