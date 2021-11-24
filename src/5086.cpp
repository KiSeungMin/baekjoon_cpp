#include<iostream>
#include<vector>
using namespace std;

int main(){

    int num1, num2;

    cin>>num1>>num2;

    while(num1 !=0 || num2!=0){

        if(num1 / num2 >=1  && num1 % num2 ==0){
            cout<<"multiple"<<endl;
        }

        else if(num2 / num1 >=1 && num2 % num1 ==0){
            cout<<"factor"<<endl;
        }

        else{
            cout<<"neither"<<endl;
        }

        cin>>num1>>num2;

    }

    return 0;
}