#include <bits/stdc++.h>
using namespace std;

#define IS_DEBUGGING false

string wordSearch[205];

int hLen;
int vLen;
int sum = 0;

const string WordToFind = "XMAS";

pair<int, int> directions[8] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1},};

void solve(){
    string ws;
    int i=0;
    do{
        getline(cin, ws);
        wordSearch[i] = ws;
        i++;
    }while(!ws.empty());

    if(IS_DEBUGGING) cout<<"Input Finished successfully\n";

    hLen = wordSearch[0].length() - 1;
    vLen = i;
    
    for(int x = 0; x <= hLen; x++){
        for(int y = 0; y <= vLen; y++){
            if(wordSearch[y][x] == WordToFind[0]){
                if(IS_DEBUGGING) cout<<"Found first letter at x: "<<x<<" y: "<<y<<", beginning to look for other letters\n";
                for(auto dir : directions){
                    bool foundWord = true;
                    for(i = 1; i<WordToFind.length(); i++){
                        int newy = y+dir.second * i;
                        int newx = x+dir.first * i;
                        if(newy > vLen || newy < 0) {
                            foundWord = false;
                            break;
                        }
                        if(newx > hLen || newx < 0) {
                            foundWord = false;
                            break;
                        }
                        if(wordSearch[newy][newx] != WordToFind[i]){
                            foundWord = false;
                        }
                    }
                    if(foundWord){
                        if(IS_DEBUGGING) cout<<"Found word at x: "<<x<<" y: "<<y<<"\n";
                        sum++;
                    }
                }
            }
        }
    }
    cout<<sum;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
