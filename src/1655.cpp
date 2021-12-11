#include<iostream>
#include<queue>
using namespace std;

int getMin(int a, int b){

    if(a > b)
        return b;

    return a;
}

int getMax(int a, int b){

    if(a > b)
        return a;
    
    return b;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    priority_queue<int, vector<int>, greater<int>> max;
    priority_queue<int> min;

    int mid = 0;
    cin>>mid;
    cout<<mid<<"\n";

    for(int i{1}; i < N; i++){

        int num;
        cin>>num;

        if(max.size() == 0 && min.size() == 0){

            max.push(getMax(num, mid));
            mid = getMin(num, mid);

            cout<<mid<<"\n";
            continue;
        }

        else if(min.size() == 0){

            if(num <= mid)
                min.push(num);

            else if(num > max.top()){
                min.push(mid);
                mid=max.top();
                max.pop();
                max.push(num);
            }

            else{
                min.push(mid);
                mid=num;
            }

            cout<<mid<<"\n";
            continue;
        }

        else{

            if(max.size() != min.size()){

                if(num <= mid)
                    min.push(num);

                else if(num > max.top()){

                    min.push(mid);
                    mid=max.top();
                    max.pop();
                    max.push(num);
                }

                else{

                    min.push(mid);
                    mid=num;
                }

                cout<<mid<<"\n";
                continue;
            }

            else if(max.size() == min.size()){

                if(num > max.top())
                    max.push(num);

                else if(num < min.top()){

                    min.push(num);
                    max.push(mid);
                    mid=min.top();
                    min.pop();
                }

                else{
                    
                    max.push(getMax(num, mid));
                    mid = getMin(num, mid);
                }
            }

            cout<<mid<<"\n";
        }   
    }

    return 0;
}