#include<iostream>
#include<vector>
#include<string>
using namespace std;

int LIMIT;
vector<bool> is_number_hansu;

void check_hansu(int num){

    if(num < 10)
        return;

    string num_to_str = to_string(num);
    int gap = num_to_str[0] - num_to_str[1];
    
    for(size_t i{0}; i < num_to_str.length() - 1; i++){
        
        int gap_now = (num_to_str[i] - '0') - (num_to_str[i + 1] - '0');

        if(gap != gap_now){
            is_number_hansu[num] = false;
            return;
        }
    }
}

void printAnswer(){

    int answer = 0;

    for(int i{1}; i <= LIMIT; i++){
        if(is_number_hansu[i])
            answer++;
    }

    cout<<answer<<"\n";
}

int main(){

    cin>>LIMIT;

    for(int i{0}; i < LIMIT + 1; i++)
        is_number_hansu.push_back(true);

    for(int i{1}; i <= LIMIT; i++)
        check_hansu(i);

    printAnswer();

    return 0;
}