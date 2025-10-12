//분수찾기
//무한히 큰 배열에 다음과 같이 분수들이 적혀있다.
//이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> …과 같은
//지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
//X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성

//input X을 입력 (1 <= N <= 10,000,000)
//output 첫째 줄에 분수를 출력

//case 1: [1] [1/1]		case 2: [2] [1/2]		case 3: [3] [2/1]		case 4: [4] [3/1]
//case 5: [5] [2/2]		case 6: [6] [1/3]		case 7: [7] [1/4]		case 8: [8] [2/3]
//case 9: [9] [3/2]		case 10: [14] [2/4]

#include <iostream>

using namespace std;

int main() {
	int X;
	int top = 1, down = 1, max = 1;
	bool condition = true;
	cin >> X;
	
	for(int i = 0; i < X - 1; i++){
		if(condition){
			if(top == 1){
				down++;
				max++;
				condition = false;
			}
			else{
				down++;
				if(top > 1)
					top--;
			}
		}
		else{
			if(top < max){
				top++;
				if(down > 1)
					down--;
			}
			else{
				top++;
				max++;
				condition = true;
			}
		}
	}
	
	cout << top << "/" << down << endl;
	
	return 0;
}
