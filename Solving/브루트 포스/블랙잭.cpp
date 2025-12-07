//블랙잭
//카드의 합이 21을 넘지 않는 한도 내에서 합을 최대로 만드는 게임
//블랙잭의 고수 김정인은 새로운 규칙을 만들어 상근, 청명이와 게임을 하고자 한다
//각 카드에는 양의 정수가 써져있고 딜러는 N장의 카드가 숫자가 보이도록 놓는다
//그후 딜러는 숫자 M을 크게 외친다
//플레이어는 제한된 시간 내에 N장의 카드 중 3장의 카드를 뽑아야 한다
//M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하라

//input 카드의 개수 N(3 <= N <= 100)과 M(10 <= M <= 300,000) 입력, 각 카드에 쓰여진 숫자 입력
//output M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력

//case 1: [5 21 \n 5 6 7 8 9] [21]
//case 2: [10 500 \n 93 181 245 214 315 36 185 138 216 295] [497]

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, tmp, sum = 0, max = 0;
	vector<int> val;
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		val.push_back(tmp);
	}
	
	for(int i = 0; i < val.size() - 2; i++){
		sum += val[i];
		for(int j = i + 1; j < val.size() - 1; j++){
			sum += val[j];
			for(int k = j + 1; k < val.size(); k++){
				sum += val[k];
				if(sum <= M && sum > max)
					max = sum;
				sum -= val[k];
			}
			sum -= val[j];
		}
		sum -= val[i];
	}
	
	cout << max << endl;
	
	return 0;
}
