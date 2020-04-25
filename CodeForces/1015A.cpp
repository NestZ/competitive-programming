#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	vector<int> arr(m + 1, 0);
	for(int i = 0;i < n;i++){
		int a, b;cin >> a >> b;
		for(int j = a;j <= b;j++){
			arr[j]++;
		}
	}
	vector<int> ans;
	for(int i = 1;i <= m;i++){
		if(arr[i] == 0)ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i : ans)cout << i << ' ';
}
