/*랜선 자르기
오영식은 K개의 랜선이 있으나 길이가 전부 제각각이라, 잘라서 모두 길이가 같은 N개의 랜선을 만들어야 함
300cm 랜선에서 140cm 랜선을 두 개 잘라내면 20cm는 버림
N개보다 많이 만드는 것도 괜찮음
만들 수 있는 최대 랜선의 길이를 구하라

input 가지고 있는 랜선의 개수 K, 필요한 랜선의 개수 N 입력
	  1 <= K <= 10,000, 1 <= N <= 1,000,000, K <= N
	  K개의 랜선 길이 cm단위의 정수 입력 (<= 2^31 - 1)
output N개를 만들 수 있는 랜선의 최대 길이 출력

case 1 [4 11 802 743 457 539] [200]
*/

#include <iostream>
#include <vector>

using namespace std;

int K, N;
long long tmp, maxLen = 0, ret = 0;
vector<long long> line;

int cutting(long long len){
	int cnt = 0;
	for(int i = 0; i < K; i++){
		cnt += line[i] / len;
	}
	
	return cnt;
}

void binary_search(long long beg, long long end){
	if(beg > end){
		cout << ret;
		return;
	}
	
	long long mid = (beg + end) / 2;	//mid 401

	if(cutting(mid) >= N){
		if(mid > ret)	ret = mid;
		binary_search(mid + 1, end);
	}
	else binary_search(beg, mid - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N;	//K 4, N 11
	for(int i = 0; i < K; i++){
		cin >> tmp;
		line.push_back(tmp);
		
		if(tmp > maxLen)	maxLen = tmp;
	}
	//line[0] 802, line[1] 743, line[2] 457, line[3] 539
	
	binary_search(1, maxLen);	//beg 1, end 802
	
	return 0;
}
