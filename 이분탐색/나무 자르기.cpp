/*나무 자르기
상근이는 나무 Mm가 필요
목재절단기를 높이 H에서 사용하여 한 줄로 연속되있는 나무를 절단 (H는 0 또는 양의 정수)
높이가 H보다 높은 나무는 H에서 절단될 것이고, 낮은 나무는 절단되지 않을 것
H: 15, tree: 20 15 10 17 -> left: 15 15 10 15, get: 5 + 2 = 7
적어도 Mm의 나무(M보다 커도 됨)를 가져갈 수 있는 H의 최댓값을 구하라

input 나무의 수 N, 가져갈 나무의 길이 M 입력 (1 <= N <= 1,000,000, 1 <= M <= 2,000,000,000)
	  각 나무의 높이 입력 (<= 1,000,000,000)
output 적어도 Mm의 나무를 가져갈 수 있는 높이의 최댓값 출력

case 1 [4 7 20 15 10 17] [15]		case 2 [5 20 4 42 40 26 46] [36]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M, maxLen = 0;
vector<long long> LoT;	//Length of Tree

void binary_search(int beg, int end){
	if(beg > end){
		cout << maxLen;
		return;
	}
	
	int mid = (beg + end) / 2;	//mid 10
	long long sum = 0;
	
	for(int i = 0; i < N; i++){
		if(LoT[i] - mid >= 0)
			sum += LoT[i] - mid;	//sum 22
	}
	
	if(sum < M){
		binary_search(beg, mid - 1);
	}
	else{
		maxLen = mid;
		binary_search(mid + 1, end);
	}
}

int main() {
	long long tmp;
	
	cin >> N >> M;	//N 4, M 7
	for(int i = 0; i < N; i++){
		cin >> tmp;
		LoT.push_back(tmp);
	}
	//LoT 20 15 10 17
	
	sort(LoT.begin(), LoT.end());	//10 15 17 20
	
	binary_search(0, LoT[N - 1]);	//LoT[N - 1] 20
	
	return 0;
}
