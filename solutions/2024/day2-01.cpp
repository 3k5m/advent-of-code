#include <bits/stdc++.h>
using namespace std;

int report[105];

void solve(){
    int sum = 0;
    int i=0; 
    while(true){
        string s;
        getline(cin, s);
        if(s.empty()) break; 

        //adding a space at the end to detect last number
        //hacky fix lol
        s += " ";
        
        int curNum, prevNum;
        bool incFlag = false, decFlag = false, firstNum = true;

        bool unsafe = false;

        int digit = 1, nextNum = 0;
        string num = "";
        for(char c: s){
            if(c == ' '){
                nextNum = stoi(num);
                num = "";
                if(firstNum){
                    curNum = nextNum;
                    firstNum = false;
                }else{
                    prevNum = curNum;
                    curNum = nextNum;
                    if(curNum > prevNum) incFlag = true;
                    if(curNum < prevNum) decFlag = true;
                    if(curNum == prevNum) {
                        unsafe = true;
                        //cout<<curNum<<" is equal to "<<prevNum<<", report failed.\n";
                        break;
                    }

                    if(abs(curNum - prevNum) > 3){
                        unsafe = true;
                        //cout<<curNum<<" and "<<prevNum<<" abs difference > 3, report failed.\n";
                        break;
                    }

                    if(incFlag && decFlag){
                        unsafe = true;
                        //cout<<"  both incFlag & decFlag were set, report failed.\n";
                        break;
                    }
                }
            }else{
                num += c;
            }
        }

        if(!unsafe) sum++;
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
