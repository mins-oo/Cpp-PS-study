//팰린드롬인지 확인하기
//알파벳 소문자로만 이루어진 단어가 주어질 때, 이 단어가 팰린드롬인가
//팰린드롬이란 앞으로 읽을 때와 뒤로 읽을 때가 같은 단어

//input 단어를 입력. 단어는 1보다 크거나 같고, 100보다 작거나 같으며 모두 소문자.
//output 팰린드롬이면 1, 아니면 0을 출력

//case 1: [level] [1]		case 2: [baekjoon] [0]

#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	
	cin >> word;
	
	for(int i = 0; i < word.size() / 2; i++){
		if(word[i] != word[word.size() - i - 1]){
			cout << "0" << endl;
			return 0;
		}
	}
	
	cout << "1" << endl;
	
	return 0;
}
