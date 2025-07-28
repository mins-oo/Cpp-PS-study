/*2015
A[1], A[2], ..., A[N]의 N개의 정수가 저장된 배열
부분합이란 1 <= i <= j <= N 에 대해 A[i]부터 A[j]까지의 합
N이 주어졌을 때 부분합이 K인 경우의 수를 구하라

input N, K (1 <= N <= 200,000, |K| <= 2,000,000,000) 입력
	  배열 A를 이루는 정수 N개 입력 (-10,000 <= A[x] <= 10,000)
output 부분합이 K인 경우의 개수 출력

case 1 [4 0 2 -2 2 -2] [4]
case 2 [6 5 1 2 3 4 5 0] [3]
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K, tmp, sum = 0;
    
    map<int, long long> accums_counter;
    accums_counter[sum]++;
    
    cin >> N >> K;
    
    long long cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        sum += tmp;
        cnt += accums_counter[sum - K];
        accums_counter[sum]++;
    }

    cout << cnt;
}