//체스판 다시 칠하기
//지민이는 자신의 집에서 MN개의 단위 정사각형으로 이루어진 MxN 크기의 보드 발견
//규칙없이 흰색과 검은색으로 칠해진 보드를 잘라서 8x8 크기의 체스판으로 만들어야 함
//각 칸은 흰색과 검은색 둘 중 하나로 채워져있고, 변을 공유하는 사각형의 색은 달라야 함
//따라서 두 가지 경우, 맨 왼쪽 위 칸이 흰색인 경우나 검은색인 경우 뿐이다
//보드를 8x8 크기의 체스판으로 자른 후 몇 개의 칸을 다시 칠하기로 함
//다시 칠하는 칸의 최소 개수를 구하라

//input N과 M 입력(8 <= N, M <= 50). 각 행의 상태를 입력(B: 검은색, W: 흰색)
//output 칠해야 하는 칸 개수의 최솟값을 출력

//case 1: [8 8 WBWBWBWB BWBWBWBW WBWBWBWB BWBBBWBW WBWBWBWB BWBWBWBW WBWBWBWB BWBWBWBW] [1]
//case 2: [10 13 BBBBBBBBWBWBW BBBBBBBBBWBWB BBBBBBBBWBWBW BBBBBBBBBWBWB BBBBBBBBWBWBW BBBBBBBBBWBWB BBBBBBBBWBWBW BBBBBBBBBWBWB WWWWWWWWWWBWB WWWWWWWWWWBWB] [12]
//case 3: [8 8 BWBWBWBW WBWBWBWB BWBWBWBW WBWBWBWB BWBWBWBW WBWBWBWB BWBWBWBW WBWBWBWB] [0]
//case 4: [9 23 BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBB BBBBBBBBBBBBBBBBBBBBBBW] [31]
//case 5: [10 10 BBBBBBBBBB BBWBWBWBWB BWBWBWBWBB BBWBWBWBWB BWBWBWBWBB BBWBWBWBWB BWBWBWBWBB BBWBWBWBWB BWBWBWBWBB BBBBBBBBBB] [0]
//case 6: [8 8 WBWBWBWB BWBWBWBW WBWBWBWB BWBBBWBW WBWBWBWB BWBWBWBW WBWBWWWB BWBWBWBW] [2]
//case 7: [11 12 BWWBWWBWWBWW BWWBWBBWWBWW WBWWBWBBWWBW BWWBWBBWWBWW WBWWBWBBWWBW BWWBWBBWWBWW WBWWBWBBWWBW BWWBWBWWWBWW WBWWBWBBWWBW BWWBWBBWWBWW WBWWBWBBWWBW] [15]

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> A = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
const vector<string> B = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};

int main() {
	//N vertical, M horizon
	int N, M, retA, retB, min = 99999999;
	vector<string> board;
	string tmp;
		
	cin >> N >> M;
		
	for(int i = 0; i < N; i++){
		cin >> tmp;
		board.push_back(tmp);
	}
		
	for(int i = 0; i <= N - 8; i++){
		for(int j = 0; j <= M - 8; j++){
			retA = 0;
			retB = 0;

			for(int k = 0; k < 8; k++){
				for(int l = 0; l < 8; l++){
					if(board[i + k][j + l] != A[k][l])
						retA++;
					
					if(board[i + k][j + l] != B[k][l])
						retB++;
				}
			}
			
			if(retA < retB){
				if(retA < min)
					min = retA;
			}
			else{
				if(retB < min)
					min = retB;
			}
		}
	}
		
	cout << min << endl;
		
	return 0;
}
