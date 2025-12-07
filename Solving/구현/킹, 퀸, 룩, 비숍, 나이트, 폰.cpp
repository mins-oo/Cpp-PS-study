/*3003
체스의 검정색 피스는 모두 있었으나 흰색 피스는 개수가 올바르지 않았다
체스 피스는 총 16개. 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
각 흰색 피스들의 수가 주어졌을 때, 몇 개를 더하고 빼야하는가

input 퀸, 퀸, 룩, 비숍, 나이트, 폰의 개수 입력 (1 <= N <= 10)
output 입력 순서대로 몇 개의 피스를 더하거나 빼야하는지 출력

case 1: [0 1 2 2 2 7] [1 0 0 0 0 1]
case 2: [2 1 2 1 2 1] [-1 0 0 1 0 7]
*/

#include <iostream>
#include <vector>

using namespace std;

const vector<int> compValue = {1, 1, 2, 2, 2, 8};

int main() {
	vector<int> inputValue;
	int tmp;
	
	for(int i = 0; i < 6; i++){
		cin >> tmp;
		inputValue.push_back(tmp);
	}
	
	for(int i = 0; i < 6; i++){
		cout << compValue[i] - inputValue[i] << " ";
	}
	
	return 0;
}
