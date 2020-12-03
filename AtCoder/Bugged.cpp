#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	int sum = 0;
	int fst = INT_MAX;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
		if(arr[i] % 10 != 0)fst = min(fst, arr[i]);
	}
	if(sum % 10 != 0)cout << sum;
	else if(fst != INT_MAX)cout << sum - fst;
	else cout << 0;
	cout << endl;
}
