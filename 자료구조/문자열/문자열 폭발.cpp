/*9935
상근이는 문자열에 폭발 문자열을 심음. 폭발 문자열이 폭발하면 사라지고 남은 문자열은 순서대로 합체
새로 합쳐진 문자열에 폭발 문자열이 포함되어 있을 수 있음. 폭발은 폭발 문자열이 없을 때까지 계속
남은 문자열이 없으면 "FRULA" 출력
폭발 문자열은 같은 문자를 두 개 이상 포함하지 않음

input 1이상 1,000,000이하 길이의 문자열 입력
	  1이상 36이하 길이의 폭발 문자열 입력 (알파벳 대소문자, 숫자로 구성)
output 모든 폭발이 끝나고 남은 문자열을 출력

case 1 [mirkovC4nizCC44 C4] [mirkovniz]
case 2 [12ab112ab2ab 12ab] [FRULA]

aaaaaaaaaaa...aabbbbbbbbbb...bbbb ab
FRULA
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str, bomb, tmp = "";

	cin >> str >> bomb;
	
	for(int i = 0; i < str.size(); i++){
		tmp += str[i];
		if(tmp.size() >= bomb.size()){
			int j = 0;
			for(; j < bomb.size(); j++){
				if(tmp[tmp.size() - bomb.size() + j] != bomb[j]) break;
			}
			
			if(j == bomb.size()) tmp.erase(tmp.end() - bomb.size(), tmp.end());
		}
	}
	
	if(tmp == "") cout << "FRULA";
	else cout << tmp;
	
	return 0;
}

/*
vector<int> cnt;
string str, bomb;

cin >> str >> bomb;
	
for(int i = 0; i < str.size(); i++){
	if(str[i] == bomb[0]){
		//폭발 문자열 의심 구역을 저장
		if(cnt.empty() || cnt[cnt.end() - cnt.begin() - 1] != i) cnt.push_back(i);
			
		//의심 구역이 폭발 문자열과 일치하는지 탐색
		for(int j = 1; j < bomb.size(); j++){
			//미일치 시 반복문 탈출
			if(str[i+j] != bomb[j]) break;
				
			//일치 시 의심 구역 제거, 문자열 폭발
			if(j == bomb.size() - 1){
				cnt.erase(cnt.end() - 1);
					
				str.erase(str.begin() + i, str.begin() + i + j + 1);
				
				if(cnt.empty()) i--;	//직전으로 이동
				else i = cnt[cnt.end() - cnt.begin()] - 2;	//최근 의심 구역으로 이동
			}
		}
	}
}
	
if(str == "") cout << "FRULA";
else cout << str;
*/
