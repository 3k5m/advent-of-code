#include <bits/stdc++.h>
using namespace std;

pair<int, int> dir[8] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void solve(){
    int sum = 0;
    string flmap[5005], flmap2[5005];
    string input;
    int i = 0, maxi;
    while(true){
        getline(cin, input);
        if(input.empty()){
            break;
        }
        flmap[i] = input;
        flmap2[i] = input;
        i++;
    }
    maxi = i;

    for(i = 0; i <= maxi; i ++){
        for(int j = 0; j < flmap[i].length(); j++){
            if(flmap[i][j] != '@') continue;
            int rolls = 0;
            for(auto x: dir){
                int newx = i + x.first;
                int newy = j + x.second;
                if(newx >= flmap[i].length() || newx < 0 || newy > maxi || newy < 0){
                    continue;
                }
                if(flmap[i + x.first][j + x.second] == '@'){
                    rolls ++;
                }
            }
            if(rolls < 4){
                sum ++;
                flmap2[i][j] = 'x';
            }
        }
    }
    for(i = 0; i <= maxi; i++){
        cout<<flmap2[i]<<"\n";
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
