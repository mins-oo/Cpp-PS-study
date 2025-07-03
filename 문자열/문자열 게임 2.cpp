/*문자열 게임 2
1. 알파벳 소문자로 이루어진 문자열 W가 주어짐
2. 양의 정수 K가 주어짐
3. 어떤 문자가 K개인 가장 짧은 연속 문자열의 길이를 구함
4. 어떤 문자가 K개고, 첫 번째와 마지막이 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구함
위 게임을 T회 진행

input 게임의 수 T (1 <= T <= 100) 입력
      다음 2개의 줄 동안 문자열 W와 정수 K 입력 (1 <= K <= |W| <= 10,000)
output T개의 줄 동안 게임 3번 4번 항목에서 구한 길이를 출력 (만족하는 문자열이 없을 시 -1 출력)

case 1 [2 superaquatornado 2 abcdefghijklmnopqrstuvwxyz 5] [4 8 -1]
첫 번째 게임 (3번) 어떤 문자가 2개인 가장 짧은 문자열은 aqua 4
			(4번) 어떤 문자가 2개이고 첫 번째와 마지막이 해당 문자로 같은 가장 긴 문자열은 raquator 8
두 번째 게임 어떤 문자가 5개인 문자열이 없으므로 -1

case 2 [1 abaaaba 3] [3 4]
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, K, max, min;
	string W;
	
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> W >> K;
		
		max = -1, min = 10001;
		vector<int> alp(26);

		for(int wIdx = 0; wIdx < W.size(); wIdx++){
			alp[W[wIdx] - 'a']++;	//W에 있는 알파벳의 개수 카운트
		}
		
		for(int wIdx = 0; wIdx < W.size(); wIdx++){
			if(alp[W[wIdx] - 'a'] < K) continue;	//알파벳의 개수가 K보다 적으면 넘어감
			
			int cnt = 0;
			for(int j = wIdx; j < W.size(); j++){
				if(W[wIdx] == W[j]) cnt++;
				
				if(cnt == K){
					if(j - wIdx + 1 > max) max = j - wIdx + 1;
					if(j - wIdx + 1 < min) min = j - wIdx + 1;
					break;
				}
			}
		}
		
		if(max == -1 && min == 10001) cout << -1 << "\n";
		else cout << min << " " << max << "\n";
	}
	
	return 0;
}
