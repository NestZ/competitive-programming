#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	double currX = 0;
	double currY = 0;
	while(s != "*"){
		int d = stoi(s);
		int n = s.length();
		int numlen = to_string(d).length();
		string pos = s.substr(numlen, n - numlen);
		if(pos == "N")currY += d;
		else if(pos == "S")currY -= d;
		else if(pos == "W")currX -= d;
		else if(pos == "E")currX += d;
		else if(pos == "NE"){
			currX += d * sqrt(2) / 2.0;
			currY += d * sqrt(2) / 2.0;
		}
		else if(pos == "SE"){
			currY -= d * sqrt(2) / 2.0;
			currX += d * sqrt(2) / 2.0;
		}
		else if(pos == "SW"){
			currY -= d * sqrt(2) / 2.0;
			currX -= d * sqrt(2) / 2.0;
		}
		else if(pos == "NW"){
			currY += d * sqrt(2) / 2.0;
			currX -= d * sqrt(2) / 2.0;
		}
		cin >> s;
	}
	printf("%.3f %.3f\n", (float)currX, (float)currY);
	printf("%.3lf", sqrt((double)pow(0.0 - currX, 2) + (double)pow(0.0 - currY, 2)));
}
