#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long getAnswer(long long a, long long b);

int main(){

    int N;
    cin>>N;

    vector<long long>result;

    for(int i{0}; i < N; i++){

        long long num1, num2;
        cin>>num1>>num2;

        result.push_back(getAnswer(num1, num2));
    }

    for(auto v: result)
        cout<<v<<endl;

    return 0;
}

long long getAnswer(long long a, long long b){

    if(a > b){
        long long tmp=a;
        a=b;
        b=tmp;
    }

    if(a == 1){
        return a*b;
    }

    else if(a ==2 || b ==2){

        if(b % 2==0)
            return b;
        else
            return b*2;
    }

    else if(a==3 || b==3){
        if(b % 3 ==0)
            return b;
        else
            return b*3;
    }

    long long result=1;;

    for(long long i{2};  i <= a; i++){

        if(a % i ==0 && b % i ==0){

            while(a % i == 0 && b % i ==0){
                a=a/i;
                b=b/i;
                result*=i;
            }
        }
    }

    result=result*a*b;

    return result;
}