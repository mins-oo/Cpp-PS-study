/*가장 긴 증가하는 부분 수열 2
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하라
ex) A = {10, 20, 10, 30, 20, 50}
	가장 긴 증가하는 부분 수열은 10, 20, 30, 50. 길이는 4

input 수열 A의 크기 N (1 <= N <= 1,000,000) 입력. Ai (1 <= Ai <= 1,000,000)들 입력
output 가장 긴 증가하는 부분 수열의 길이 출력

case 1 [6 10 20 10 30 20 50] [4]
*/

#include <iostream>
#include <vector>
	
using namespace std;

int N;
vector<int> A, pA;

int binary_search(int target, int beg, int end){
	while(beg < end){
		int mid = (beg + end) / 2;
		
		if(pA[mid] < target) beg = mid + 1;
		else end = mid;
	}
	
	return end;
}	
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tmp, cnt = 0;
	
	cin >> N;	//수열 A 입력
	for(int i = 0; i < N; i++){
		cin >> tmp;
		A.push_back(tmp);
	}
	
	pA.push_back(A[0]);
	for(int i = 0; i < N; i++){
		if(pA[cnt] < A[i]){
			pA.push_back(A[i]);
			cnt++;
		}
		else{
			int index = binary_search(A[i], 0, cnt);
			pA[index] = A[i];
		}
	}
	
	cout << cnt + 1;
	
	return 0;
}
