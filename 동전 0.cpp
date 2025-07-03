/*동전 0
동전은 총 N종류. 동전을 적절히 사용하여 그 합이 K가 되는 동전 개수의 최솟값

input N, K 입력 (1 <= N <= 10, 1 <= K <= 100,000,000)
	  N개의 동전 A(i)가 오름차순으로 입력 (1 <= A(i) <= 1,000,000, A(1) = 1,
	  i >= 2인 경우 A(i)는 A(i-1)의 배수)
output K원을 만드는데 필요한 동전 개수의 최솟값 출력

case 1 [10 4200 1 5 10 50 100 500 1000 5000 10000 50000] [6]
case 2 [10 4790 1 5 10 50 100 500 1000 5000 10000 50000] [12]
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K, tmp, cnt = 0;
	vector<int> val;
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		val.push_back(tmp);
	}
	
	for(int i = val.size() - 1; i >= 0; i--){
		if(val[i] <= K){
			cnt += K / val[i];
			K = K % val[i];
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
