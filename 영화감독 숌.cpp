//영화감독 숌
//종말의 수란 6이 적어도 3개 이상 연속되는 수
//제일 작은 종말의 수는 666, 그 다음은 1666, 2666, 3666, …
//숌이 만든 N번째 영화의 제목에 들어간 수를 구하라

//input N 입력(N <= 10,000)
//output N번째 영화의 제목에 들어간 수 출력

//case 1: [2] [1666]		case 2: [3] [2666]		case 3: [6] [5666]
//case 4: [187] [66666]		case 5: [500] [166699]

#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, num = 665, cnt = 0, check;
	string numChar;
	
	cin >> N;
	
	while(cnt < N){
		num++;
		check = 0;
		
		numChar = to_string(num);
		
		for(char c : numChar){
			if(c == '6')
				check++;
			else
				check = 0;
			
			if(check >= 3){
				cnt++;
				break;
			}
		}
	}
	
	cout << num << endl;
	
	return 0;
}
