//인사성 밝은 곰곰이
//오픈 채팅방에 사람이 올 때마다 곰곰티콘으로 인사한다
//문자열 킬러 임스는 채팅방에서 곰곰티콘이 사용된 횟수를 구하기로 함
//ENTER 는 새로운 사람이 채팅방에 입장했음을 나타낸다
//그 외는 채팅을 입력한 유저의 닉네임을 나타낸다(숫자 또는 영문 대소문자)

//input 채팅방의 기록 수를 나타내는 정수 N (1 <= N <= 100,000) 입력. ENTER 혹은 유저의 닉네임
//output 곰곰티콘이 사용된 횟수를 출력

//case 1: [9 ENTER pjshwa chansol chogahui05 lms0806 pichulia r4pidstart swoon tony9402] [8]
//case 2: [7 ENTER pjshwa chansol chogahui05 ENTER pjshwa chansol] [5]
//case 3: [3 ENTER lms0806 lms0806] [1]

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	int N, cnt = 0;
	string tmp;
	set<string> name;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		
		if(tmp == "ENTER"){
			cnt += name.size();
			name.clear();
		}
		else
			name.insert(tmp);
	}
	
	cnt += name.size();
	
	cout << cnt << endl;
	
	return 0;
}

/*
int main() {
	int N, cnt = 0;
	vector<string> name;
	string tmp;
	
	cin >> N;
	
	//input name list
	for(int i = 0; i < N; i++){
		cin >> tmp;
		
		//check new user
		if(tmp != "ENTER"){
			if(find(name.begin(), name.end(), tmp) - name.begin() == name.size()){
				cnt++;
				name.push_back(tmp);
			}
		}
		else
			name.clear();
	}
	
	cout << cnt << endl;
	
	return 0;
}
*/
