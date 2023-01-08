#include<iostream>
#include<string>
#include<vector>
#define sync_with_stdio(NULL)
using namespace std;

bool checkGroupWord(string input_str);

int getAnswer(){

    int T;
    cin>>T;

    int result{0};
    for(int t{0}; t < T; t++){
        
        string input_str;
        cin>>input_str;

        bool is_group_word = checkGroupWord(input_str);
        result = is_group_word ? ++result : result;
    }

    return result;
}

bool checkGroupWord(string input_str){

    int alphabet_index_arr[26];
    
    for(int i{0}; i < 26; i++)
        alphabet_index_arr[i] = -2;

    for(int i{0}; i < static_cast<int>(input_str.length()); i++){

        int alphabet_index = input_str[i] - 'a';

        if(alphabet_index_arr[alphabet_index] == -2)
            alphabet_index_arr[alphabet_index] = i;

        else if(alphabet_index_arr[alphabet_index] == i - 1)
            alphabet_index_arr[alphabet_index] = i;
        
        else if(alphabet_index_arr[alphabet_index] >= 0 && alphabet_index_arr[alphabet_index] != i - 1)
            return false;
    }

    return true;
}

int main(){

    cin.tie(NULL);

    cout<<getAnswer()<<"\n";

    return 0;
}