#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	for(int j = 0;j < t;j++){
		int n;cin >> n;
		vector<int> arr(n);
		vector<int> arrNew(n);
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			arrNew[i] = arr[i];
		}
		sort(arrNew.begin(), arrNew.end());
		int mn = *min_element(arr.begin(), arr.end());
		bool flag = true;
		for(int i = 0;i < n;i++){
			if(arr[i] == arrNew[i])continue;
			if(arr[i] != arrNew[i] && (arr[i] % mn != 0 || arrNew[i] % mn != 0))flag = false;
		}
		if(flag)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
