#include<iostream>
#include<string>
using namespace std;

string input_str;
const int LIMIT = 26;
int alphabet_index[LIMIT];

void init(){

    for(int i{0}; i < LIMIT; i++)
        alphabet_index[i] = -1;

    cin>>input_str;
}

void getIndex(){

    for(int i{0}; i < input_str.length(); i++){

        int alphabet_to_num = input_str[i] - 'a';
        
        if(alphabet_index[alphabet_to_num] == -1)
            alphabet_index[alphabet_to_num] = i;
    }
}

void printAnswer(){
    for(auto i : alphabet_index){
        cout<<i<<" ";
    }
}

int main(){

    init();

    getIndex();

    printAnswer();
    
	return 0;
}