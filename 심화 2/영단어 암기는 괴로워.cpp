/*영단어 암기는 괴로워
자주 나오는 단어일수록 앞에 배치, 길이가 길수록 앞에 배치, 알파벳 사전 순으로 앞에 배치
단어는 길이가 M 이상인 단어들만 외운다

input 단어의 개수 N, 단어의 길이 기준이 되는 M 입력(1 <= N <= 100,000, 1 <= M <= 10)
		입력은 알파벳 소문자만 주어지며 길이는 10을 넘지 않음
output 앞에 위치한 단어부터 순서대로 출력

case 1 [7 4 apple ant sand apple append sand sand] [sand apple append]

case 2 [12 5 appearance append attendance swim swift swift swift mouse wallet mouse ice age]
	   [swift mouse appearance attendance append wallet]

hint cin.tie(NULL), sync_with_stdio(false) 적용. endl 대신 개행문자 '\n'
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b){
	if(a.first == b.first){
		if(a.second.length() == b.second.length())
			return a.second < b.second;
		else
			return a.second.length() > b.second.length();
	}
	else
		return b.first < a.first;
}

int main() {
	int N, M;
	string tmp;
	map<string, int> word;
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//input conditions and words
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		
		//exclude word less than M
		if(tmp.size() >= M)
			word[tmp]++;
	}
	
	//sort
	vector<pair<int, string>> wordbook;
	
	for(auto w : word){
		wordbook.push_back({ w.second, w.first });
	}
	
	sort(wordbook.begin(), wordbook.end(), comp);
	
	for(auto s : wordbook){
		cout << s.second << "\n";
	}
	
	return 0;
}
