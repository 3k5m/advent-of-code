#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct coords {
    ll x, y;
};

const bool DEB = false;
const int MAXM = 100005;

coords red_tiles[1005];
ll largest_area = 0, min_x = 1e12, min_y = 1e12, largest_x = 0, largest_y = 0;
int maxi;

bool checkpoint(coords point){
    int intersections = 0;
    for(int i = 0; i < maxi; i++){
        coords p1 = red_tiles[i];
        coords p2 = red_tiles[(i+1) % maxi];
        if(point.y > min(p1.y, p2.y) && point.y <){

        }
    }
    return false;
}

void solve(){
    ll sum = 0;
    string input;

    int i = 0;

    int prevx = -1, prevy = -1;
    while(true){
        getline(cin, input, ',');
        if(input.empty()) break; // need to enter comma after pasting input
        ll ix = stoll(input);
        red_tiles[i].x = ix;
        getline(cin, input);
        ll iy = stoll(input);
        red_tiles[i].y = iy;
        i++;
    }
    maxi = i;
    for(i = 0; i < maxi; i++){
        for(int j=0; j< maxi; j++){
            ll new_area = (red_tiles[i].x - red_tiles[j].x + 1) * (red_tiles[i].y - red_tiles[j].y + 1);
            if(new_area > largest_area){
                ll p1x = max(red_tiles[i].x, red_tiles[j].x);
                ll p1y = max(red_tiles[i].y, red_tiles[j].y);
                ll p2x = min(red_tiles[i].x, red_tiles[j].x);
                ll p2y = min(red_tiles[i].y, red_tiles[j].y);
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
