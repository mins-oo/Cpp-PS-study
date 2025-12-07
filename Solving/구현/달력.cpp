/*20207
1 ~ 365일로 표현되는 달력에 계획을 표시
계획이 지워지는 것을 방지하기 위해 일정이 있는 날에 코팅지를 붙일 것
연속된 두 일자에 각각 일정이 1개 이상 있다면 이는 연속된 것
연속된 일정은 하나의 가장 작은 직사각형으로 코팅
일정은 시작일과 종료일을 포함
시작일이 앞선 일정부터 채워짐, 시작일이 같으면 기간이 긴 것을 먼저 채움
일정은 가능한 최 상단부터 배치

2  3  4  5  6  7  8  9 10 11 12		2  3  4  5  6  7  8  9 10 11 12
■ ■ ■ ■ ■ ■ □ □ □ ■ ■		▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ □ ▒ ▒
□ □ ■ ■ □ ■ ■ ■ □ □ ■		▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ □ ▒ ▒		3*8 + 2*2 = 28
□ □ □ ■ ■ □ □ □ □ □ □		▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ □ □ □

input 일정의 개수 N (1 <= N <= 1,000) 입력
	  N만큼 시작일 S와 종료일 E (1 <= S <= E <= 365) 입력
output 코팅지의 면적 출력

case 1 [7 2 4 4 5 5 6 5 7 7 9 11 12 12 12] [28]
case 2 [5 1 9 8 9 4 6 3 4 2 5] [36]
*/

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, S, E, cnt[365] = {0, }, sum = 0;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> S >> E;
		
		for(int j = S; j <= E; j++) cnt[j - 1]++;
	}
	
	for(int s = 0; s < 365; s++){
		if(cnt[s] != 0){
			int e = s, max = 0;
			
			for(; e < 365; e++){
				if(cnt[e] == 0) break;	//연속된 구간이 종료
				if(cnt[e] > max) max = cnt[e];	//최빈값
			}
			
			sum += (e - s) * max;	//연속된 구간의 길이(너비) * 최빈값(높이)
			s = e;
		}
	}
	
	cout << sum;
	
	return 0;
}


/*일정들을 기준에 따라 정렬하여 2차 벡터에 저장하고 싶었음. 도중에 다른 방안이 떠올라 기각
vector<pair<int, int>> schedule;

sort(schedule.begin(), schedule.end(), comp);	//기준(comp 참조)에 따라 정렬

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second > b.second;	//시작일이 같을 때, 기간이 더 긴 것
	else return a.first < b.first;	//시작일이 같지 않을 때, 시작일이 더 빠른 것
}
*/
