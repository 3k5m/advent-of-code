#include <bits/stdc++.h>
using namespace std;

#define IS_DEBUGGING false

void solve(){
    string corrupted_memory = "";
    string cm;
    do{
        getline(cin, cm);
        corrupted_memory+=cm;
    }while(!cm.empty());
    cin>>corrupted_memory;

    string curStage = "NONE";
    int num1 = 0, num2 = 0, sum = 0;
    string curnum = "";

    bool enabled = true;

    for(int i=0;i<corrupted_memory.length();i++){

        char c = corrupted_memory[i];

        if(IS_DEBUGGING) cout<<"Character: "<<c<< " Current Stage is "<<curStage<<" \n";

        
        if(curStage == "NUMBER1"){
            if(c >= '0' && c <= '9'){
                curnum += c;
            }else if(c == ','){
                num1 = stoi(curnum);
                curnum = "";
                curStage = "NUMBER2";
            }else{
                if(IS_DEBUGGING) cout<<"Detected "<<c<< " instead of digit or comma, CurStage is NONE \n";
                curStage = "NONE";
            }
        }else if(curStage == "NUMBER2"){
            if(c >= '0' && c <= '9'){
                curnum += c;
            }else if(c == ')'){
                num2 = stoi(curnum);
                if(enabled){sum += num1 * num2;}
                else if(IS_DEBUGGING) cout<<"Would've multiplied, but mul was disabled.\n";
                if(IS_DEBUGGING) cout<<"Multiplying "<<num1<< " and "<<num2<< "\n";
                curStage = "NONE";
            }else{
                if(IS_DEBUGGING) cout<<"Detected "<<c<< " instead of digit or right bracket, CurStage is NONE \n";
                curStage = "NONE";
            }
        }

        
        if(curStage == "NONE"){
            num1 = 0; num2 = 0;
            curnum = "";
        }

        // need to keep checking for numbers until manually stopped (since they can be arbitrary length)
        if(curStage == "NUMBER1" || curStage == "NUMBER2") continue;

        if(curStage == "NONE"){
            if(corrupted_memory[i]=='m' && corrupted_memory[i+1]=='u' && corrupted_memory[i+2]=='l' && corrupted_memory[i+3]=='('){
                if(IS_DEBUGGING) cout<<"STARTING mul() attempt as mul( was detected\n";
                i+=3;
                curStage = "NUMBER1";
            }else if(corrupted_memory[i]=='d' && corrupted_memory[i+1]=='o' && corrupted_memory[i+2]=='(' && corrupted_memory[i+3]==')'){
                if(IS_DEBUGGING) cout<<"Enabled mul as do() was detected \n";
                i+=3;
                enabled = true;
            }else if(corrupted_memory[i]=='d' && corrupted_memory[i+1]=='o' && corrupted_memory[i+2]=='n' && corrupted_memory[i+3]=='\'' && corrupted_memory[i+4]=='t'){
                if(IS_DEBUGGING) cout<<"Disabled mul as don\'t() was detected \n";
                i+=4;
                enabled = false;
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
