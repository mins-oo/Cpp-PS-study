/*2156
n개의 포도주가 일렬로 있어 규칙대로 마셔야 함
1. 선택한 잔은 다 마셔야 하고 원래 위치로 복귀
2. 연속으로 놓인 3잔을 모두 마실 수는 없음

6개의 포도주 {6, 10, 13, 9, 8, 1}일 때, 1, 2, 4, 5 잔을 선택하면 총 33으로 최대

input 포도주 잔의 개수 n (1 <= n <= 10,000) 입력
	  잔에 들어있는 포도주의 양(<= 1,000) 입력
output 최대로 마실 수 있는 포도주의 양 출력

case 1 [6 6 10 13 9 8 1] [33]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
	  
vector<int> g;
//int cache[10000] = {0, }; 배열을 0으로 초기화하여 사용하면 포도주의 양이 0인 경우 타임아웃
//벡터를 -1로 초기화하여 하는 것으로 변경
vector<int> cache(10000, -1);

int maxg(int n){
	if(n > g.size()) return 0;

	int &ret = cache[n];
	if(ret != -1) return ret;
	
	ret = max(g[n] + g[n+1] + maxg(n+3), g[n] + maxg(n+2));
	return ret = max(ret, maxg(n+1));
}  
	  	  
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, tmp;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> tmp;
		g.push_back(tmp);
	}
	
	cout << maxg(0);
	
	return 0;
}
