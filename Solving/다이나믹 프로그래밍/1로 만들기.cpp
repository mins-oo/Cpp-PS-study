/*1463
정수 N에 대해
1. 3으로 나눠지면 /3
2. 2로 나눠지면 /2
3. 안 되면 -1을 하여
1을 만드는데 필요한 연산 횟수의 최솟값을 구하라

input 정수 N (1 <= N <= 1,000,000) 입력
output 연산 횟수의 최솟값 출력

case 1 [2] [1]
case 2 [10] [3]
*/

#include <iostream>
#include <algorithm>

using namespace std;

int cache[1000000] = {0, 1, 1, 2, 0, };

int cal(int n){
	int &ret = cache[n-1];
	if(ret != 0) return ret;
	
	if(n == 1) return 0;
	
	ret = cal(n - 1);
	if(n % 3 == 0) ret = min(ret, cal(n / 3));
	if(n % 2 == 0) ret = min(ret, cal(n / 2));

	return ret = ret + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	cout << cal(N);
	
	return 0;
}
