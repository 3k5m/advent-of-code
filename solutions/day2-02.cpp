#include <bits/stdc++.h>
using namespace std;

#define IS_DEBUGGING false

//not finished yet
//TODO: implement isSafe, change logic to turn string into array of ints
//attempt isSafe with each variation (remove one report at a time)
//very inefficient but probably easiest way I can think of?

//pass in reports and length to loop through
bool isSafe(int reports[105], int l){
    int curNum = -1, prevNum;
    bool incFlag = false, decFlag = false;
    bool unsafe = false;
    
    if(IS_DEBUGGING) cout<<"looping through report with length = "<<l<<"\n";
    if(IS_DEBUGGING) cout<<"Report output: ";
    if(IS_DEBUGGING) for(int i=0;i<l;i++) cout<<reports[i]<<" ";
    if(IS_DEBUGGING) cout<<"\n";
    for(int i = 0; i < l; i++){

        if(reports[i] == -1){
            if(IS_DEBUGGING) cout<<"skipped report value -1 at index "<<i<<"\n";
            continue;
        }

        if(curNum == -1) {
            curNum = reports[i];
            continue;
        }

        prevNum = curNum;
        curNum = reports[i];
        if(curNum > prevNum) incFlag = true;
        if(curNum < prevNum) decFlag = true;
        if(curNum == prevNum) {
            unsafe = true;
            if(IS_DEBUGGING) cout<<curNum<<" is equal to "<<prevNum<<", report failed.\n";
        }

        if(abs(curNum - prevNum) > 3){
            unsafe = true;
            if(IS_DEBUGGING) cout<<curNum<<" and "<<prevNum<<" abs difference > 3, report failed.\n";
        }

        if(incFlag && decFlag){
            unsafe = true;
            if(IS_DEBUGGING) cout<<"  both incFlag & decFlag were set, report failed.\n";
            break;
        }
    }
    return !unsafe;
}

void solve(){
    int sum = 0, guaranteedsum = 0;
    while(true){
        string s;
        getline(cin, s);
        if(s.empty()) break; 

        //adding a space at the end to detect last number
        //hacky fix lol
        s += " ";

        int reportsToCheck[105];
        string num = "";
        int j = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                reportsToCheck[j] = stoi(num);
                num = "";
                j++;
            }else{
                num += s[i];
            }
        }
        bool safe = isSafe(reportsToCheck, j);

        if(!safe){
            for(int i = 0; i < j; i++){
                int tempReports[105];
                copy(reportsToCheck, reportsToCheck + j, tempReports);
                tempReports[i] = -1;
                bool tempS = isSafe(tempReports, j);
                if(tempS) {
                    safe = true;
                    break;
                }
            }
        }else {
            guaranteedsum++;
        }

        if(safe) sum++;
    }
    cout<<sum <<" with dampen, "<<guaranteedsum<<" without.\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
