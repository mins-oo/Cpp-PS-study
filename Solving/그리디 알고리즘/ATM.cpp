/*ATM
ATM 앞에 N명의 사람이 줄을 서있다.
사람은 1번부터 N번까지 번호가 매겨져 i번 사람이 돈을 인출하는데 걸리는 시간은 P(i)분
P(1) = 3, P(2) = 1, P(3) = 4, P(4) = 3, P(5) = 2인 경우
[1, 2, 3, 4, 5]순서로 줄을 선다면
1번 사람은 3분만에 돈을 뽑을 수 있음, 2번 사람은 3+1 = 4분, 3번 사람은 3+1+4 = 8분...필요
따라서 총 시간의 합은 3+4+8+11+13 = 39분 소요
[2, 5, 1, 4, 3]순서로 줄을 선다면
2번 사람은 1분, 5번 사람은 1+2 = 3분, 1번 사람은 1+2+3 = 6분...필요
따라서 총 시간의 합은 1+3+6+9+13 = 32분 소요 (최소 case)
줄을 서 있는 사람의 수 N과 각 사람이 걸리는 시간 P(i)가 주어졌을 때, 필요한 시간의 합의 최솟값

input N (1 <= N <= 1,000) 입력. 각 사람이 인출하는데 걸리는 시간 P(i) (1 <= P(i) <= 1,000) 입력
output 필요한 시간의 합의 최솟값 출력

case 1 [5 3 1 4 3 2] [32]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, tmp, sum = 0;
	vector<int> time;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		time.push_back(tmp);
	}
	
	sort(time.begin(), time.end());
	tmp = 0;
	for(int t : time){
		tmp += t;
		sum += tmp;
	}
	
	cout << sum << endl;
	
	return 0;
}
