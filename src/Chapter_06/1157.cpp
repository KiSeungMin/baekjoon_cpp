#include<iostream>
#include<string>
using namespace std;

string input_str;
int max_count = 0;
const int LIMIT = 26;
int count_alphabet[LIMIT];

void init(){

    cin>>input_str;

    for(int i{0}; i < LIMIT; i++)
        count_alphabet[i] = 0;
}

void logic(){

    for(size_t i{0}; i < input_str.length(); i++){

        int index;
        if(input_str[i] - 'a' >= 0)
            index = input_str[i] - 'a';
        else
            index = input_str[i] - 'A';

        count_alphabet[index]++;

        if(count_alphabet[index] > max_count)
            max_count = count_alphabet[index];
    }
}

void printAnswer(){

    char answer = '.';

    for(int i{0}; i < LIMIT; i++){
        if(count_alphabet[i] == max_count){
            if(answer == '.')
                answer = i + 65;

            else{
                answer = '?';
                break;
            }
        }
    }

    cout<<answer<<"\n";
}

int main(){

    init();

    logic();

    printAnswer();

    return 0;
}