#include<iostream>
using namespace std;

void getFourthPoint(int x1, int y1, int x2, int y2, int x3, int y3);

int main(){
	int x1, y1;
	cin >> x1 >> y1;
	int x2, y2;
	cin >> x2 >> y2;
	int x3, y3;
	cin >> x3 >> y3;

	getFourthPoint(x1, y1, x2, y2, x3, y3);

	return 0;
}

void getFourthPoint(int x1, int y1, int x2, int y2, int x3, int y3){
	int x4, y4;
	if (x1 == x2)
		x4 = x3;
	
	else if (x1 == x3)
		x4 = x2;
	
	else if (x2 == x3)
		x4 = x1;
	
	if (y1 == y2)
		y4 = y3;
	
	else if (y1 == y3)
		y4 = y2;
	
	else if (y2 == y3)
		y4 = y1;
	
	cout << x4 << " " << y4<<"\n";
}