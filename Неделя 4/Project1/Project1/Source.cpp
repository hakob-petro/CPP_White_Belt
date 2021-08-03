#include <iostream>
#include <string>
using namespace std;

struct Specialization {
	string name;
	explicit Specialization(string newname) {
		name = newname;
	}
};

struct Course {
	string name;
	explicit Course(string newname) {
		name = newname;
	}
};

struct Week {
	string name;
	explicit Week(string newname) {
		name = newname;
	}
};


struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization newspec, Course newcourse, Week newweek){
		specialization = newspec.name;
		course = newcourse.name;
		week = newweek.name;
	}
};

void PrintLectures(const LectureTitle& lec) {
	cout << lec.specialization << " " + lec.course << " " + lec.week << endl;
}


int main(){
	//enable
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	
	//diablw
	/*
	LectureTitle title("C++", "White belt", "4th");

	LectureTitle title(string("C++"), string("White belt"), string("4th"));

	LectureTitle title = { "C++", "White belt", "4th" };

	LectureTitle title = { {"C++"}, {"White belt"}, {"4th"} };

	LectureTitle title(
		Course("White belt"),
		Specialization("C++"),
		Week("4th")
	);
	*/
	//system("pause");
	return 0;
}