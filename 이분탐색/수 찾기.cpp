/*수 찾기
N개의 정수 A[1], A[2], ..., A[N]이 있을 때, X라는 정수가 있는지 확인

input 자연수 N 입력 (1 <= N <= 100,000). N개의 정수 A[1], A[2], ..., A[N] 입력
	  M 입력 (1 <= N <= 100,000). M개의 수들이 A안에 존재하는지 (-2^31 <= A < 2^31)
output M개의 답을 출력. 존재하면 1을, 존재하지 않으면 0 출력

case 1 [5 4 1 5 2 3 5 1 3 7 9 5] [1 1 0 0 1]
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, tmp;

	cin >> N;
	int A[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	sort(A, A + N);
	
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> tmp;
		cout << binary_search(A, A + N, tmp) << '\n';
	}
	
	return 0;
}

/*재귀는 시간초과
int Binary_search(int target, int beg, int end){
	if(beg > end)	return 0;
	
	int mid = (beg + end) / 2;
	
	if(target == A[mid])	return 1;
	
	if(target < A[mid])	return Binary_search(target, beg, mid - 1);
	else	return Binary_search(target, mid + 1, end);
}
*/
