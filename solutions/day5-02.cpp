#include <bits/stdc++.h>
using namespace std;

#define IS_DEBUGGING false

bool mustBeBefore[105][105] = {0};
int pages[105] = {0};

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
        pages[105] = {0};
        bool correct = true;
        
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
        for(int j=0; j < i; j++){
            for(int k=0; k < i; k++){
                int n1 = pages[j], n2 = pages[k];
                if(mustBeBefore[n1][n2] && j > k){
                    correct = false;
                }
            }
        }

        if(correct){
    if(IS_DEBUGGING) cout<<"Rule " + inputLine + " is correct. Adding its middle: "<<pages[(i)/2]<<"\n";
            sum += pages[(i)/2];
        }

    }

    cout<<sum<<"\n";
}

int main() {

    solve();

    return 0;
}
