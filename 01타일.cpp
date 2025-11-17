/*1904
00과 1이 쓰여진 타일만 남아 크기가 N인 모든 2진 수열을 만들 수 없음
N=1{1}, N=2{00, 11}, N=4{0011, 0000, 1001, 1100, 1111}
N이 주어졌을 때 만들 수 있는 모든 가짓수

input N (1 <= N <= 1,000,000)
output 길이가 N인 2진 수열의 개수를 15746으로 나눈 나머지

case 1 [4] [5]
*/

#include <iostream>

using namespace std;

//overflow..
long long cache[1000001] = {0, 1, 2, 0, };

long long tile(int N){
	if(N <= 0) return 0;
	
	long long &ret = cache[N];
	if(ret != 0) return ret;
	
	return ret = (tile(N-2) + tile(N-1)) % 15746;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	
	cin >> N;
	cout << tile(N);
	
	return 0;
}
