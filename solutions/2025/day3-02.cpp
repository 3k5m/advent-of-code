#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DIGITS 12

void solve(){
    ll sum = 0;
    string input;
    while(true){
        getline(cin, input);
        if(input.empty()){
            break;
        }

        int largestnum = 0, previ = -1;
        int inplen = input.length();
        for(int i = 0; i < DIGITS; i++){
            largestnum = 0;
            for(int j = previ + 1; j <= inplen - (DIGITS - i); j++){
                int c = input[j] - '0';
                if(c > largestnum){
                    largestnum = c;
                    previ = j;
                }
            }
            sum += largestnum * pow(10, DIGITS - i - 1);
            //cout<<largestnum * pow(10, DIGITS - i - 1)<<" WAS ADDED \n";
        }
    }
    cout<<sum<<"\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
