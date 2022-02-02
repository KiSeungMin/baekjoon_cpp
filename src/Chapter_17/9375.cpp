#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(){

    int T;
    cin>>T;

    map<string, int>arr;
    
    for(int i{0}; i <T; i++){

        map<string, int>arr;

        int N;
        cin>>N;

        int result=1;
        
        for(int j{0}; j < N; j++){
            string s1;
            string s2;
            cin>>s1>>s2;

            if(arr.find(s2) == arr.end()){
                arr.insert({s2, 1});
            }
            else{
                arr[s2]++;
            }
        }

        map<string , int>::iterator iter;

        for(iter=arr.begin(); iter != arr.end(); iter++){
            result *= (iter->second)+1;
        }

        result--;

        cout<<result<<endl;
    }

    return 0;
}