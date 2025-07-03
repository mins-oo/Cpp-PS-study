//너의 평점은
//치훈의 전공평점을 계산. 전공평점은 과목별 학점x과목평점의 합을 학점의 총합으로 나눈 것
//등급에 따른 과목평점
//A+: 4.5, A0: 4.0, B+: 3.5, B0: 3.0, C+: 2.5, C0: 2.0, D+: 1.5, D0: 1.0, F: 0.0
//P/F 과목의 경우 등급이 P또는 F로 표시되는데, P는 계산에서 제외

//input 20줄에 걸쳐 치훈이가 수강한 과목의 과목명, 학점, 등급이 공백으로 구분되어 입력
//output 전공평점 출력 (절대오차 또는 상대오차가 10^-4이하면 정답)

//case 1: [ObjectOrientedProgramming1 3.0 A+ \n IntroductiontoComputerEngineering 3.0 A+ \n
//		   ObjectOrientedProgramming2 3.0 A0 \n CreativeComputerEngineeringDesign 3.0 A+ \n
//		   AssemblyLanguage 3.0 A+ \n InternetProgramming 3.0 B0 \n
//		   ApplicationProgramminginJava 3.0 A0 \n SystemProgramming 3.0 B0 \n
//		   OperatingSystem 3.0 B0 \n WirelessCommunicationsandNetworking 3.0 C+ \n
//		   LogicCircuits 3.0 B0 \n DataStructure 4.0 A+ \n MicroprocessorApplication 3.0 B+ \n
//		   EmbeddedSoftware 3.0 C0 \n ComputerSecurity 3.0 D+ \n Database 3.0 C+ \n
//		   Algorithm 3.0 B0 \n CapstoneDesigninCSE 3.0 B+ \n CompilerDesign 3.0 D0 \n
//		   ProblemSolving 4.0 P] [3.284483]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> gradeList = {"F", "P", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};

int main() {
	string name, grade;
	float rating, point, ret, count = 0;
	
	for(int i = 0; i < 20; i++){
		cin >> name >> point >> grade;
		
		//set rating
		for(int i = 0; i < gradeList.size(); i++){
			if(grade == gradeList[i]){
				rating = i * 0.5f;
				
				//exclude P grade
				if(grade == "P"){
					rating = 0;
					continue;
				}
				
				count += point;
			}
		}
		ret += point * rating;
	}
	
	ret = ret / (float)count;
	
	cout << ret << endl;
	
	return 0;
}
