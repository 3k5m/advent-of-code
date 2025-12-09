#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;

pair<ll, ll> red_tiles[1005];
ll largest_area = 0;

void solve(){
    ll sum = 0;
    string input;

    int i = 0;

    while(true){
        getline(cin, input, ',');
        if(input.empty()) break; // need to enter comma after pasting input
        red_tiles[i].first = stoi(input);
        getline(cin, input);
        red_tiles[i].second = stoi(input);
        i++;
    }
    int maxi = i;
    for(i = 0; i < maxi; i++){
        for(int j=0; j< maxi; j++){
            ll new_area = (red_tiles[i].first - red_tiles[j].first + 1) * (red_tiles[i].second - red_tiles[j].second + 1);
            if(new_area > largest_area){
                largest_area = new_area;
            }
        }
    }
    cout<<largest_area;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
