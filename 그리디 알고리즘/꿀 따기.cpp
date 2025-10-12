/*21758
N개의 장소 중, 두 곳은 벌, 한 곳은 벌통	(9) (9) 4 1 4 9 [9]
벌은 벌통으로 똑바로 날아가면서 지나가는 칸에서 꿀을 딴다 (벌이 시작한 장소 제외)
숫자는 꿀을 딸 수 있는 양을 의미	2*(4+1+4+9+9) = 54
가능한 최대의 꿀의 양을 계산

input 장소의 수 N 입력 (3 <= N <= 100,000)
	  각 장소마다 꿀을 딸 수 있는 양 입력 (1이상 10,000이하의 정수)
output 가능한 최대의 꿀의 양 출력

sub task N <= 20
		 N <= 500
		 N <= 5,000

case 1 [7 9 9 4 1 4 9 9] [57]
case 2 [7 4 4 9 1 9 4 4] [54]
case 3 [3 2 5 4] [10]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, tmp, maxSum = 0;
	vector<int> honey, sum;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> tmp;
		honey.push_back(tmp);
		i == 0 ? sum.push_back(tmp) : sum.push_back(sum[i-1] + tmp);
	}
	
	//case1 : bee1 => hive => bee2
	for(int i = 1; i < N - 1; i++){
		tmp = (sum[i] - honey[0]) + (sum[N-2] - sum[i-1]);
		maxSum = max(tmp, maxSum);
	}
	
	//case2 : bee1 => bee2 => hive
	for(int i = 1; i < N - 1; i++){
		tmp = (sum[N-1] - honey[0] - honey[i]) + (sum[N-1] - sum[i]);
		maxSum = max(tmp, maxSum);
	}
	
	//case3 : hive => bee1 => bee2
	for(int i = 1; i < N - 1; i++){
		tmp = sum[i-1] + (sum[N-2] - honey[i]);
		maxSum = max(tmp, maxSum);
	}
	
	cout << maxSum;
	
	return 0;
}
