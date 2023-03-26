#include<iostream>
using namespace std;

int main(){

    int num1, num2, num3, num4, num5, num6;
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6;

    int vec1 = num3 - num1;
    int vec2 = num4 - num2;
    int vec3 = num5 - num3;
    int vec4 = num6 - num4;

    int result = (vec1 * vec4) - (vec2 * vec3);

    if(result == 0){
        cout<<0;
    }
    else if(result < 0){
        cout<<-1;
    }
    else{
        cout<<1;
    }
    cout<<endl;

    return 0;
}