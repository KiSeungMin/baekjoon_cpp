#include<iostream>
#include<string>
#define sync_with_stdio(false)
using namespace std;

void logic(){
    int cycle;
    string input_str;

    cin>>cycle>>input_str;

    for(size_t i{0}; i < input_str.length(); i++){
        for(int j{0}; j < cycle; j++){
            cout<<input_str[i];
        }
    }
}

int main(){

    cin.tie(NULL);

    int T;
    cin>>T;
    
    for(int t{0}; t < T; t++){
        logic();
        cout<<"\n";
    }

    return 0;
}