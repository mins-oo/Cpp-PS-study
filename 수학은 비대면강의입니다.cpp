//수학은 비대면강의입니다
//수현이의 버츄얼 선생님은 문자가 2개인 연립방정식을 해결하는 문제를 냈다
//각 -999 이상 999 이하의 정수만을 입력

//input 정수 a, b, c, d, e, f가 공백으로 구분되어 입력
//output 정답인 x와 y를 공백으로 구분하여 출력

//case 1: [1 3 -1 4 1 7] [2 -1]		case 2: [2 5 8 3 -4 -11] [-1 2]

#include <iostream>

using namespace std;

int main() {
	float a, b, c, d, e, f;
	float tmp, x, y;
	
	cin >> a >> b >> c >> d >> e >> f;
	if(a != 0 && d != 0){
		tmp = (float)a / d;
		y = (c - (f * tmp)) / (b - (e * tmp));
		x = (c - (b * y)) / a;
	}
	else if (a == 0){
		y = c / b;
		x = (f - (c * y)) / d;
	}
	else{
		y = f / e;
		x = (c - (b * y)) / a;
	}	
	
	cout << x << " " << y << endl;
	
	return 0;
}
