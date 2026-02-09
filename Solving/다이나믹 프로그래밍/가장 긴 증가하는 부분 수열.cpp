/*11053
수열 A에서 가장 긴 증가하는 부분 수열을 찾으시오
ex) A = {10, 20, 10, 30, 20, 50}
		 10  20      30      50  -> 길이 4

input 수열 A의 크기 N (1 <= N <= 1,000)
	  각 Ai (1 <= Ai <= 1,000) 입력
output 가장 긴 증가하는 부분 수열의 길이 출력

case 1 [6 10 20 10 30 20 50] [4]
*/

#include <iostream>
#include <algorithm>

using namespace std;
	  
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, A[1000] = {0, };
	int len[1000] = {0, };
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	len[N-1] = 1;
	
	for(int i = N-2; i >= 0; i--){
		for(int j = i+1; j < N; j++){
			if(A[j] > A[i]){
				if(len[j] != 0) len[i] = max(len[i], len[j]);
			}
		}
		len[i]++;
	}

	int maxLen = 0;
	for(int i = 0; i < N; i++){
		if(len[i] > maxLen) maxLen = len[i];
	}
	cout << maxLen;
	
	return 0;
}
