/*잃어버린 괄호
양수와 +, -, 그리고 괄호를 가지고 식을 만든 후 괄호를 지웠다가 다시 괄호를 쳐서 값을 최소로

input '0'~'9', '+', '-'을 사용한 식 입력. 연산자가 연속되지 않고, 5자리 초과의 연속되는 숫자는 없음.
	  수는 0으로 시작할 수 있고 식의 길이는 50 이하
output 최소 정답 출력

case 1 [55-50+40] [-35]		case 2 [10+20+30+40] [100]		case 3 [00009-00009] [0]
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string eq, num = "";
	int sum = 0;
	bool isBracket = false;
	
	cin >> eq;
	eq += "=";

	for(char c : eq){
		if(c == '+' || c == '-' || c == '='){
			if(isBracket)
				sum -= stoi(num);
			else
				sum += stoi(num);
			num.clear();
			
			if(c == '-')
				isBracket = true;
		}
		else{
			num += c;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
