#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;

ll timelines = 0, rows;
string tachyon_diagram[1005];
ll tachyon_possibilities[1005][1005] = {0};

void solve(){
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
    cout<<"num rows "<<rows<<"\n";

    pair<int, int> startcoords = {tachyon_diagram[0].find('S'), 0};

    tachyon_possibilities[0][startcoords.first] = 1;
    //tach_beam(startcoords);
    
    int col = tachyon_diagram[0].length();

    for(int y = 1; y < rows; y++){
        for(int z = 0; z < col; z++){
            if(tachyon_diagram[y-1][z] != '^') tachyon_possibilities[y][z] += tachyon_possibilities[y-1][z];
            if(tachyon_diagram[y][z] == '^'){
                tachyon_possibilities[y][z-1] += tachyon_possibilities[y][z];
                tachyon_possibilities[y][z+1] += tachyon_possibilities[y][z];
            }
        }
    }
    for(int z = 0; z < col; z++){
        timelines += tachyon_possibilities[rows-1][z];
    }

    if(DEB){
        for(int y = 0; y < rows; y++){
            for(int z = 0; z < col; z++){
                cout<<tachyon_possibilities[y][z]<<"\t";
            }
            cout<<"\n";
        }
    }
    
    cout<<timelines<<"\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
