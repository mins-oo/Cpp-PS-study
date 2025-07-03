/*공유기 설치
도현이의 집 N개가 수직선 위에 있음. 각 집의 좌표는 x1, ..., xN으로 같은 좌표를 가지는 일은 없음
집에 공유기 C개를 설치해서 최대한 많은 곳에서 와이파이를 사용하려 함
가장 인접한 두 공유기 사이의 거리를 최대가 되도록 하라

input 집의 개수 N (2 <= N <= 200,000), 공유기의 개수 C (2 <= C <= N) 입력
	  각 집의 좌표 xi (0 <= xi <= 1,000,000,000) 입력
output 가장 인접한 두 공유기 사이의 최대 거리 출력

case 1 [5 3 1 2 8 4 9] [3]

hint 공유기를 1, 4, 8 또는 1, 4, 9에 설치하면 인접한 공유기 사이의 거리는 3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, C;
	long long tmp;
	vector<long long> x;
	
	cin >> N >> C;	//N, C, 각 집의 좌표 입력
	for(int i = 0; i < N; i++){
		cin >> tmp;
		x.push_back(tmp);
	}
	
	sort(x.begin(), x.end());
	
	int beg = 1, end = x[N-1] + 1;
	
	for(int i = 0; i < 30; i++){
		int mid = (beg + end) / 2, pos1 = x[0], pos2, cnt = 1;
		for(int j = 1; j < N; j++){
			pos2 = x[j];
			int dis = pos2 - pos1;
			
			if(dis >= mid){
				cnt++;
				pos1 = pos2;
			}
		}
		if(cnt >= C)	beg = mid;
		else	end = mid;
	}
	
	cout << beg;
	
	return 0;
}

/*이분 탐색을 사용하지 않았다.. 애초에 틀림?
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, C;
	long long tmp;
	vector<long long> x, Cx;
	
	cin >> N >> C;	//N, C, 각 집의 좌표 입력
	for(int i = 0; i < N; i++){
		cin >> tmp;
		x.push_back(tmp);
	}
	
	sort(x.begin(), x.end());
	
	Cx.push_back(x[0]);	//시작 추가
	
	float K = (float)(x[0] + x[N-1]) / (C - 1);
	
	for(int i = 1; i < N - 1; i++){
		if(abs(x[i] - K) < abs(x[i+1] - K)){
			Cx.push_back(x[i]);
			K += (x[0] + x[N-1]) / (C - 1);
		}
	}
	
	Cx.push_back(x[N-1]);	//끝 추가
	
	tmp = x[N-1];
	for(int i = 0; i < Cx.size() - 1; i++){
		if(Cx[i+1]-Cx[i] < tmp)	tmp = Cx[i+1]-Cx[i];
	}
	
	cout << tmp;
	
	return 0;
}
*/
