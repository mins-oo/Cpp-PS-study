//달팽이는 올라가고 싶다
//달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다
//낯에 A미터 오르지만, 밤에는 자느라 B미터 미끄러진다.
//나무 막대를 전부 오르기까지 며칠이 걸리는가.

//input A, B, V가 공백으로 구분되어 입력 (1 <= B < A <= V <= 1,000,000,000)
//output 며칠이 걸리는지 출력

//case 1: [2 1 5] [4]		case 2: [5 1 6] [2]		case 3: [100 99 100000000] [999999901]

#include <iostream>

using namespace std;

int main() {
	int A, B, V;
	int day = 0;
	
	cin >> A >> B >> V;
	
	day = (V - B) / (A - B);
	
	if((V - B) % (A - B) != 0)
		day++;

	cout << day << endl;
	
	return 0;
}
