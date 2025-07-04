/*14719
2차원 세계에 블록이 쌓여있음. 비가 오면 블록 사이에 고임
□□□□■□□□		□□□□■□□□
■□□■■□□□		■▒▒■■□□□
■□■■■□□■		■▒■■■▒▒■
■■■■■■■■		■■■■■■■■

input 2차원 세계의 세로 길이 H와 가로 길이 W 입력 (1 <= H, W <= 500)
	  0이상 H이하의 블록이 쌓인 높이가 맨 왼쪽부터 W개 입력
output 한 칸의 용량을 1이라 할 때, 고이는 빗물의 총량 출력

case 1 [4 4 3 0 1 4] [5]	case 2 [4 8 3 1 2 3 4 1 1 2] [5]	case 3 [3 5 0 0 0 2 0] [0]
		□□□■						□□□□■□□□						
		■▒▒■						■▒▒■■□□□						□□□□□
		■▒▒■						■▒■■■▒▒■						□□□■□
		■▒■■						■■■■■■■■						□□□■□
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int H, W, tmp, sum = 0;
	vector<int> x;
	
	cin >> H >> W;
	for(int i = 0; i < W; i++){
		cin >> tmp;
		x.push_back(tmp);
	}
	
	for(int h = 0; h < H; h++){		//bottom to top
		tmp = 0;
		bool isClosed = false;
		
		for(int w = 0; w < W; w++){	//left to right
			if(x[w] <= h) tmp++;
			else{
				if(isClosed) sum += tmp;
				else isClosed = true;
				
				tmp = 0;
			}
		}
	}
	
	cout << sum;
	
	return 0;
}
