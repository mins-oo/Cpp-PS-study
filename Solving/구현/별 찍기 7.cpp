/*2444
규칙을 유추하여 별을 찍어라

input N 입력 (1 <= N <= 100)
output 2N - 1 번째 줄까지 차례대로 별 출력

case 1: [5] [* \n *** \n ***** \n ******* \n ********* \n ******* \n ***** \n *** \n *]
*/

#include <iostream>

using namespace std;

int main() {
	int N;
	
	cin >> N;
	
	for(int i = 0; i < 2 * N - 1; i++){
		//jump
		for(int j = 0; j < abs(1 - N + i); j++){
			cout << " ";
		}
		
		//output stars
		for(int j = 0; j < 1 + (N - abs(1 - N + i) - 1) * 2; j++){
			cout << "*";
		}
		
		cout << endl;
	}

	return 0;
}
