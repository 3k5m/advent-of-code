#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const bool DEB = true;
const int MAXM = 15;

struct light_state{
    bool required_lights[MAXM] = {0};
    int lights;
    bool compare_states(light_state ls){
        if(ls.lights != lights) return false;
        for(int i = 0; i < lights; i++){
            if(ls.required_lights[i] != required_lights[i]){
                return false;
            }
        }
        return true;
    }
};

struct machine{
    light_state ls;
    vector<int> buttons[MAXM];
    vector<int> voltage;
};

bool completed_machine(machine m, light_state cur_lights){
    return cur_lights.compare_states(m.ls);
}

machine process_input(string input){
    int index = 0;
    machine m;
    int i = 0;
    while(input[index] != ']' && index < input.length()){
        if(input[index] == '[') {
            index++;
            continue;
        }else {
            m.ls.required_lights[i] = (input[index] == '#') ? 1:0;
            i++;
        }
        index++;
    }
    m.ls.lights = i;
    index += 2;

    i = 0;
    string num = "";
    while(input[index] != '{' && index < input.length()){
        if(input[index] == ',' || input[index] == ')'){
            m.buttons[i].push_back(stoi(num));
            num = "";
        }else if(input[index] == ' '){
            i++;
        }else if(input[index] >= '0' && input[index] <= '9'){
            num += input[index];
        }
        index++;
    }
    index ++;
    num = "";
    while(index < input.length()){
        if(input[index] == ',' || input[index] == '}'){
            m.voltage.push_back(stoi(num));
            num = "";
        }else{
            num += input[index];
        }
        index++;
    }
    return m;
}

void output_machine(machine m){
    cout<<"PROCESSED m with LIGHTS ";
    for(int i = 0; i<m.ls.lights; i ++){
        bool x = m.ls.required_lights[i];
        if(x) cout<<'O';
        else cout<<'.';
    }
    cout<<" BUTTONS ";
    for(vector<int> x: m.buttons){
        if(x.empty()) break;
        cout<<"(";
        for(int i:x){
            cout<<i<<',';
        }
        cout<<") ";
    }
    cout<<" VOLTAGE ";
    for(int x: m.voltage){
        cout<<x<<',';
        cout<<' ';
    }
    cout<<"\n";
}

bool machine_bfs(machine m, int button, light_state cur_lights, int steps, vector<int> previously_pressed){
    bool flag = false;
    for(int i : m.buttons[button]){
        cur_lights.required_lights[i] = !cur_lights.required_lights[i];
    }
    previously_pressed.push_back(button);
    if(steps > 1){ // further recursion
        for(int i = 0; !m.buttons[i].empty(); i++){
            // only check button if it wasn't previously pressed
            if(find(previously_pressed.begin(), previously_pressed.end(), i) == previously_pressed.end()){
                if (machine_bfs(m, i, cur_lights, steps-1, previously_pressed)){
                    return true;
                }
            }
        }
    }else if(steps == 1){ // this is the last step
        if(completed_machine(m, cur_lights)){
            return true;
        }
    }else{
        cout<<"ERROR! Encountered negative steps.";
    }
    return false;
}

light_state press_all_buttons(machine m){
    light_state ls;
    ls.lights = m.ls.lights;
    for(int i = 0; !m.buttons[i].empty(); i++){
        for(int j : m.buttons[i]){
            ls.required_lights[j] = !ls.required_lights[j];
        }
    }
    return ls;
}

int solve_machine(machine m){
    // implement some sort of bfs? (queue with buttons, etc.)
    // add a while loop that increments layers by one each time (going through every number of layer-presses, so press all once, twice, etc)
    // use recursion to test each case, so do test(machine, layers), so we can test 4 layers, which will run the function on all 3 layers (of the 4th layer altered)
    // lights, then do the same on 2 layers, etc. if one of the function is a success, return true, and if it reaches 0 without success, return false (end condition)
    // of recursion. 
    int layers = 0;
    light_state empty_lights;
    empty_lights.lights = m.ls.lights;
    light_state full_lights;
    full_lights = press_all_buttons(m);

    int temp_i, max_layers;
    for( temp_i = 0; !m.buttons[temp_i].empty(); temp_i++);
    max_layers = ceil(temp_i/2);

    while(true){
        layers++;
        for(int i = 0; !m.buttons[i].empty(); i++){
            vector<int> empty_vector;
            if (machine_bfs(m, i, empty_lights, layers, empty_vector)){
                return layers;
            }
        }
        if(layers > max_layers) {
            cout<<"Couldn't find layers after "<<layers<<" layers of recursion!\n";
            cout<<"Attempting reverse search...\n";
            break;
        }
    }
    layers = 0;
    while(true){
        layers++;
        for(int i = 0; !m.buttons[i].empty(); i++){
            vector<int> empty_vector;
            if (machine_bfs(m, i, full_lights, layers, empty_vector)){
                return temp_i - layers;
            }
        }
        if(layers > max_layers) {
            cout<<"ERROR! Couldn't find layers after "<<layers<<" layers of recursion for both full and empty methods!!\n";
            break;
        }
    }


    return 0;
}

void solve(){
    ll sum = 0;
    string input;

    while(true){
        string input;
        getline(cin, input);
        if(input.empty()) break;
        machine m = process_input(input);
        output_machine(m);
        int x = solve_machine(m);
        sum += x;
        cout<<x<<" was added to sum!\n";
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
