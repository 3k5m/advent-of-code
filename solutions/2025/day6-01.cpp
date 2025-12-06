#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;

int nums[1005][15];

void nums_from_string(int row, string s){
    int column = 0;
    string curNum = "";
    for(char c: s){
        if(c <= '9' && c >= '0'){
            curNum += c;
        }else if(!curNum.empty()){
            nums[column][row] = stoi(curNum);
            column++;
            curNum = "";
        }
    }
}

void solve(){
    ll sum = 0;
    string input;

    int i = 0;
    //input fresh ranges

    while(true){
        getline(cin, input);
        if(input[0] == '+' || input[0] == '*'){ //should be valid only for last line with math symbols
            break;
        }
        input.append(" "); //append string to allow for formatting the last number
        if(DEB) cout<<"RECEIVED "<<input<<"\n";

        nums_from_string(i, input);
        i++;
    }
    int rows = i;

    if(DEB) cout<<"current str: "<<input<<"\n";
    
    // have to do this because whitespace between operators means we can't just use the same i
    int operatorID = 0; 
    for(i = 0; i < input.length(); i++){
        if(input[i] == '+'){
            for(int j = 0; j < rows; j++){
                sum += nums[operatorID][j];
                if(DEB) cout<<"adding: "<<nums[operatorID][j]<<"\n";
                if(DEB) cout<<"\t at position column:"<<i<<" row: "<<j<<"\n";
            }
            operatorID ++;
        }else if(input[i] == '*'){
            ll product = 1;
            for(int j = 0; j < rows; j++){
                product *= nums[operatorID][j];
                if(DEB) cout<<"multiplying: "<<nums[operatorID][j]<<"\n";
                if(DEB) cout<<"\t at position column:"<<i<<" row: "<<j<<"\n";
            }
            sum += product;
            operatorID ++;
        }
    }
    cout<<sum<<"\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
