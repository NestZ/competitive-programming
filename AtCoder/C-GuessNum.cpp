#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n,m;cin >> n >> m;
	vector<int> arr(n + 1, -1);
	while(m--){
		int s,c;cin >> s >> c;
		if(arr[s] == -1 || arr[s] == c)arr[s] = c;
		else return cout << -1, 0;
	}
	if(arr[1] == 0 && n > 1)return cout << -1, 0;
	for(int i = 1;i <= n;i++){
		if(i == 1 && arr[i] == -1 && n > 1)cout << 1;
		else if(arr[i] == -1)cout << 0;
		else cout << arr[i];
	}
}
