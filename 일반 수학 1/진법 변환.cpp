//진법 변환
//B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 출력하는 프로그램을 작성
//10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다
//이런 경우에는 다음과 같이 알파벳을 사용 A:10, B:11...F:15...Y:34, Z:35

//input N과 B(2<=B<=36), B진법 수 N을 10진법으로 바꾸면 10억보다 작거나 같다
//output B진법 수 N을 10진법으로 출력

//case 1: [ZZZZZ 36] [60466175]

#include <iostream>
#include <string>
using namespace std;

int squar(int B, int i){
	int ret = 1;	
	while(i > 0){
		ret = ret * B;
		i--;
	}
	return ret;
}

int main() {
	string N = "";
	int B = 0, sum = 0;
	int tmp = 0;
	cin >> N >> B;
	
	for(int i = 0; i < N.size(); i++){
		//translate char to integer (ascii value)
		if(N[i] >= 65)
			tmp = N[i] - 55;
		else
			tmp = N[i] - 48;
		
		//calculate squar value and sum
		sum += tmp * squar(B, N.size() - i - 1);
	}

	cout << sum << endl;
	return 0;
}
