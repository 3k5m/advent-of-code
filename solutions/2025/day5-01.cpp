#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> freshranges[105];

void solve(){
    int freshingredients = 0;
    string input;

    int i = 0;
    //input fresh ranges
    while(true){
        getline(cin, input);
        if(input.empty()){
            break;
        }
        int minusindex = input.find('-');
        freshranges[i].first = stoll(input.substr(0, minusindex));
        freshranges[i].second = stoll(input.substr(minusindex + 1, input.length() - minusindex));
        //cout<<freshranges[i].first<<"    "<<freshranges[i].second<<"\n";
        i++;
    }
    int maxi = i;

    //input ingredient IDs
    while(true){
        getline(cin, input);
        if(input.empty()){
            break;
        }
        ll id = stoll(input);
        for(i = 0; i <= maxi; i++){
            if(id >= freshranges[i].first && id <= freshranges[i].second){
                freshingredients ++;
                break;
            }
        }
    }
    cout<<freshingredients<<"\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
