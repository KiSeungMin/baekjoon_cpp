#include<iostream>
#include<vector>
using namespace std;

vector<long long>arrFive(20, 1);
vector<long long>arrTwo(50, 1);

int getFive(long long a);
int getTwo(long long a);

// answer : (n!)/ ( (n-m)! * (m)! )의 2의 개수와 5의 개수 둘 중 더 작은 값

int main(){

    int N, M;
    cin>>N>>M;
    
    for(int i{1}; i < 20; i++){
        arrFive[i]=arrFive[i-1]*5;

        if(arrFive[i] < 0 || arrFive[i] % 5 != 0){
            arrFive[i]=1;
            break;
        }
    }

    for(int i{1}; i <50; i++){
        arrTwo[i] = arrTwo[i-1] * 2;
        if(arrTwo[i] < 0 || arrTwo[i] % 2 !=0){
            arrTwo[i]=1;
            break;
        }
    }

    int answer1=getFive(N)-(getFive(N-M) + getFive(M));
    int answer2=getTwo(N)-(getTwo(N-M) + getTwo(M));

    if(answer1 > answer2){
        cout<<answer2<<endl;
        return 0;
    }

    cout<<answer1<<endl;
    return 0;
}

int getFive(long long a){

    int result=0;

    for(int i{0}; i <arrFive.size(); i++ ){

        if(arrFive[i] > 1){
            result = result + (a/arrFive[i]) ;
        }
    }
    return result;
}

int getTwo(long long a){

    int result=0;

    for(int i{0}; i<arrTwo.size(); i++){

        if(arrTwo[i] > 1){
            result=result + (a/arrTwo[i]);
        }
    }

    return result;
}