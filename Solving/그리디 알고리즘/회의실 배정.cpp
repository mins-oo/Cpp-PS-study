/*1931
한 개의 회의실을 사용하고자 하는 N개의 회의에 대하여 사용표를 제작
각 회의 I에 대해 시작 시간과 끝나는 시간이 주어짐. 회의의 시작 시간과 끝나는 시간이 같을 수도 있음
회의가 겹치지 않게 회의실을 사용할 수 있는 회의의 최대 개수

input N (1 <= N <= 100,000) 입력. N개의 각 회의 시작 시간과 끝나는 시간 입력 (<= (2^31)-1, = 0)
output 사용 가능한 회의의 최대 개수 출력

case 1 [11 1 4 3 5 0 6 5 7 3 8 5 9 6 10 8 11 8 12 2 13 12 14] [4]

hint (1,4), (5,7), (8,11), (12,14)를 이용
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, tmp1, tmp2;
	vector<pair<int, int>> time;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> tmp1 >> tmp2;
		time.push_back(make_pair(tmp2, tmp1));
	}
	
	sort(time.begin(), time.end());
	tmp1 = 0;
	tmp2 = 0;
	for(auto t : time){
		if(t.second >= tmp1){
			tmp2++;
			tmp1 = t.first;
		}
	}
	
	cout << tmp2 << endl;
	
	return 0;
}
