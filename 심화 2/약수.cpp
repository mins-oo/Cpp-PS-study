//약수
//양수 A가 N의 진짜 약수가 되려면 N이 A의 배수이고, A가 1과 N이 아니어야 한다.
//N의 진짜 약수가 모두 주어질 때, N을 구하시오

//input N의 진짜 약수의 개수 입력(<= 50). N의 진짜 약수를 입력 (2 <= <= 1,000,000)
//output N 출력

//case 1: [2 \n 4 2] [8]	case 2: [1 \n 2] [4]	case 3: [6 \n 3 4 2 12 6 8] [24]
//case 4: [14 \n 26456 2 28 13228 3307 7 23149 8 6614 46298 56 4 92596] [185192]

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num, tmp, min = 99999999, max = 0;
	vector<int> div;
	
	cin >> num;
	
	for(int i = 0; i < num; i++){
		cin >> tmp;
		div.push_back(tmp);
	}
	
	for(int n : div){
		if(n < min)
			min = n;
		if(n > max)
			max = n;
	}
	
	cout << min * max << endl;
	
	return 0;
}
