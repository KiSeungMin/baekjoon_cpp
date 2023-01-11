#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

bool compare(pair<pair<int, int>, string>& value1, pair<pair<int, int>, string>& value2){

    int age1 = value1.first.first;
    int entry1 = value1.first.second;

    int age2 = value2.first.first;
    int entry2  = value2.first.second;

    if(age1 == age2)
        return entry1 < entry2;

    else
        return age1 < age2;
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<pair<int, int>, string>>input_arr;

    for(int i{0}; i < N; i++){
        
        pair<int, int> age_entry;
        cin>>age_entry.first;
        age_entry.second  = i;

        string name;
        cin>>name;

        pair<pair<int, int>, string> input_value = {age_entry, name};

        input_arr.push_back(input_value);
    }

    sort(input_arr.begin(), input_arr.end(), compare);

    for(int i{0}; i < N; i++){

        int age = input_arr[i].first.first;
        string name = input_arr[i].second;

        cout<<age<<" "<<name<<"\n";
    }

    return 0;
}