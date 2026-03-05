/*13975
소설의 각 장은 각 파일에 저장
모든 장을 작성하면 각 장이 쓰인 파일을 합쳐 한개의 파일로
이 과정에서 두 개의 파일을 하나의 임시파일로 합치고
이 임시파일 또는 원래의 파일 두 개를 합쳐 최종적으로 한개의 파일로
필요 비용이 크기의 합일 때 최소가 되는 값

ex) C1:40, C2:30, C3:30, C4:50
    <case 1>
    C2 + C3 = X1:60, C1 + X1 = X2:100, X2:100 + C4:50 = 150
    60 + 100 + 150 = 310
    <case 2>
    C1 + C2 = Y1:70, C3 + C4 = Y2:80, Y1 + Y2 = 150
    70 + 80 + 150 = 300

expact 1) 매 순간마다 제일 크기가 작은 파일 두개를 합치기
          매번 가장 작은 파일을 탐색해야 함. 최대 10^6
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int T, K, tmp;

    cin >> T;   //test case

    for(int i = 0; i < T; i++){
        cin >> K;   //number of chapter 3 <= K <= 1,000,000
        priority_queue<long long, vector<long long>, greater<long long>> chapter;
        
        for(int j = 0; j < K; j++){
            cin >> tmp; //each size of file < 10,000
            chapter.push(tmp);
        }

        long long sum = 0;

        while(chapter.size() > 1){
            long long part = chapter.top();
            chapter.pop();
            part += chapter.top();
            chapter.pop();
            chapter.push(part);
            sum += part;
        }

        cout << sum << "\n";
    }
    
    return 0;
}