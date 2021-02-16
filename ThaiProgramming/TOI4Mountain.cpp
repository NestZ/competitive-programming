#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int mxw = 0;
	int mxh = 0;
	vector<int> s(n);
	vector<int> h(n);
	for(int i = 0;i < n;i++){
		cin >> s[i] >> h[i];
		s[i]--;
		mxh = max(mxh, h[i]);
		mxw = max(mxw, s[i] + h[i] * 2 - 1);
	}
	for(int i = 0;i < mxh;i++){
		for(int j = 0;j <= mxw;j++){
			bool under = false;
			bool l = false;
			bool r = false;
			int curh = mxh - i - 1;
			for(int k = 0;k < n;k++){
				int this_h = h[k];
				int this_s = s[k];
				if(curh < this_h &&
						j < this_s + curh + ((this_h - curh) * 2 - 1) &&
						j > this_s + curh)
					under = true;
				if(curh < this_h &&
						j == this_s + curh + ((this_h - curh) * 2 - 1))
					r = true;
				if(curh < this_h &&
						j == this_s + curh)
					l = true;

			}
			if(under)cout << 'X';
			else if(l && r)cout << 'v';
			else if(l)cout << '/';
			else if(r)cout << '\\';
			else cout << '.';
		}
		cout << endl;
	}
}
