#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> arr(n);
		for(int i = 0;i < n;i++)cin >> arr[i];
		bool flag = true;
		for(int i = 0;i < n - 1;i++){
			for(int j = i + 1;j < n;j++){
				if(abs(arr[i] - arr[j]) % 2 != 0)flag = false;
			}
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
