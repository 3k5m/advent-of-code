#include <bits/stdc++.h>
using namespace std;

long long searchforrange(long long firstn, long long secondn){
    long long sum = 0;
    for(long long ll = firstn; ll <= secondn; ll++){
        //cout<<"trying ll: "<<ll<<"\n";
        string lls = to_string(ll);
        int llslen = lls.length();

        //special special case where the ID is ONE CHARACTER (edge case ;-;)
        if(llslen == 1){
            continue;
        }

        //special case for n=1
        bool specialflag = true;
        for(int j = 1; j < llslen; j ++){
            if (lls[j] != lls[j-1]){
                specialflag = false;
                break;
            }
        }
        if(specialflag){
            cout<<"INVALID "<<ll<<"\n";
            sum += ll;
            continue; 
        }

        //cout<<"llslen: "<<llslen<<"\n";
        // only need to check even lengths
        for(int n = 2; n <= llslen / 2; n++ ){
            if(llslen % n == 0){
                bool flag = true;
                string llsportions[100];
                int i = 0, j = 0; 
                while(j < n){
                    llsportions[j] = lls.substr(i, llslen / n);
                        //cout<<"portion "<<j<<" SET TO "<<llsportions[j]<<" i: "<<i<<"\n";
                    i += llslen / n;
                    j++;
                }
                for(j = 1; j < n; j ++){
                    if (llsportions[j] != llsportions[j-1]){
                        //cout<<"portion: "<<llsportions[j]<<" NOT EQUAL "<<llsportions[j-1]<<"\n";
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    //cout<<"INVALID "<<ll<<"\n";
                    sum += ll;
                    //necessary to account for case like 222222 that repeat with both n=2 and n=3
                    break; 
                }
            }
        }
    }
    return sum;
}

void solve(){
    long long sum = 0;
    string input;
    getline(cin, input);
    // adds a comma for easier processing (, after every range)
    input = input + ","; 
    string firstnum = "", secondnum = "";
    long long firstnumll = 0, secondnumll = 0;
    bool first = true;
    for(char c:input){
        //cout<<"SCANNED CHAR: "<<c<<"\n";
        if (c == '-'){
            firstnumll = stoll(firstnum);
            first = false;
        }else if (c == ','){
            secondnumll = stoll(secondnum);
            first = true;
            //cout<<"Attempting searchforrange: "<<firstnumll<<" "<<secondnumll<<"\n";
            sum += searchforrange(firstnumll, secondnumll);
            firstnum= "";
            secondnum= "";
        }else if (first){
            firstnum += c;
        }else{
            secondnum += c;
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
