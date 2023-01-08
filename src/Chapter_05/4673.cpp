#include<iostream>
#include<string>
using namespace std;

const int LIMIT = 10000;
bool is_self_number[LIMIT];

void self(int num){

    string num_to_str = to_string(num);

    for(size_t i{0}; i < num_to_str.length(); i++){
        num += num_to_str[i] - '0';
    }

    if(num < LIMIT)
        is_self_number[num] = false;
}

void printAnswer(){
    for(int i{1}; i < LIMIT; i++){

        if(is_self_number[i])
            cout<<i<<"\n";
    }
}

int main(){

    for(int i{1}; i < LIMIT; i++)
        is_self_number[i] = true;

    for(int i{1}; i < LIMIT; i++)
        self(i);

    printAnswer();

    return 0;
}