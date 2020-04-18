#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		int sum = 0;
		int cnt = 0;
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i] == 0)cnt++;
			sum += arr[i];
		}
		sum += cnt;
		cout << cnt + (sum == 0 ? 1 : 0) << endl;
	}
}
