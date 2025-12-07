/*1912
n개의 정수로 이루어진 수열에서 연속된 수를 선택해 가장 큰 합이 되는 경우를 구하라
수를 선택하지 않을 수는 없음
ex) 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 에서 가장 큰 합은 12+21=33

input n 입력 (1 <= n <= 100,000)
	  n개의 정수 수열 입력 (-1,000 <= <= 1,000)
output 가장 큰 합 출력

case 1 [10 10 -4 3 1 5 6 -35 12 21 -1] [33]
case 2 [10 2 1 -4 3 4 -4 6 5 -5 1] [14]
case 3 [5 -1 -2 -3 -4 -5] [-1]
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int tmp, curSum = 0, maxSum = -99999;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		curSum += tmp;
		maxSum = max(maxSum, curSum);
		
		if(curSum <= 0){
			curSum = 0;
			continue;
		}
	}
	
	cout << maxSum << endl;
	
	return 0;
}
