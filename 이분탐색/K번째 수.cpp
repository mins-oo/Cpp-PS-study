/*K번째 수
NxN인 배열 A, 들어있는 수 A[i][j] = ixj. 이 수를 일차원 배열 B에 넣으면 B의 크기는 NxN
B를 오름차순으로 정렬했을 때, B[k]를 구하라. A, B의 인덱스는 1부터 시작

input N (N <= 10^5, 자연수), k (k <= min(10^9, N^2), 자연수) 입력
output B[k] 출력

case 1 [3 7] [6]
*/

#include <iostream>
#include <vector>

using namespace std;

int N, k;

void binary_search(int beg, int end){
	if(beg >= end){
		cout << end;
		return;
	}
	
	//mid = 5 | 7
	int mid = (beg + end) / 2, cnt = 0;
	
	for(int i = 1; i <= N; i++){
		if((mid / i) < N)	cnt += mid / i;	//cnt = 0 + 1 + 2 = 3 | 0 + 1 + 1 = 2
		else cnt += N;
	}
	
	if(cnt < k)	binary_search(mid + 1, end);	//5, 9
	else binary_search(beg, mid);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> k;	//3 7, 1 2 2 3 3 4 (6) 6 9
	
	binary_search(1, k);
	
	return 0;
}
