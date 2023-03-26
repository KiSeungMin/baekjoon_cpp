#include<iostream>
#include<vector>
using namespace std;

int getGCD(int num1, int num2){

    if(num1 % num2 == 0){
        return num2;
    }

    else{
        return getGCD(num2, num1 % num2);
    }
}

int getNum(int num1, int num2){

}

int main(){

    vector<int>arr;
    for(int i{0}; i < 5; i++){
        int num; cin >> num;
        arr.push_back(num);
    }

    return 0;
}