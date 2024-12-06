#include <bits/stdc++.h>
using namespace std;

#define IS_DEBUGGING true

// failed to solve this part
// work in progress code for future reference
// need to learn more about sorting
// (still don't know how to implement quicksort and just use c++ built-in sort)

bool mustBeBefore[105][105] = {0};
int pages[105] = {0};
bool pageCorrect[105] = {0};

bool checkUpdate(int i){
    bool correct = true;
    for(int j=0; j < i; j++){
        if(pageCorrect[j]) continue;
        bool thisPageC = true;
        for(int k=0; k < i; k++){
            int n1 = pages[j], n2 = pages[k];
            if(mustBeBefore[n1][n2] && j > k){
                correct = false;
                thisPageC = false;
            }
        }
        if(thisPageC){
            pageCorrect[j] = true;
            if(IS_DEBUGGING) cout<<pages[j]<<" has been shown as correct.\n";
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
        for(int z=0;z<105;z++) {pages[z] = 0; pageCorrect[z] = false;}
        
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
            //using randomness to swap positions of two incorrect tests
            srand((unsigned)time(0)); 
            int steps = 0;

            while(!checkUpdate(i)){
                steps ++; if(steps > 2000) break;
                int r = (rand()%(i-1));
                int r2 = (rand()%(i-1));
                if(!pageCorrect[r] && !pageCorrect[r2]){
                    if(IS_DEBUGGING) cout<<"Swapping "<<pages[r]<<" and "<<pages[r2]<<"\n";

                    int temp = pages[r];
                    pages[r] = pages[r2];
                    pages[r2] = temp;
                }
            }

            if(IS_DEBUGGING) cout<<"Rule " + inputLine + " corrected middle: "<<pages[(i)/2]<<"\n";
            sum += pages[(i)/2];
        }
    }

    cout<<sum<<"\n";
}

int main() {

    solve();

    return 0;
}
