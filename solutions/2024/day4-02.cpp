#include <bits/stdc++.h>
using namespace std;

#define IS_DEBUGGING false

string wordSearch[205];

int hLen;
int vLen;
int sum = 0;

// 0 = top left, 1 = bottom left, 2 = top right, 3 = bottom right
pair<int, int> directions[4] = {{-1,-1},{-1,1},{1,-1},{1,1}};

// "x" works when 0 = 2, 0 = 1, 2 = 3, 1 = 3 according to directions above
pair<int, int> matches[4] = {{0,2},{0,1},{2,3},{1,3}};

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
            if(wordSearch[y][x] == 'A'){
                if(IS_DEBUGGING) cout<<"Found first letter at x: "<<x<<" y: "<<y<<", beginning to look for other letters\n";
                
                bool foundWord = false;

                if(y + 1 > vLen || y - 1 < 0) continue;
                if(x + 1 > vLen || x - 1 < 0) continue;

                char letters[4];
                for(i = 0; i<4; i++){
                    letters[i] = wordSearch[y + directions[i].second][x + directions[i].first];
                }

                int numM = 0, numS = 0;
                for(char c : letters){
                    if(c == 'M') numM ++;
                    if(c == 'S') numS ++;
                }
                if(numM != 2 || numS != 2) continue;

                for(auto m : matches){
                    if(letters[m.first] == letters[m.second]){
                        foundWord = true;
                    }
                }

                if(foundWord){
                    if(IS_DEBUGGING) cout<<"Found word at x: "<<x<<" y: "<<y<<"\n";
                    sum++;
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
