#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int N, goal;
int counter = 0;
vector<int>arr;
vector<int>tmp;

void merge(int start, int center, int end);

void merge_sort(int start, int end){
    if(start < end){
        int center = (start + end) / 2;
        merge_sort(start, center);
        merge_sort( center + 1, end);
        merge(start, center, end);
    }
}

void merge(int start, int center, int end){

    int i{start};
    int j{center + 1};
    int t{0};

    while(i <= center && j <= end){
        if(arr[i] <= arr[j]){
            tmp[t++] = arr[i++];
        } else{
            tmp[t++] = arr[j++];
        }
    }

    while(i <= center)
        tmp[t++] = arr[i++];
    
    while(j <= end)
        tmp[t++] = arr[j++];
        
    i = start;
    t = 0;

    while(i<= end){
        arr[i++] = tmp[t++];

        if(++counter == goal){
            cout<<arr[i - 1]<<"\n";
            return;
        }
    }
}

int main(){

    cin.tie(NULL);

    cin>>N>>goal;

    for(int i{0}; i < N; i++){
        int input_num;
        cin>>input_num;

        arr.push_back(input_num);
    }

    tmp = arr;

    merge_sort(0 , N - 1);

    if(counter < goal)
        cout<<-1<<"\n";

    return 0;
}