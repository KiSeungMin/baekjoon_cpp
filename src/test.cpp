#include<iostream>
using namespace std;

int main(){

    int result = 1;
    for(int i{0}; i < 20; i++){
        result *= 2;
    }

    cout<<result<<endl;
}