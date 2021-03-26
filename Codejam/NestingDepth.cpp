#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;scanf("%d", &t);
	for(int j = 0;j < t;j++){
		string s;cin >> s;
		int n = s.length();
		vector<char> arr;
		for(int i = 0;i < n;i++){
			int num = s[i] - '0';
			if(i == 0){
				for(int k = 0;k < num;k++)arr.push_back('(');
				arr.push_back(s[i]);
			}
			else{
				if(s[i] > s[i - 1]){
					for(int k = 0;k < s[i] - s[i - 1];k++){
						arr.push_back('(');
					}
					arr.push_back(s[i]);
				}
				else if(s[i] < s[i - 1]){
					for(int k = 0;k < s[i - 1] - s[i];k++){
						arr.push_back(')');
					}
					arr.push_back(s[i]);
				}
				else arr.push_back(s[i]);
			}
			if(i == n - 1){
				for(int k = 0;k < num;k++)arr.push_back(')');
			}
		}
		printf("Case #%d: ", j + 1);
		for(char c : arr)printf("%c", c);
		printf("\n");
	}
}
