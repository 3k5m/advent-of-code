#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = true;

int nums[1005][15];

int first_one_not_space(string s, int start){
    for(int i = start; i < s.length(); i++){
        if(s[i] != ' '){
            //if(DEB) cout<<"returned "<<i<<" for call of f_o_n_s with index "<<start<<"\n";
            return i;
        }
    }
    return -1;
}

void solve(){
    ll sum = 0;
    string input, nums[105];

    int i = 0;
    //input fresh ranges

    while(true){
        getline(cin, input);
        if(input[0] == '+' || input[0] == '*'){ //should be valid only for last line with math symbols
            break;
        }
        nums[i] = input;
        i++;
    }
    int rows = i;

    if(DEB) cout<<"current str: "<<input<<"\n";

    // adding end character so first_one_not_space works
    input += 'Z';
    
    for(i = 0; i < input.length(); i++){
        if(input[i] == ' ') continue;
        if(input[i] == '+'){
            // note j must start at sign (beginning of numbers in the column)
            for(int j=i; j < first_one_not_space(input, i+1); j++){
                int row = 0;
                string num = "";
                for(int row = 0; row < rows; row++){
                    if(nums[row][j] != ' '){
                        num += nums[row][j];
                    }
                }
                if(!num.empty()){
                    if(DEB) cout<<"adding: "<<num<<"\n";
                    sum += stoll(num);
                }
            }
        }else if(input[i] == '*'){
            // note j must start at sign (beginning of numbers in the column)
            ll product = 1;
            for(int j=i; j < first_one_not_space(input, i+1); j++){
                int row = 0;
                string num = "";
                for(int row = 0; row < rows; row++){
                    if(nums[row][j] != ' '){
                        num += nums[row][j];
                    }
                }
                if(!num.empty()){
                    if(DEB) cout<<"multiplying: "<<num<<"\n";
                    product *= stoll(num);
                }
            }
            sum += product;
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
