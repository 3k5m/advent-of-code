#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;

int splits = 0, rows;
string tachyon_diagram[1005];

void tach_beam(pair<int, int> coords){
    int x = coords.first;
    int y = coords.second;
    char cur = tachyon_diagram[y][x];
    if((cur == 'S' || cur == '.') && y < rows-1){
        tachyon_diagram[y][x] = '|'; // prevents repeated counting
        tach_beam({x, y+1});
    }else if(cur == '^'){
        splits ++;
        if(x > 0) tach_beam({x-1, y});
        if(x+1 < tachyon_diagram[y].length()) tach_beam({x+1, y});
    }
}

void solve(){
    ll sum = 0;
    string input;

    int i = 0;
    //input fresh ranges

    while(true){
        getline(cin, input);
        if(input.empty()) break;
        tachyon_diagram[i] = input;
        i++;
    }
    rows = i;

    pair<int, int> startcoords = {tachyon_diagram[0].find('S'), 0};

    tach_beam(startcoords);

    for(int y = 0; y < rows; y++){
        cout<<tachyon_diagram[y]<<"\n";
    }

    cout<<splits<<"\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
