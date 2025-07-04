/*2179
N개의 영단어가 주어졌을 때 가장 비슷한 두 단어를 구하라
비슷함의 정도는 두 단어의 접두사의 길이로 측정. 접두사는 단어의 시작부터 공통으로 나타나는 부분 문자열
접두사의 길이가 최대인 경우가 여러 개일 때에는 제일 먼저 입력된 단어를 답으로 함

input N (2 <= N <= 20,000) 입력. N개의 줄에 알파벳 소문자로 이루어진 길이 100 이하의 영단어 입력
output 첫째 줄에 S, 둘째 줄에 T 출력. 두 단어 S와 T는 다름

case 1 [9 noon is lunch for most noone waits until two] [noon noone]
case 2 [4 abcd abe abc abchldp] [abcd abc]

input				 	 wrong	 answer
5 ca ab ac cc c 	 	| ca ab | ca cc
5 a c bcc accac b 		| a bcc | a accac
5 a ca bcc abcac bbbbc  | a bcc | a abcac
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, max = -1;
	vector<pair<string, int>> words;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		string tmp;
		cin >> tmp;
		words.push_back({tmp, i});
	}

	sort(words.begin(), words.end());	//sort by abc -> similar word will be near
	
	vector<pair<int, string>> candi;	//candidate that same length of prefix
	
	for(int i = 0; i < N - 1; i++){
		int cnt = 0;
		
		if(words[i].first == words[i+1].first) continue;	//exclude same word
		
		//repeat for minimum between words[i], words[i+1] size
		for(int j = 0; j < min(words[i].first.size(), words[i+1].first.size()); j++){	
			if(words[i].first[j] == words[i+1].first[j]) cnt++;	//count lenght of same prifix
			else break;
		}
		
		if(cnt > max){
			max = cnt;
			candi.clear();
		}
		else if(cnt < max) continue;
		
		//add longest similar words to candidate vector
		if(candi.empty() || candi[candi.end() - candi.begin() - 1].second != words[i].first)
			candi.push_back({words[i].second, words[i].first});
		candi.push_back({words[i+1].second, words[i+1].first});
	}
	
	sort(candi.begin(), candi.end());	//sort by index
	
	string S = candi[0].second, T = candi[1].second;
	
	for(int i = 1; i < candi.size(); i++){
		for(int j = 0; j < max; j++){
			if(candi[i].second[j] != candi[0].second[j]) break;
			
			//found first similar words
			if(j + 1 == max){
				S = candi[0].second;
				T = candi[i].second;
				
				cout << S << "\n" << T;
				return 0;
			}
		}
	}
	
	cout << S << "\n" << T;
	
	return 0;
}

/*
26개의 소수를 알파벳에 대응. 각 단어의 알파벳마다 값을 곱하면 고유한 수가 나올 것
vector<int> prm = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
좋은 아이디어인 것 같긴한데, 문제에 적절한 방법은 아닌듯
*/
