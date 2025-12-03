#include <bits/stdc++.h>
using namespace std;

long long searchforrange(long long firstn, long long secondn){
    long long sum = 0;
    for(long long ll = firstn; ll <= secondn; ll++){
        //cout<<"trying ll: "<<ll<<"\n";
        string lls = to_string(ll);
        int llslen = lls.length();
        //cout<<"llslen: "<<llslen<<"\n";
        // only need to check even lengths
        if(llslen % 2 == 0){
            string llsfirsthalf = lls.substr(0, llslen/2);
            string llssecondhalf = lls.substr(llslen/2);
            //cout<<"llsfirsthalf: "<<llsfirsthalf<<"\n";
            //cout<<"llssecondhalf: "<<llssecondhalf<<"\n";
            if(llsfirsthalf == llssecondhalf){
                sum += ll;
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
