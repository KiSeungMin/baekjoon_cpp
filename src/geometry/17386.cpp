#include <iostream> 
using namespace std;
struct Vector2{
    long long x; 
    long long y;
}; 

int ccw(Vector2 a, Vector2 b, Vector2 c);  

int main(){ 	
    ios_base :: sync_with_stdio(false); 	
    cin.tie(NULL); cout.tie(NULL); 
    Vector2 p1,p2,p3,p4; 	// L1 양 끝점 p1 , p2  	// L2 양 끄텀 p3 , p4  	
    cin >> p1.x >> p1.y >> p2.x >> p2.y; 	
    cin >> p3.x >> p3.y >> p4.x >> p4.y; 	 	// L1과 L2 선분이 교차 하는지 판별  

    // ccw 돌려서 L1 벡터와  p1p3 벡터 * L1 벡터와 p1p4 벡터 <=0  	
    // ccw 돌려서 L2 벡터와 p3p1 벡터 * L2 벡터와 p3p2 벡터 <= 0  	
    // 면 선분 교차. 	 	
    if(ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 && ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0){
        cout << 1;
    }
    else{
        cout << 0;
    } 	 	
    
    return 0;
}

int ccw(Vector2 a, Vector2 b, Vector2 c){  	
    long long crossProduct = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    
    if(crossProduct < 0){
        return -1; 	
    }
    else if(crossProduct > 0){ 		
        return 1; 	
    }
    else{ 		
        return 0; 	
    } 
}
  