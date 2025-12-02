#include <bits/stdc++.h>
using namespace std;

const int MAXROT = 99;

void solve() {
    int flag = 0;
    string input;
    int curROT = 50;
    while (true) {
        getline(cin, input);
        if (input.empty()) {
            break;
        }
        if (input[0] == 'L') {
            input.erase(0, 1);
            int steps = stoi(input);
            while (steps--) {
                curROT -= 1;
                if (curROT == -1) {
                    curROT = 99;
                }
                if (curROT == 0) {
                    flag++;
                }
            }
        }
        else if (input[0] == 'R') {
            input.erase(0, 1);
            int steps = stoi(input);
            while (steps--) {
                curROT += 1;
                if (curROT == 100) {
                    curROT = 0;
                }
                if (curROT == 0) {
                    flag++;
                }
            }
        }

    }
    cout << flag << "\n";
    system("pause");
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
