#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int w = 0;
	int b = 0;
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			char c;cin >> c;
			if(tolower(c) == 'q'){
				if(islower(c))b += 9;
				else w += 9;
			}
			else if(tolower(c) == 'r'){
				if(islower(c))b += 5;
				else w += 5;
			}
			else if(tolower(c) == 'b' || tolower(c) == 'n'){
				if(islower(c))b += 3;
				else w += 3;
			}
			else if(tolower(c) == 'p'){
				if(islower(c))b += 1;
				else w += 1;
			}
		}
	}
	if(w == b)cout << "Draw";
	else if(w < b)cout << "Black";
	else cout << "White";
}
