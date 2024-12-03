#include <bits/stdc++.h>
using namespace std;

//not finished yet
//TODO: implement isSafe, change logic to turn string into array of ints
//attempt isSafe with each variation (remove one report at a time)
//very inefficient but probably easiest way I can think of?

//pass in reports and length to loop through
bool isSafe(int reports[105], int l){
    int curNum, prevNum;
    int errors = 0;
    bool incFlag = false, decFlag = false, firstNum = true;
    bool unsafe = false;
    int digit = 1, nextNum = 0;
    string num = "";
    
    for(char c: ){
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
                    errors ++;
                }

                if(abs(curNum - prevNum) > 3){
                    unsafe = true;
                    //cout<<curNum<<" and "<<prevNum<<" abs difference > 3, report failed.\n";
                    errors ++;
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
    return unsafe;
}

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
        int errors = 0;
        bool incFlag = false, decFlag = false, firstNum = true;
        bool unsafe = false;
        int digit = 1, nextNum = 0;

        int reportsToCheck[105];
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
                        errors ++;
                    }

                    if(abs(curNum - prevNum) > 3){
                        unsafe = true;
                        //cout<<curNum<<" and "<<prevNum<<" abs difference > 3, report failed.\n";
                        errors ++;
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
