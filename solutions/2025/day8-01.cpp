#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;
const int MAXM = 10005;
const int PAIRS_TO_CONNECT = 1000;


int x[MAXM], y[MAXM], z[MAXM];
bool connected[MAXM][MAXM];
vector<pair<double, pair<int, int>>> dists;

int circuits[MAXM] = {0};
int circuits_counts[MAXM] = {0};

//priority_queue<int> checklist;


double shortestlinedist(int j1, int j2){
    return sqrt(pow(x[j2]-x[j1], 2) + pow(y[j2]-y[j1], 2) + pow(z[j2]-z[j1], 2));
}

void solve(){
    ll sum = 0;
    string input;

    int i = 0;
    //input fresh ranges

    while(true){
        getline(cin, input, ',');
        if(input.empty()) break; // need to enter comma after pasting input
        x[i] = stoi(input);
        getline(cin, input, ',');
        y[i] = stoi(input);
        getline(cin, input);
        z[i] = stoi(input);
        i++;
    }
    int maxi = i;
    for(i = 0; i < maxi; i++){
        for(int j = i+1; j < maxi; j++){
            dists.push_back(make_pair(shortestlinedist(i, j), make_pair(i, j)));
        }
    }
    sort(dists.begin(), dists.end());
    reverse(dists.begin(), dists.end());

    for(i=0;i< PAIRS_TO_CONNECT;i++){
        if(dists.empty()) break;
        pair<double, pair<int, int>> a = dists.back();
        dists.pop_back();
        int id1 = a.second.first;
        int id2 = a.second.second;
        //cout<<"next closest distance is "<<a.first;
        //cout<<" of junction boxes with IDs "<<id1<<" and "<<id2;
        //cout<<". These IDs have coordinates of "<<x[id1]<<", "<<y[id1]<<", "<<z[id1]<<" ";
        //cout<<" and "<<x[id2]<<", "<<y[id2]<<", "<<z[id2]<<"\n";

        connected[id1][id2] = true;
        connected[id2][id1] = true;
    }
    // initialize all junctions as individual circuits
    for(i = 0; i < maxi; i++){
        circuits[i] = i+1;
    }
    // take the lowest circuit that each junction is connected to
    for(int k = 0; k < 10; k++) // running this 10x because it doesn't work when only run once
    for(i = 0; i < maxi; i++){
        for(int j = i+1; j < maxi; j++){
            if(connected[i][j] || connected[j][i]){
                circuits[i] = min(circuits[i], circuits[j]);
                circuits[j] = min(circuits[i], circuits[j]);
                //cout<<" junction box connection identified between ID "<<i<<" AND "<<j<<", placed in circuit "<<circuits[i]<<"\n";
            }
        }
    }

    // count num of junctions in each circuit
    for(i = 0; i < maxi; i++){
        for(int j = 0; j < maxi; j++){
            if(circuits[j] == i+1){
                circuits_counts[i+1] ++;
            }
        }
    }
    sort(begin(circuits_counts), end(circuits_counts), greater<>());
    cout<<"MULTIPLYING circuits with elements "<<circuits_counts[0]<<","<<circuits_counts[1]<<","<<circuits_counts[2]<<"\n";
    cout<<circuits_counts[0] * circuits_counts[1] * circuits_counts[2];

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
