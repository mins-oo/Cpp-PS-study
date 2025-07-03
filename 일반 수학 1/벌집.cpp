//벌집
//육각형으로 이루어진 벌집. 중앙의 방 1부터 시작해서 이웃하는 방에 돌아가며 1씩 증가하는 번호가 주소
//숫자 N이 주어지면 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나가는지 계산
//(시작과 끝 포함) 13까지는 3개, 58까지는 5개

//input N을 입력 (1 <= N <= 1,000,000,000)
//output 입력으로 주어진 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나는지 출력

//case 1: [13] [3]

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	int sum = 2, ret = 1;
	
	cin >> N;
	
	//except
	if(N == 1){
		cout << 1;
		return 0;
	}
	
	//6n equally increase
	for( ; ; ret++){
		if(N < sum)
			break;
		
		sum += 6 * ret;
	}
	
	cout << ret;
	
	return 0;
}
