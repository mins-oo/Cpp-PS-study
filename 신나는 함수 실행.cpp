/*9184
재귀함수 w(a, b, c){
	if(a<=0 || b<=0 || c<=0) return 1;
	
	if(a>20 || b>20 || c>20) return w(20, 20, 20);
	
	if(a<b && b<c) return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	
	return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b-1, c-1);
}
를 구현하면 값을 구하는데 매우 오랜 시간이 걸림

input 세 정수 a, b, c 입력 ('-1 -1 -1'로 입력의 끝, -50 <= a,b,c <= 50)
output 각 w(a, b, c)의 값을 출력

case 1
[1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1]

[w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1]
*/

#include <iostream>

using namespace std;

int cache[101][101][101] = {0, };
const int d = 50;

int w(int a, int b, int c){
	int &ret = cache[a+d][b+d][c+d];
	if(ret != 0) return ret;
	
	if(a<=0 || b<=0 || c<=0) return ret = 1;
	
	if(a>20 || b>20 || c>20) return ret = w(20, 20, 20);
	
	if(a<b && b<c) return ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	
	return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c;
	
	while(true){
		cin >> a >> b >> c;
		
		if(a==-1 && b==-1 && c==-1) break;
		
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
	
	return 0;
}
