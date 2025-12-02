#include <bits/stdc++.h>
using namespace std;

int list1[10005], list2[10005];
int bucket[100005];

void solve(){
    int sum = 0;
    int i=0; 
    while(true){
        string s;
        getline(cin, s);
        if(s.empty()) break; 

        int input1 = 0, input2 = 0;
        
        int digit = 4;
        bool i2 = false;
        for(char c: s){
            if(c == ' ') continue;
            else{
                if(digit < 0){
                    digit = 4;
                    i2=true;
                }
                if(i2) input2 += pow(10, digit) * (c - '0');
                else input1 += pow(10, digit) * (c - '0');
                digit --;
            }
        }

        list1[i] = input1;
        list2[i] = input2;
        i++;
    }
    sort(list1, list1 + i);
    sort(list2, list2 + i);

    for(int j=0;j<=i;j++){
        bucket[list2[j]] ++;
    }
    
    for(int j=0;j<=i;j++){
        sum += list1[j] * bucket[list1[j]];
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
