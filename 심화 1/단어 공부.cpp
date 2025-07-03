//단어 공부
//알파벳 대소문자로 이루어진 단어가 주어졌을 때, 가장 많이 사용된 알파벳은 무엇인가
//대문자와 소문자는 구분하지 않는다

//input 알파벳 대소문자로 이루어진 단어 입력 (단어의 길이는 1,000,000를 넘지 않는다)
//output 가장 많이 사용된 알파벳을 대문자로 출력. 여러 개 존재하는 경우 ? 출력

//case 1: [Mississipi] [?]		case 2: [zZa] [Z]
//case 3: [z] [Z]				case 4: [baaa] [A]

#include <iostream>
#include <string>

using namespace std;

int main(){
	string word;
	int count[27] = {0, };
	int max = 0;
	char ret;
	
	cin >> word;
	
	//translate word to upper
	for(int i = 0; i < word.size(); i++){
		word[i] = toupper(word[i]);
	}

	for(char c : word){
		count[c - 65]++;
	}

	for(int i = 0; i < 26; i++){
		if(count[i] > max){
			max = count[i];
			ret = i + 65;
		}
		else if(count[i] == max)
			ret = '?';
	}
	
	cout << ret << endl;
	
	return 0;
}

/*
int main() {
	string word;
	char ret;
	int max = 0, count;
	
	cin >> word;
	
	//translate word to upper
	for(int i = 0; i < word.size(); i++){
		word[i] = toupper(word[i]);
	}
	
	//search O(N^2)
	for(char c : word){
		count = 0;
		
		for(char comp : word){
			if(c == comp)
				count++;
		}
		
		if(count > max){
			max = count;
			ret = c;
		}
		else if(count == max && ret != c){
			ret = '?';
		}
	}
	
	cout << ret << endl;
	
	return 0;
}


//이중 for문은 O(N^2)으로 시간초과
*/
