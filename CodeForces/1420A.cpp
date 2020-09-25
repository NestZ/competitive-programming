#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		bool ans = false;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		for(int i = 0;i < n - 1;i++){
			if(arr[i] <= arr[i + 1])ans = true;
		}
		if(ans)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
