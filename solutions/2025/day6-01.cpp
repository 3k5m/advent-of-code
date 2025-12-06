#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;

int nums[1005][15];

//absolute mess of a code, wrote it while staying up overnight and just whatever works

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
        input.erase(0, input.find_first_not_of(' ')); // remove leading spaces
        if(DEB) cout<<"RECEIVED "<<input<<"\n";
        //start stores starting point of number, l stores length of number
        // k stores index of element in input currently looping through
        int start = 0, l = 0, k = 0;  
        //j stores the number index in row(nums array)
        int j = 0;
        while(k <= input.length() - 1){
            bool convertedNumThisTime = false;
            while(input[k] == ' '){
                if(!convertedNumThisTime){
                    //if(DEB) cout<<"current start: "<<start<<"l: "<<l<<"\n";
                    if(DEB) cout<<"attempting to store \'"<<input.substr(start, l)<<"\'\n";
                    if(DEB) cout<<"\t at position column:"<<j<<" row: "<<i<<"\n";
                    nums[j][i] = stoi(input.substr(start, l));
                    j ++;
                    start = start + l;
                    l = 0;
                    convertedNumThisTime = true;
                }else{
                    start++;
                    k++;
                }
            }
            k++;
            l++;
        }
        i++;
    }
    int rows = i;

    if(DEB) cout<<"current str: "<<input<<"\n";
    
    // have to do this because whitespace between operators means we can't just use the same i
    int operatorID = 0; 
    for(i = 0; i < input.length(); i++){
        if(input[i] == ' ') continue;
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
