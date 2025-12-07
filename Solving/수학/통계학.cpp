//통계학
//N개의 수의 통계값 4가지
//산술평균 : N개의 수들의 합을 N으로 나눈 값
//중앙값 : N개의 수들을 증가하는 순서로 나열했을 때 중앙에 위치하는 값
//최빈값 : N개의 수들 중 가장 많이 나타나는 값
//범위 : N개의 수들 중 최댓값과 최솟값의 차이

//input N (1 <= N <= 500,000) 입력 (N은 홀수). N개의 정수가 입력. 정수의 절댓값은 4,000 이하
//output 산술평균, 중앙값, 최빈값, 범위를 출력. -0은 0으로 출력

//case 1: [5 1 3 8 -2 2] [2 2 1 10]			case 2: [1 4000] [4000 4000 4000 0]
//case 3: [5 -1 -2 -3 -1 -2] [-2 -2 -1 2]	case 4: [3 0 0 -1] [0 0 0 1]

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N, tmp;
	vector<int> num, mv;
	
	double ret = 0;		//when float, wrong?
	int count[8001] = { 0, };
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		num.push_back(tmp);
	}
	
	for(int i = 0; i < N; i++){
		//mean
		ret += num[i];

		//mode
		count[num[i] + 4000]++;
	}
	
	//print mean
	ret = round(ret / (double)N);
	if(ret == -0)
		ret = 0;
	cout << ret << endl;
	
	//print median
	sort(num.begin(), num.end());
	cout << num[num.size() / 2] << endl;
	
	//mode
	tmp = 0;
	for(int i = 0; i < 8001; i++){
		if(count[i] > tmp){
			ret = i - 4000;
			tmp = count[i];
		}
	}
	
	for(int i = 0; i < 8001; i++){
		if(count[i] == tmp)
			mv.push_back(i - 4000);
	}
	
	sort(mv.begin(), mv.end());

	if(mv.size() == 1)
		ret = mv[0];
	else
		ret = mv[1];
	
	//print mode
	cout << ret << endl;
	
	//print range
	cout << num[num.size() - 1] - num[0] << endl;
	
	return 0;
}
