//크로아티아 알파벳
//크로아티아 알파벳 c=, c-, dz=, d-, lj, nj, s=, z=가 있다
//이 외의 알파벳은 한 글자씩 센다

//input 최대 100글자의 단어를 입력 (알파벳 소문자, -, = 으로만 이루어져 있다)
//output 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력

//case 1: [ljes=njak]	[6]				case 2: [ddz=z=]	[3]
//case 3: [nljj]		[3]				case 4: [c=c=]		[2]
//case 5: [dz=ak]		[3]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> crAl = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
	string word, comp, tmp;
	int ret;
	
	cin >> word;
	ret = word.size();
	
	for(int i = 0; i < word.size(); i++){
		for(string str : crAl){
			if(str.size() == 2){
				comp = word[i];
				tmp = word[i+1];
				comp += tmp;
			}
			//case "dz=". it can overlaping with "z="
			else{
				comp = word[i];
				tmp = word[i+1];
				comp += tmp;
				tmp = word[i+2];
				comp += tmp;
			}
			
			if(str == comp){
				if(str.size() == 3)
					ret++;
				ret -= str.size() - 1;
			}
		}
	}
	
	cout << ret << endl;
	
	return 0;
}
