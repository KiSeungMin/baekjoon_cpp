#include<iostream>
using namespace std;

int main(){

    int num1, num2, num3;
    cin>>num1>>num2>>num3;

    int result = 0;

    if(num1 == num2  && num1 == num3)
        result = 10000 + num1 * 1000;

    else if(num1 == num2 || num1 == num3)
        result = 1000 + num1 * 100;

    else if(num2 == num3)
        result = 1000 + num2 * 100;

    else{
        int max = num1;

        if(num2 > max)
            max = num2;

        if(num3 > max)
            max = num3;

        result = max * 100;
    }

    cout<<result<<"\n";

    return 0;
}