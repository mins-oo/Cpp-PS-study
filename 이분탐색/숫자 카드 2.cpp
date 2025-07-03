/*숫자 카드 2
정수 하나가 적혀져 있는 카드. 상근이는 카드 N개를 가지고 있다
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지

input 상근이가 가지고 있는 카드의 수 N (1 <= N <= 500,000), 각 카드에 적혀져 있는 정수 입력
	  M (1 <= M <= 500,000), M개의 정수 입력
	  정수는 -10,000,000보다 크거나 같고 10,000,000보다 작거나 같음
output M개의 수에 대하여 각 수가 적힌 카드를 상근이가 몇 개 가지고 있는지 출력

case 1 [10 6 3 2 10 10 10 -10 -10 7 3 8 10 9 -5 2 3 4 5 -10] [3 0 0 1 2 0 0 2]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long num;
vector<long long> card;

//beg, end 범위를 좁혀가 중복수의 범위를 구할 것 => beg, end을 각각 binary search
int binary_search(int target, int beg, int end){
	if(beg > end)	return 0;
	
	int mid = (beg + end) / 2;
	
	if(target < num){	//case of searching beg
		if(card[beg] == num)	return beg - 1;	//card[0] == num
		
		if(card[mid] == num)	return binary_search(target, beg, mid - 1);
		
		if(card[mid+1] == num)	return mid;		//num 바로 전에 해당하는 수
	}
	else{				//case of searching end
		if(card[end] == num)	return end;		//card[N-1] == num
		
		if(card[mid] == num)	return binary_search(target, mid + 1, end);
		
		if(card[mid-1] == num)	return mid - 1;	//num 바로 다음에 해당하는 수
	}
	
	if(card[mid] > num)	return binary_search(target, beg, mid - 1);
	else	return binary_search(target, mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	
	cin >> N;	
	for(int i = 0; i < N; i++){	//상근이의 카드 입력
		cin >> num;
		card.push_back(num);
	}
	
	sort(card.begin(), card.end());	//-10 -10 2 3 3 6 7 10 10 10
	
	cin >> M;
	for(int i = 0; i < M; i++){	//대상 카드 M개 입력
		cin >> num;
		
		//target range end point - target range beg point
		cout << binary_search(num+1, 0, N-1) - binary_search(num-1, 0, N-1) << " ";
		//upper_bound(card.begin(), card.end(), num); 주어진 값보다 큰 값이 처음으로 나타난 위치
	}
	
	return 0;
}
