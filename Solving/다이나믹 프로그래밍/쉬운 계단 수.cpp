/*10844
인접한 모든 자리의 차이가 1인 수를 계단 수
N이 주어질 때 길이가 N인 계단 수가 몇개 있는지

input N (1 <= N <= 100)
output 답을 1,000,000,000으로 나눈 나머지

case 1 [1] [9]
case 2 [2] [17]
*/

#include <iostream>

using namespace std;

long long cache[10][100] = {0, };

long long stair(int n, int len){
	long long &ret = cache[n][len];
	if(ret != 0) return ret;
	
	if(len <= 0) return ret = 1;

	if(n < 9) ret += stair(n + 1, len - 1);
	if(n > 0) ret += stair(n - 1, len - 1);
	
	return ret = ret % 1000000000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, cnt = 0;
	cin >> N;
	
	for(int i = 1; i < 10; i++){
		cnt += stair(i, N - 1);
		cnt %= 1000000000;
	}
	
	cout << cnt;
	
	return 0;
}
