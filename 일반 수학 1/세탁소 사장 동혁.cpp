//세탁소 사장 동혁
//미국으로 유학간 동혁이는 세탁소를 운영하고 있다. 알바로 고등학생 리암을 채용
//리암은 거스름돈으로 $0.5를 줘야하는데 $5를 주는 등 자꾸 실수한다.
//거스름돈에 대해 리암이 줘야할 Quarter($0.25), Dime($0.10), Nickel($0.05), Penny($0.01)의
//최소 개수를 구하는 프로그램. 거스름돈은 항상 $5.00 이하.

//input 테스트 케이스 개수 T. 거스름돈 C. C의 단위는 센트 (1달러 = 100센트) (1<=C<=500)
//output 테스트 케이스마다 필요한 동전의 개수를 공백으로 구분

//case 1: [3 \n 124 \n 25 \n 194] [4 2 0 4 \n 1 0 0 0 \n 7 1 1 4]

#include <iostream>
#include <vector>

using namespace std;

const vector<int> COIN = {25, 10, 5, 1};

int main() {
	int T, tmp;
	vector<int> C;
	
	//input test case
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> tmp;
		C.push_back(tmp);
	}
	
	//calculate charge
	for(int i : C){
		for(int j = 0; j < 4; j++){
			if(i >= COIN[j]){
				cout << i / COIN[j] << " ";
				i = i % COIN[j];
			}
			else{
				cout << "0 ";
			}
		}
		cout << endl;
	}
	
	return 0;
}
