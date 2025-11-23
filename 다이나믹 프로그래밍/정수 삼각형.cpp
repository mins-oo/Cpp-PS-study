/*1932
        7
      3   8
    8   1   0
  2   7   4   4
4	5	2	6	5
크기가 5인 정수 삼각형. 맨 위층 7부터 수를 하나씩 골라 내려올 때 수들의 합이 최대가 되는 경로
선택은 현재 수에서 대각선 왼쪽 또는 대각선 오른쪽만 선택 가능
삼각형의 크기는 1이상 500이하, 각 수는 0이상 9999이하의 정수

input 삼각형의 크기 n (1 <= n <= 500) 입력
	  n줄의 정수 삼각형 입력
output 최대가 되는 수의 합 출력

case 1 [5 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5] [30]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cache[500] = {0, };
vector<int> tri;

int sum(int idx, int cnt){
	int &ret = cache[idx];
	if(ret != 0) return ret;
	
	if(cnt > n - 2) return ret = tri[idx];

	return ret = tri[idx] + max(sum(idx+1+cnt, cnt+1), sum(idx+2+cnt, cnt+1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tmp;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin >> tmp;
			tri.push_back(tmp);
		}
	}
	
	cout << sum(0, 0);
	
	return 0;
}
