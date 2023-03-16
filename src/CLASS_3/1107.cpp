#include<iostream>
#include<vector>
using namespace std;

int answer;
int goal;
vector<int>possibles;

void getMax(string& str){

    int str_to_int = stoi(str);
    string int_to_str = to_string(str_to_int);

    int result = int_to_str.length() + abs(goal - str_to_int);

    if(result < answer){
        answer = result;
    }

    if(str.length() < 6){
        for(int i{0}; i < possibles.size(); i++){
            string copy_str = str;
            copy_str.append(to_string(possibles[i]));

            getMax(copy_str);
        }
    }
}

int main(){

    cin >> goal;
    int impossible; cin >> impossible;

    vector<int>impossibles;
    for(int i{0}; i < impossible; i++){
        int num; cin >> num;
        impossibles.push_back(num);
    }

    for(int i{0}; i < 10; i++){
        bool flag = true;
        for(int j{0}; j < impossibles.size(); j++){
            if(i == impossibles[j]){
                flag = false;
                break;
            }
        }

        if(flag)
            possibles.push_back(i);
    }

    answer = abs(goal - 100);

    string str = "";
    for(int i{0}; i < possibles.size(); i++){
        string copy_str = str;
        copy_str.append(to_string(possibles[i]));

        getMax(copy_str);
    }
    cout<<answer<<"\n";

    return 0;
}