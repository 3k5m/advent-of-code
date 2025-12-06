#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> freshranges[105];

const bool DEB = true;

void solve(){
    ll freshingredients = 0;
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
    int maxi = i - 1;

    //running the entire thing a bunch of times because once sometimes doesn't solve it for large enough numbers of ranges
    for(int attempts = 0; attempts <= maxi; attempts++){
        for(i = 0; i <= maxi; i++){
            if(freshranges[i].first == -1) continue;
            for(int j = 0; j <= maxi; j++){
                if(freshranges[j].first == -1) continue;
                // don't want to modify i itself
                if(i == j) continue;
                if(freshranges[j].second >= freshranges[i].first && freshranges[i].second >= freshranges[j].second){
                    if(DEB) cout<<"swapped stuff at indices "<<i<<" and "<<j<<" \n";
                    if(DEB) cout<<"\t current: "<<freshranges[i].first<<"-"<<freshranges[i].second<<" and "<<freshranges[j].first<<"-"<<freshranges[j].second<<"\n";
                    freshranges[i].first = min(freshranges[i].first, freshranges[j].first);
                    freshranges[i].second = max(freshranges[i].second, freshranges[j].second);
                    freshranges[j].first = -1;
                    if(DEB) cout<<"\t new: "<<freshranges[i].first<<"-"<<freshranges[i].second<<" and "<<freshranges[j].first<<"-"<<freshranges[j].second<<"\n";
                }
            }
        }
    }

    for(i = 0; i <= maxi; i++){
        if(freshranges[i].first == -1) continue;
        if(freshranges[i].first <= freshranges[i].second){
            //remember it is inclusive (need +1)
            freshingredients += freshranges[i].second - freshranges[i].first + 1;
            if(DEB) cout<<"added  "<<freshranges[i].second - freshranges[i].first + 1<<" ingredients \n";
            if(DEB) cout<<"\t this is from range: "<<freshranges[i].first<<"-"<<freshranges[i].second<<"\n";
            if(DEB) cout<<"\t at index "<<i<<"\n";
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
