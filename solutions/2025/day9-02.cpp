#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;

pair<ll, ll> red_tiles[1005];
ll largest_area = 0, min_x = 1e12, min_y = 1e12, largest_x = 0, largest_y = 0;
int maxi;

bool checkpoint(ll x, ll y){
    if(x <= largest_x && x >= min_x && y <= largest_y && y >= min_y){
        return true;
    }
    return false;
}

void solve(){
    ll sum = 0;
    string input;

    int i = 0;

    while(true){
        getline(cin, input, ',');
        if(input.empty()) break; // need to enter comma after pasting input
        red_tiles[i].first = stoll(input);
        if(red_tiles[i].first > largest_x) largest_x = red_tiles[i].first;
        if(red_tiles[i].first < min_x) min_x = red_tiles[i].first;
        getline(cin, input);
        red_tiles[i].second = stoll(input);
        if(red_tiles[i].second > largest_y) largest_y = red_tiles[i].second;
        if(red_tiles[i].second < min_y) min_y = red_tiles[i].second;
        i++;
    }
    maxi = i;
    for(i = 0; i < maxi; i++){
        for(int j=0; j< maxi; j++){
            ll new_area = (red_tiles[i].first - red_tiles[j].first + 1) * (red_tiles[i].second - red_tiles[j].second + 1);
            if(new_area > largest_area){
                ll p1x = max(red_tiles[i].first, red_tiles[j].first);
                ll p1y = max(red_tiles[i].second, red_tiles[j].second);
                ll p2x = min(red_tiles[i].first, red_tiles[j].first);
                ll p2y = min(red_tiles[i].second, red_tiles[j].second);
                if(checkpoint(p1x, p1y) && checkpoint(p2x, p2y)){
                    largest_area = new_area;
                }
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
