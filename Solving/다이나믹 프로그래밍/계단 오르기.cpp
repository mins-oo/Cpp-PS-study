/*2579
계단을 오를때 각 계단마다 점수를 얻음. 이때 총 점수의 최댓값을 구하라
						__
					__	__
				__	__	__
			__	__	__	__
		__	__	__	__	__
	__	__	__	__	__	__
__	__	__	__	__	__	__
st	10	20	15	25	10	20

계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있음
연속된 세 계단을 모두 밟을 수 없음 (시작점 제외)
마지막 계단은 반드시 밟아야 함

input 계단의 개수 (<= 300. 자연수) 입력
	  제일 아래의 계단부터 순서대로 계단의 점수 (<= 10,000. 자연수) 입력
output 총 점수의 최댓값 출력

case 1 [6 10 20 15 25 10 20] [75]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stair;
int cache[301] = {0, };

int jump(int n){
	if(n <= 0) return 0;
	
	int &ret = cache[n];
	if(ret != 0) return ret;
	
	return ret = stair[n] + max(jump(n-2), jump(n-3) + stair[n-1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, tmp;
	cin >> N;
	
	stair.push_back(0);
	for(int i = 0; i < N; i++){
		cin >> tmp;
		stair.push_back(tmp);
	}
	
	cout << jump(N);
	
	return 0;
}