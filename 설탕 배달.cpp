//설탕 배달
//상근이는 정확히 N kg의 설탕을 배달해야 한다. 설탕 봉지는 3kg과 5kg으로 포장되어있어
//배달할 때 최대한 적은 양의 봉지가 되도록 만들자

//input N 입력 (3 <= N <= 5000)
//output 봉지의 최솟값을 출력. 만약 정확하게 N kg을 만들 수 없다면 -1 출력

//case 1: [18] [4]		case 2: [4] [-1]		case 3: [6] [2]
//case 4: [9] [3]		case 5: [11] [3]

#include <iostream>

using namespace std;

int main() {
	int N, tmp, cnt = 0;
	
	cin >> N;
	tmp = N;
	
	//case 1 : divided as 5
	if(tmp % 5 == 0){
		cout << tmp / 5 << endl;
		return 0;
	}
	
	//case 2 : less 3
	while(tmp >= 3 && tmp % 5 != 0){
		cnt++;
		tmp -= 3;
	}
	while(tmp >= 5){
		cnt++;
		tmp -= 5;
	}
	
	if(tmp != 0)
		cnt = -1;
	
	cout << cnt << endl;
	
	return 0;
}
