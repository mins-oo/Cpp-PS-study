/*1149
1번 부터 N번까지의 집. 각 집은 빨강, 초록, 파랑으로 칠해야 함
규칙을 만족하면서 모든 집을 칠하는 최소 비용을 구하라

-1번 집은 2번 집과 색이 같지 않아야 함
-N번 집의 색은 N-1번 집의 색과 같지 않아야 함
-i(2 <= i <= N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 함

input 집의 수 N(2 <= N <= 1,000) 입력
	  N번 집의 빨강, 초록, 파랑으로 칠하는 비용 입력 (자연수, <= 1,000)
output 모든 집을 칠하는 비용의 최솟값을 출력

case 1 [3 26 40 83 49 60 57 13 89 99] [96]
case 2 [3 1 100 100 100 1 100 100 100 1] [3]
case 3 [3 1 100 100 100 100 100 1 100 100] [102]
case 4 [6 30 19 5 64 77 64 15 19 97 4 71 57 90 86 84 93 32 91] [208]
case 5 [8 71 39 44 32 83 55 51 37 63 89 29 100 83 58 11 65 13 15 47 25 29 60 66 19] [253]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cost;
int cache[3000] = {0, };

int paint(int c){
	int &ret = cache[c];
	if(ret != 0) return ret;
	
	//reached first house => end search
	if(c < 3) return ret = cost[c];
	
	//chose previous house cost nodes
	if(c % 3 == 0) return ret = cost[c] + min(paint(c - 2), paint(c - 1));
	if(c % 3 == 1) return ret = cost[c] + min(paint(c - 4), paint(c - 2));
	return ret = cost[c] + min(paint(c - 5), paint(c - 4));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, tmp;
	cin >> N;
	
	//input 3 cost of house in linear array
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 3; j++){
			cin >> tmp;
			cost.push_back(tmp);
		}
	}
	
	//start searching from last house`s each nodes
	int minCost = min(paint(N * 3 - 1), paint(N * 3 - 2));
	minCost = min(minCost, paint(N * 3 - 3));
	
	cout << minCost;
	
	return 0;
}
