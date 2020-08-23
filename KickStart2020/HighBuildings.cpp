#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	for(int q = 0;q < t;q++){
		int n;cin >> n;
		int a, b, c;cin >> a >> b >> c;
		bool r = a < b;
		bool flag = true;
		int temp = min(a, b);
		b = max(a, b);
		a = temp;
		vector<int> ans(n, 0);
		int curr = max(0, a - c);
		for(int i = 0;i < curr;i++)ans[i] = n - 1;
		if(c > 1){
			for(int i = 0;i < c - 1;i++)ans[i + curr] = n;
			ans[n - 1 - (b - c)] = n;
		}
		else{
			for(int i = 0;i < c;i++)ans[i + curr] = n;
		}
		for(int i = 0;i < b - c;i++)ans[n - i - 1] = n - 1;
		for(int i = 0;i < n;i++){
			if(ans[i] == 0)ans[i] = 1;
		}
		int currmx = ans[0];
		int cnt = 0;
		for(int i = 0;i < n;i++){
			if(ans[i] >= currmx){
				cnt++;
				currmx = ans[i];
			}
		}
		if(cnt != a)flag = false;
		currmx = ans[n - 1];
		cnt = 0;
		for(int i = n - 1;i >= 0;i--){
			if(ans[i] >= currmx){
				cnt++;
				currmx = ans[i];
			}
		}
		if(cnt != b)flag = false;
		cnt = 0;
		for(int i = 0;i < n;i++){
			if(ans[i] == n)cnt++;
		}
		if(cnt != c)flag = false;
		cout << "Case #" << q + 1 << ": ";
		if(flag){
			if(!r)reverse(ans.begin(), ans.end());
			for(int i = 0;i < n;i++)cout << ans[i] << ' ';
		}
		else cout << "IMPOSSIBLE";
		cout << endl;
	}
}
