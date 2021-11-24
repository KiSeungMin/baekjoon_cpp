#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GCD(int a, int b);

int main(){

    int N;
    cin>>N;

    vector<int>arr;

    for(int i{0}; i < N; i++){
        int num;
        cin>>num;

        arr.push_back(num);
    }

    for(int i{1}; i < N; i++){

        int up=1;
        int down=1;
        int mod=1;
        mod=GCD(arr[0], arr[i]);

        up=arr[0]/mod;
        down=arr[i]/mod;

        cout<<up<<"/"<<down<<endl;
    }

    return 0;
}

int GCD(int a, int b){

    if(b==0)
        return a;

    else
        return GCD(b, a%b);    

}