#include <bits/stdc++.h>
using namespace std;

void solve(){
    int sum = 0;
    string input;
    while(true){
        getline(cin, input);
        if(input.empty()){
            break;
        }
        int largestfirst = 0, largestsecond = 0;
        int firsti, secondi;
        int inplen = input.length();
        // -1 because we don't want first element to be the last one in the string
        for(int i = 0; i < inplen - 1; i++){
            int c = input[i] - '0';
            if(c > largestfirst){
                largestfirst = c;
                firsti = i;
            }
        }
        for(int i = firsti + 1; i < inplen; i++){
            int c = input[i] - '0';
            if(c > largestsecond){
                largestsecond = c;
                secondi = i;
            }
        }
        sum += largestfirst * 10 + largestsecond;
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
