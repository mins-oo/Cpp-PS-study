/*주유소
N개의 도시가 일직선 모양으로 평행하게 있다.
제일 왼쪽의 도시에서 제일 오른쪽의 도시로 이동하려는데 도시 사이의 거리는 다를 수 있음 (km 단위)
출발하기 전 주유소에서 기름을 넣고 출발해야 한다. 1km마다 1L의 기름을 사용함
도시마다 하나의 주유소가 있고, 리터당 가격이 다를 수 있다
(1L/$5) --2km-- (1L/$2) --3km-- (1L/$4) --1km-- (1L/$1)
1구역에서 2x5= $10, 2구역에서 4x2= $8, 최소 총 비용은 $18

input 도시의 개수 N 입력 (2 <= N <= 100,000). 도로의 길이 N-1개의 자연수로 입력
	  주유소의 리터당 가격 N개의 자연수로 입력. 총 거리와 가격은 1이상 1,000,000,000 이하의 자연수
output 표준 출력으로 제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소 비용 출력

sub task 1 [모든 주유소의 리터당 가격은 $1]
sub task 2 [2 <= N <= 1,000, 제일 왼쪽에서 제일 오른쪽까지의 거리와 가격은 최대 10,000]
sub task 3 [원래의 제약조건 이외에 아무 제약조건이 없다]

case 1 [4 2 3 1 5 2 4 1] [18]		case 2 [4 3 3 4 1 1 1 1] [10]
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	long long tmp, sum = 0;
	vector<long long> dis, cost;
	
	cin >> N;
	
	for(int i = 0; i < N - 1; i++){
		cin >> tmp;
		dis.push_back(tmp);
	}
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		cost.push_back(tmp);
	}
	
	for(int i = 0; i < N-1; i++){
		if(cost[i] < cost[i+1])
			cost[i+1] = cost[i];
		
		sum += cost[i] * dis[i];
	}
	
	cout << sum << endl;
	
	return 0;
}
