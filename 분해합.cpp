//분해합
//자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합. 자연수 M의 분해합이 N인 경우 M을 N의 생성자
//245의 분해합은 256(=245+2+4+5), 245는 생성자 M
//자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램

//input 자연수 N(1 <= N <= 1,000,000)
//output 생성자를 출력. 없으면 0 출력

//case 1: [216] [198]

#include <iostream>

using namespace std;

int Func(int M){
	int tmp = 10;
	
	while(M % tmp != M){
		tmp = tmp * 10;
	}
	
	tmp = tmp / 10;

	return tmp;
}

int main() {
	int N, tmp, cons, sum, min = 9999999;

	cin >> N;
	
	for(int M = 1; M < N; M++){
		sum = 0;
		cons = Func(M);
		tmp = M;
		
		while(cons >= 1){
			sum += tmp / cons;
			tmp = tmp % cons;
			cons = cons / 10;
		}
		
		if(M + sum == N && M < min)
			min = M;
	}
	
	if(min == 9999999)
		min = 0;
	
	cout << min << endl;
	
	return 0;
}
