#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void f(int i, int j, bool &flag){
	cout << i << " " << j << endl;
	flag = true;
}

int main(){
	int n, m;cin >> n >> m;
	char c[n + 5][m + 5];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char t;cin >> t;
			c[i][j] = tolower(t);
		}
	}
	
	int k;cin >> k;
	for(int i = 0;i < k;i++){
		string s;cin >> s;
		int sl = s.length();
		for(char &temp : s)temp = tolower(temp);
		bool flag = false;
		for(int j = 0;j < n;j++){
			if(flag)break;
			for(int u = 0;u < m;u++){
				if(n - j >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j + l][u];
					if(t == s){
						f(j, u, flag);
						break;
					}
				}
				if(n - j >= sl && m - u >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j + l][u + l];
					if(t == s){
						f(j, u, flag);
						break;
					}
				}
				if(n - j >= sl && u + 1 >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j + l][u - l];
					if(t == s){
						f(j, u, flag);
						break;
					}
				}
				if(j + 1 >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j - l][u];
					if(t == s){
						f(j , u, flag);
						break;
					}
				}
				if(j + 1 >= sl && m - u >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j - l][u + l];
					if(t == s){
						f(j, u, flag);
						break;
					}
				}
				if(j + 1 >= sl && u + 1 >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j - l][u - l];
					if(t == s){
						f(j, u, flag);
						break;
					}
				}
				if(m - u >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j][u + l];
					if(t == s){
						f(j, u, flag);
						break;
					}
				}
				if(u + 1 >= sl){
					string t = "";
					for(int l = 0;l < sl;l++)t += c[j][u - l];
					if(t == s){
						f(j, u, flag);
						break;
					}
				}
			}
		}
	}
}
