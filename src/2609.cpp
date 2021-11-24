#include<iostream>
#include<vector>
using namespace std;

int main(){

    int num1, num2;
    cin>>num1>>num2;

    int max=0;
    int min=0;

    for(int i{num1 * num2}; i >= 1; i--){

        if(i % num1 ==0 && i % num2 ==0){
            min=i;
        }

        if(num1 % i ==0 && num2 % i ==0){
            max=i;
            break;
        }
    }

    cout<<max<<"\n"<<min<<endl;

    return 0;
}