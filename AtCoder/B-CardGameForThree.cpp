#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      string s1, s2, s3;cin >> s1 >> s2 >> s3;
      char now = 'a';
      while(true){
            if(now == 'a'){
                  if(s1.empty())return cout << 'A', 0;
                  now = s1.front();
                  s1 = s1.substr(1, s1.length() - 1);
            }
            if(now == 'b'){
                  if(s2.empty())return cout << 'B', 0;
                  now = s2.front();
                  s2 = s2.substr(1, s2.length() - 1);
            }
            if(now == 'c'){
                  if(s3.empty())return cout << 'C', 0;
                  now = s3.front();
                  s3 = s3.substr(1, s3.length() - 1);
            }
      }
}