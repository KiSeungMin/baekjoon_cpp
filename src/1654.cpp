
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int main(){

    long long n, a, b;
    vector<long long>v;

    cin>>n>>a;
    for(int i{0}; i < n; i++){
        cin>>b;
        v.push_back(b);
    }

    sort(v.begin(), v.end());

    long long l=1, r=v.at(n-1), m=(l+r)/2;
    long long rope=0;
    while(l <= r){
        for(int i{0}; i < n; i++){
            rope += v.at(i)/m;
        }

        if(rope >= a){
            l = m + 1;
            m = (r+l) /2;
        }

        else if(rope < a){
            r=m-1;
            m=(r+l)/2;
        }
        rope=0;
    }
    cout<<m;
}


/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

long long K;
vector<long long>arr;

bool getResult(long long num);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin>>N>>K;

    long long start=1;
    long long end=LONG_MAX-1;

    for(int i{0}; i < N; i++){
        long long num;
        cin>>num;

        arr.push_back(num);
    }

    long long answer=0;
    long long mid=0;

    if(arr.size() == 1){
        cout<<arr[0]<<"\n";
        return 0;
    }

    while(true){

        mid = (start + end)/2;

        if(getResult(mid)){

            if(getResult(mid + 1)){
                start=mid + 1;
                continue;
            }

            else{
                answer = mid;
                break;
            }
        }

        else{

            if(getResult(mid - 1) == false){
                end=mid - 1;
                continue;
            }

            else{
                answer = mid-1;
                break;
            }
        }
    }

    cout<<answer<<"\n";

    return 0;
}

bool getResult(long long num){

    if(num == 0)
        return false;

    long long result=0;

    for(int i{0}; i < arr.size(); i ++){
        result += arr[i] / num;
    }

    if(result >= K)
        return true;

    return false;
}
*/