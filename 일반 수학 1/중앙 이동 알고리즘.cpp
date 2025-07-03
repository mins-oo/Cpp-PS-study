//중앙 이동 알고리즘
//상근이는 친구와 SF영화를 찍으려는데, 외계 지형이 필요
//정사각형을 이루는 점 4개를 선택
//각 변의 중앙에 점을 추가. 정사각형 중앙에 점을 추가 << N번 반복
//메모리 소모를 줄이기 위해 중복되는 점 없이 한 번만 저장

//input N을 입력 (1 <= N <= 15)
//output N번 반복한 후 점의 수를 출력

//case 1: [1] [9]
//case 2: [2] [25]
//case 3: [5] [1089]

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, vertex, tmp;
	vertex = 4, tmp = 2;
	vector<int> a;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		tmp = (tmp - 1) * 2 + 1;
		vertex = tmp * tmp;
	}
	
	cout << vertex << endl;
	
	return 0;
}
