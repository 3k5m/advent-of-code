#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = false;
const int MAXM = 10005;

//spent 30 minutes because int wasn't big enough to store the answer...
ll x[MAXM], y[MAXM], z[MAXM], maxi;
int visited[MAXM] = {0};
vector<pair<double, pair<int, int>>> dists;

double shortestlinedist(int j1, int j2){
    return sqrt(pow(x[j2]-x[j1], 2) + pow(y[j2]-y[j1], 2) + pow(z[j2]-z[j1], 2));
}

void fix_circuits(int old_circuit, int new_circuit){
    for(int i = 0; i < maxi; i++){
        if(visited[i] == old_circuit){
            visited[i] = new_circuit;
        }
    }
}

// checks circuit connections starting from junction box with id (id)
bool check_connections(int id){
    for(int i = 0; i < maxi; i++){
        if(visited[i] != 0){
            if(DEB) cout<<i<<" wasn't visited yet!\n";
            return false;
        }
    }
    if(DEB) cout<<"All junction boxes connected!\n";
    return true;
}

void solve(){
    ll final_result;
    string input;

    int i = 0;
    //input fresh ranges

    while(true){
        getline(cin, input, ',');
        if(input.empty()) break; // need to enter comma after pasting input
        x[i] = stoll(input);
        getline(cin, input, ',');
        y[i] = stoll(input);
        getline(cin, input);
        z[i] = stoll(input);
        i++;
    }
    maxi = i;
    for(i = 0; i < maxi; i++){
        for(int j = i+1; j < maxi; j++){
            dists.push_back(make_pair(shortestlinedist(i, j), make_pair(i, j)));
        }
    }
    sort(dists.begin(), dists.end());
    reverse(dists.begin(), dists.end());

    for(int i=0; i < maxi; i++){
        visited[i] = i;
    }

    while(true){
        if(dists.empty()) {
            cout<<"error: went through all junction boxes yet not all are connected to one circuit!\n";
            break;
        }
        pair<double, pair<int, int>> a = dists.back();
        dists.pop_back();
        int id1 = a.second.first;
        int id2 = a.second.second;
        if(DEB) cout<<"next closest distance is "<<a.first;
        if(DEB) cout<<" of junction boxes with IDs "<<id1<<" and "<<id2;
        if(DEB) cout<<". These IDs have coordinates of "<<x[id1]<<", "<<y[id1]<<", "<<z[id1]<<" ";
        if(DEB) cout<<" and "<<x[id2]<<", "<<y[id2]<<", "<<z[id2]<<"\n";

        int min_v = min(visited[id1], visited[id2]), max_v = max(visited[id1], visited[id2]);
        if(DEB && max_v != min_v) cout<<"fixing circuits of "<<max_v<<" into "<<min_v<<"\n";
        fix_circuits(max_v, min_v);
        visited[id1] = min_v;
        visited[id2] = min_v;

        if(check_connections(0)){
            final_result = x[id1] * x[id2];
            break;
        }
    }
    cout<<final_result;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
