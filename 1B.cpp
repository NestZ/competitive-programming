#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n;i++){
		bool rc = false;
		string s;cin >> s;
		int l = s.length();
		for(int j = 1;j < l;j++){
			if(s[j] >= 'A' && s[j] <= 'Z' && s[j - 1] >= '0' && s[j - 1] <= '9')
				rc = true;
		}
		if(rc){
			string row = "";
			string col = "";
			int j = 1;
			for(;j < l;j++){
				if(s[j] == 'C')break;
				row += s[j];
			}
			for(j++;j < l;j++)col += s[j];
			string pre = "";
			int coln = stoi(col);
			while(coln > 0){
				char c = 'A' + ((coln - 1) % 26);
				pre += c;
				coln--;
				coln /= 26;
			}
			reverse(pre.begin(), pre.end());
			string ans = pre + row;
			cout << ans << endl;
		}
		else{
			string kuy = "";
			string row = "";
			int j = 0;
			for(;j < l;j++){
				if(s[j] >= 'A' && s[j] <= 'Z')kuy += s[j];
				else break;
			}
			for(;j < l;j++)row += s[j];
			cout << 'R' << row << 'C';
			int col = 0;
			int len = kuy.length();
			for(int k = 0;k < len - 1;k++){
				col += pow(26, len - k - 1) * (kuy[k] - 'A' + 1);
			}
			col += kuy[len - 1] - 'A' + 1;
			cout << col << endl;
		}
	}
}
