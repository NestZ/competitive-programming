#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void out(int n){
		printf("%d\n", n);
		fflush(stdout);
}

void in(char &c){
		cin.ignore();
		scanf("%c", &c);
}

int main(){
	int t, b;scanf("%d %d", &t, &b);
	while(t--){
		string bit(b, '0');
		pair<int, int> samein = make_pair(-1, -1);
		pair<int, int> xorin = make_pair(-1, -1);
		char temp = '0';
		int cnt = 10;
		int currin = 6;
		int round = 0;
		for(int i = 1;i <= 5;i++){
			out(i);
			in(temp);
			bit[i - 1] = temp;
			out(b - i + 1);
			in(temp);
			bit[b - i] = temp;
			if(bit[b - i] == bit[i - 1] && samein.first == -1){
				samein.first = i - 1;
				samein.second = bit[i - 1] - '0';
			}
			else if(bit[b - i] != bit[i - 1] && xorin.first == -1){
				xorin.first = i - 1;
				xorin.second = bit[i - 1] - '0';
			}
			round += 2;
		}
		while(cnt < b){
			out(currin);
			in(temp);
			bit[currin - 1] = temp;
			round++;
			if(round % 10 == 1){
				bool same = false;
				bool xorr = false;
				char newbit = '0';
				out(max(1, samein.first + 1));
				in(newbit);
				round++;
				if(samein.first != -1){
					if(newbit - '0' != samein.second){
						samein.second = newbit - '0';
						same = true;
					}
				}
				out(max(1, xorin.first + 1));
				in(newbit);
				round++;
				if(xorin.first != -1){
					if(newbit - '0' != xorin.second){
						xorin.second = newbit - '0';
						xorr = true;
					  }
				}
				if(samein.first != -1 && xorin.first != -1){
					if(same && xorr){
						for(char &c : bit)c = (c == '1' ? '0' : '1');
					}
					else if(xorr && !same)reverse(bit.begin(), bit.end());
					else if(same && !xorr){
						reverse(bit.begin(), bit.end());
						for(char &c : bit)c = (c == '1' ? '0' : '1');
					}
				}
				else if(samein.first != -1){
					if(same)for(char &c : bit)c = (c == '1' ? '0' : '1');
				}
				else if(xorin.first != -1){
					if(xorr)reverse(bit.begin(), bit.end());
				}
				bit[currin - 1] = temp;
			}
			out(b - currin + 1);
			in(temp);
			bit[b - currin] = temp;
			round++;
			if(bit[b - currin] == bit[currin - 1] &&
			   samein.first == -1){
				samein.first = currin - 1;
				samein.second = bit[currin - 1] - '0';
			}
			else if(bit[b - currin] != bit[currin - 1] &&
			   xorin.first == -1){
				xorin.first = currin - 1;
				xorin.second = bit[currin - 1] - '0';
			}
			currin++;
			cnt += 2;
		}
		printf("%s\n", bit.c_str());
		fflush(stdout);
		cin.ignore();
		char r;scanf("%c", &r);
		if(r == 'N')return 0;
	}
}
