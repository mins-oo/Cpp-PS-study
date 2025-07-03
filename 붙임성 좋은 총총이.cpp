//붙임성 좋은 총총이
//총총이의 무지개 댄스를 본 사람은 따라하게 된다
//사람들이 만난 기록이 N개 주어짐. 처음에는 총총이만 무지개 댄스를 추고있음
//마지막에 무지개 댄스를 추는 사람은 총 몇 명인지 구하라

//input 사람이 만난 기록의 수 N(1 <= N <= 1,000) 입력. ChongChong은 1회 이상 존재
//output 무지개 댄스를 추는 사람의 수를 출력

/*case 1
[12
bnb2011 chansol
chansol chogahui05
chogahui05 jthis
jthis ChongChong
jthis jyheo98
jyheo98 lms0806
lms0806 pichulia
pichulia pjshwa
pjshwa r4pidstart
r4pidstart swoon
swoon tony9402
tony9402 bnb2011] [10]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

static vector<string> dancers;

bool search(string s){
	for(string dancer : dancers){
		if(s == dancer)
			return true;
	}
	return false;
}

int main() {
	int N;
	string tmp;
	vector<string> names;

	dancers.push_back("ChongChong");
	
	cin >> N;
	//input records that people met
	for(int i = 0; i < N; i++){
		cin >> tmp;
		names.push_back(tmp);
		cin >> tmp;
		names.push_back(tmp);
	}
	
	for(int i = 0; i < names.size() / 2; i++){
		if(search(names[2 * i]) && !search(names[2 * i + 1])){
			dancers.push_back(names[2 * i + 1]);
		}
		if(!search(names[2 * i]) && search(names[2 * i + 1])){
			dancers.push_back(names[2 * i]);
		}
	}
	
	cout << dancers.size() << endl;
	
	return 0;
}
