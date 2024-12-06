#include <bits/stdc++.h>
using namespace std;

#define IS_DEBUGGING false

// was going to give up on this part but I saw this reddit comment saying to just swap when a rule is violated
// https://www.reddit.com/r/adventofcode/comments/1h71eyz/comment/m0m81aj/
// thank you u/Enemiend

bool mustBeBefore[105][105] = {0};
int pages[105] = {0};

bool checkUpdate(int i){
    bool correct = true;
    for(int j=0; j < i; j++){
        for(int k=0; k < i; k++){
            int n1 = pages[j], n2 = pages[k];
            if(mustBeBefore[n1][n2] && j > k){
                correct = false;
                if(IS_DEBUGGING) cout<<"Swapping "<<pages[j]<<" and "<<pages[k]<<"\n";
                //swapping should hopefully resolve all rule breaks
                int temp = pages[k];
                pages[k] = pages[j];
                pages[j] = temp;

            }
        }
    }
    return correct;
}

void solve(){
    string inputLine;
    int sum = 0;
    /* do{
        int r1, r2;
        scanf("%d|%d", r1, r2);
        mustBeBefore[r1][r2] = 1;
    }while(!ws.empty()); */
    
    //first input the rules
    while(true){
        int r1, r2;
        string num = "";

        getline(cin, inputLine);

        //exit condition. means that input always has to end on newline
        if(inputLine.empty()) break;

        //hardcoding E as the end because of the way the string is split into ints
        inputLine += 'E';

        //if(IS_DEBUGGING) cout<<"Attempting to parse Line:" + inputLine + "\n";

        for(char c: inputLine){
            if(c == '|'){
                r1 = stoi(num);
                num = "";
            }else if(c == 'E'){
                r2 = stoi(num);
                num = "";
            }else{
                num += c;
            }
        }
        mustBeBefore[r1][r2] = true;
    }
    
    

    if(IS_DEBUGGING) cout<<"Input of Rules Finished successfully\n";

    //then the test cases
    while(true){
        string num = "";
        for(int z=0;z<105;z++) {pages[z] = 0;}
        
        int i=0;

        getline(cin, inputLine);

        //exit condition. means that input always has to end on newline
        if(inputLine.empty()) break;

        //hardcoding , at the end because of the way the string is split into ints
        inputLine += ',';
        
        for(char c: inputLine){
            if(c == ','){
                pages[i] = stoi(num);
                i++;
                num = "";
            }else{
                num += c;
            }
        }

        if(IS_DEBUGGING) cout<<"Received Input of Rule: " + inputLine + ". Beginning its analysis.\n";

        if(checkUpdate(i)){
            if(IS_DEBUGGING) cout<<"Rule " + inputLine + " was already correct, no need to add its middle.\n";
        }else{
            if(IS_DEBUGGING){
                cout<<"Original Rule " + inputLine<<"\n";
                cout<<"Corrected Rule: ";
                for(auto x : pages){
                    if(x == 0) break;
                    cout<<x<<", ";
                }
                cout<<"\nCorrected middle: "<<pages[(i)/2]<<"\n";
            }
            sum += pages[(i)/2];
        }
    }

    cout<<sum<<"\n";
}

int main() {

    solve();

    return 0;
}
