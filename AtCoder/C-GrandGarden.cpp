#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> v(n);
	int maxx = INT_MIN;
	for(int i = 0;i < n;i++){
		cin >> v[i];
		if(v[i] > maxx)maxx = v[i];
	}
	int ans = 0;
	for(int i = maxx;i > 0;i--){
		bool last = false;
		for(int j = 0;j < n;j++){
			if(v[j] == i && last == false){
				ans++;
				v[j]--;
				last = true;
			}
			else if(v[j] == i && last)v[j]--;
			else if(v[j] != i)last = false;
		}
	}
	cout << ans;
}
