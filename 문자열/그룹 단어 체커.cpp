//그룹 단어 체커
//그룹 단어란 단어에 존재하는 모든 문자가 이어지는 경우
//ccazzzzbb, kin은 그룹 단어지만, aabbbccb는 b가 떨어져 있어 그룹이 아님

//input 단어의 개수 N을 입력 (N <= 100). 단어 N개 입력 (알파벳 소문자, 중복x, 최대 100)
//output 그룹 단어의 개수 출력

//case 1: [3 \n happy \n new \n year] [3]
//case 2: [4 \n aba \n abab \n abcabc \n a] [1]
//case 3: [5 \n ab \n aa \n aca \n ba \n bb] [4]
//case 4: [2 \n yzyzy \n zyzyz] [0]
//case 5: [1 \n z] [1]
//case 6: [9 \n aaa \n aaazbz \n babb \n aazz \n azbz \n aabbaa \n abacc \n aba \n zzaz] [2]

#include <iostream>
#include <string>

using namespace std;

bool searchGroup(char c, string group){
	for(char comp : group){
		if(c == comp)
			return true;
	}
	
	return false;
}

int main() {
	int N, ret = 0;
	char tmp;
	string word, group;
	
	//input words
	cin >> N;
	
	//N times individual case
	for(int i = 0; i < N; i++){
		cin >> word;
		tmp = ' ';
		
		for(char c : word){
			//check same alphabat group
			if(c == tmp){
				continue;
			}
			
			//alphabat has changed
			tmp = c;
			if(searchGroup(c, group)){
				ret--;
				break;
			}
			else
			{
				group.push_back(c);
			}
		}
		
		ret++;
		group = "";
	}
	
	cout << ret << endl;
	
	return 0;
}
