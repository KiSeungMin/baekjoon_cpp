#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int main(){
	
	cout.tie(NULL);
	cin.tie(NULL);
	
	int max, length;
	cin>>max>>length;
	
	vector<int>result;
	for(int i{0}; i<length; i++)
		result.push_back(i+1);
	
	vector<int>canuse;
	for(int i{0}; i< length-1; i++)
		canuse.push_back(0);
	
	for(int i{result[result.size()-1]}; i<=max; i++)
		canuse.push_back(i);
	
	while(true){
		
		unsigned long int resultEnd=result.size()-1;
		
		bool end=true;
		for(int i{0}; i <= resultEnd; i++){
			cout<<result[i]<<" ";
			
			if(result[0] != max || (i !=0 && result[i-1] != result[i]+1)) 
			{
				end=false;
			}
		}
		cout<<"\n";
		
		if(end==true)
			break;
		
		int canuseMax=0;
		for(size_t i{canuse.size()-1}; i>=0; i--){
			if(canuse[i]>canuseMax){
				canuseMax=canuse[i];
				break;
			}
		}
		
		if(result[resultEnd] >= canuseMax || result[resultEnd] + 1 > max)
		{
			unsigned long int i = resultEnd;
			while(i>=1 && (result[i] >= canuseMax || result[i] + 1 >max))
				i--;
			
			for(int j{0}; j<max; j++){
				canuse[j]=j+1;
			}
			
			if(i==0){
				if(result[i]==max){
					result[0]=max;
					canuse[max-1]=0;
					
					i++;
					for(i; i<resultEnd; i++){
						for(int k{0}; k<canuse.size(); k++){
							if(canuse[k] > result[i]){
								result[i]=canuse[k];
								canuse[k]=0;
								break;
							}						
						}
					}			
				}
				else{
					for(int k{0}; k<canuse.size(); k++){
						if(canuse[k] > result[i]){
							result[i]=canuse[k];
							canuse[k]=0;
							break;
						}
					}					
				}
			}
			
			else{
				for(int j{0}; j<i; j++){
					for(int k{0}; k<canuse.size(); k++){
						if(result[j]==canuse[k]){
							canuse[k]=0;
							break;
						}
					}
				}
				for(int k{0}; k<canuse.size(); k++){
					if(canuse[k] > result[i]){
						result[i]=canuse[k];
						canuse[k]=0;
						break;
					}
				}
			}
			i++;
	
			for(unsigned long int j{i}; j < resultEnd; j++){
				for(int k{0}; k<canuse.size(); k++){
					if(canuse[k] > 0){
						result[j]=canuse[k];
						canuse[k]=0;
						break;
					}
				}
			}
			
			for(int j{0}; j<canuse.size(); j++){
				if(canuse[j] > 0){
					result[resultEnd]=canuse[j];
					break;
				}
			}
			continue;
		}
		
		else{
			for(int i{0}; i<canuse.size(); i++){
				if(canuse[i] > result[resultEnd])
				{
					result[resultEnd]=canuse[i];
					break;
				}
			}
		}
	}
	
	return 0;
}