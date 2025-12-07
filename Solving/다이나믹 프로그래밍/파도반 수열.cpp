/*9461
변의 길이가 1인 정삼각형 옆에 정삼각형을 계속 추가할 것임
이때 나선에서 가장 긴 변의 길이 k인 정삼각형을 추가
파도반 수열 P(N)은 정삼각형의 변의 길이 {1, 1, 1, 2, 2, 3, 4, 5, 7, 9}

input 테스트 케이스의 개수 T 입력
	  N (1 <= N <= 100) 입력
output P(N) 출력

case 1 [2 6 12] [3 16]
*/

#include <iostream>

using namespace std;

//overflow..
long long cache[100] = {1, 1, 1, 2, 2, 0, };

long long P(int N){
	if(N <= 5) return cache[N-1];
	
	long long &ret = cache[N-1];
	if(ret != 0) return ret;
	
	return ret = P(N-5) + P(N-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, N;
	
	cin >> T;
	while(T-->0){
		cin >> N;
		cout << P(N) << "\n";
	}
	
	return 0;
}
