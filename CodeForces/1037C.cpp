#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	string a;cin >> a;
	string b;cin >> b;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(i == n && a[i] != b[i])ans++;
		else{
			if(a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] != b[i]){
				swap(a[i], a[i + 1]);
				ans++;
			}
			else if(a[i] != b[i])ans++;
		}
	}
	cout << ans;
}
