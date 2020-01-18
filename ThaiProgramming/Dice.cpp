#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        int t = 1;
        int f = 2;
        int l = 3;
        int b = 5;
        int r = 4;
        int u = 6;
        string s;cin >> s;
        int len = s.length();
        for(int j = 0;j < len;j++){
            if(s[j] == 'F'){
                int temp = t;
                t = b;
                b = u;
                u = f;
                f = temp;
            }
            else if(s[j] == 'B'){
                int temp = t;
                t = f;
                f = u;
                u = b;
                b = temp;
            }
            else if(s[j] == 'L'){
                int temp = t;
                t = r;
                r = u;
                u = l;
                l = temp;
            }
            else if(s[j] == 'R'){
                int temp = t;
                t = l;
                l = u;
                u = r;
                r = temp;
            }
            else if(s[j] == 'C'){
                int temp = f;
                f = r;
                r = b;
                b = l;
                l = temp;
            }
            else if(s[j] == 'D'){
                int temp = f;
                f = l;
                l = b;
                b = r;
                r = temp;
            }
        }
        cout << f << " ";
    }
}