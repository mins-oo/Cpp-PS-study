//진법 변환 2
//10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성
//10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다
//이런 경우에는 다음과 같이 알파벳을 사용 A:10, B:11...F:15...Y:34, Z:35

//input N과 B(2<=B<=36), N은 10억보다 작거나 같은 자연수
//output 10진법 수 N을 B진법으로 출력

//case 1: [60466175 36] [ZZZZZ]

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N = 0, B = 0;
	vector<int> res;
	char tmp;
	cin >> N >> B;
	
	while(N >= B){
		res.push_back(N % B);
		N = N / B;
	}
	res.push_back(N);
	
	for(int i = res.size(); i > 0; i--){
		//translate integer to char (ascii value)
		if(res[i-1] >= 10)
			tmp = res[i-1] + 55;
		else
			tmp = res[i-1] + 48;
		
		cout << tmp;
	}
	return 0;
}
