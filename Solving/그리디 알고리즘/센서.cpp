/*2212
고속도로 위에 N개의 센서 설치
센서들의 정보를 분석하는 집중국을 설치해야 하는데 최대 K개 가능
집중국은 센서 수신 가능 영역을 조절
모든 센서는 적어도 하나의 집중국과 연결되어야 하고 (중복 연결 가능?)
수신 가능 영역의 길이의 합을 최소화 (0 이상)

input 센서의 개수 N(1 <= N <= 10,000)
	  집중국의 개수 K(1 <= K <= 1,000)
	  N개의 센서의 각 정수 좌표 (-1,000,000 <= <= 1,000,000)
output 집중국의 수신 가능 영역의 길이의 합의 최솟값

case 1 [6 2 1 6 9 3 6 7] [5]
caee 2 [10 5 20 3 14 6 7 8 18 10 12 15] [7]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K, tmp;
	vector<int> pos, dis;
	
	cin >> N >> K;
	
	if(K >= N){
		cout << 0;
		return 0;
	}
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		pos.push_back(tmp);
	}
	
	if(pos.size() > 1){
		sort(pos.begin(), pos.end());		//센서의 좌표 위치순 정렬 : 1 3 6 6 7 9
		
		for(int i = 1; i < N; i++){
			dis.push_back(abs(pos[i] - pos[i-1]));
		}	//각 센서 사이의 거리 저장 : 2 3 0 1 2
		
		sort(dis.begin(), dis.end());	//거리의 크기 순 정렬 : 0 1 2 2 3
	}
	else dis.push_back(0);
	
	int sum = 0;
	for(int i = 0; i < dis.size() - (K-1); i++){	//가장 거리가 먼 경우 K-1개 제외
		sum += dis[i];
	}	//sum = 0 + 1 + 2 + 2 = 5
	
	cout << sum;
	
	return 0;
}
