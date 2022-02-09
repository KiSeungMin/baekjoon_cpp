#include<iostream>
#include<string>
using namespace std;

int main(){
	
	int x = 0;
	
	x |= (1<<1);
	x |= (1<<3);
	x |= (1<<4);
	x |= (1<<8);

	/*
	for(int i{0}; i < 32; i++){
		if(x & (1<<i))
			cout<<i<<" ";
	}
	*/

	/*
	int y = 0;
	y |= (0 << 20);
	y = y | (1 << 1);

	cout<<y<<" ";

	int bitSet = 0;
	bitSet |= (1 << 21);
	cout<<bitSet<<"\n";
	bitSet &= bitSet - 1;
	cout<<bitSet<<"\n";
	*/

	int bitMask = 1 << 1;
	for(int i{0}; i < 10; i++){

		int tmp = bitMask || (1 << i);
		cout<<tmp<<"\n";
	}

	int b1 = (0 << 3);
	int b2 = (1 << 3);
	
	int b3 = b1 | b2;
	cout<<b3<<"\n";
	int tmp2 = (0 << 3 ) || (1<<3);
	cout<<tmp2<<"\n";
	
	return 0;
}
