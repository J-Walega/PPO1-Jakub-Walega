#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

#define STUDENTS_COUNT 10



class Student {
	public:
		string studentNo;
			
		void setStudentNo(string studentNo) {
			this->studentNo = studentNo;
		}
		
		string getStudentNo() {
			return this->studentNo;
		}					
		
};

string getRandomStudentNumber() {
	ostringstream ss;
	int randomNumber = rand() % 2000 + 37000;
	
	ss << randomNumber;
	
	return ss.str();
}

string randomName()
		{		
	string Names[10]=
		Names[0]="Pawel";
		Names[1]="Piotr";				
		Names[2]="Maciej";
		Names[3]="Jakub";
		Names[4]="Andrzej";
		Names[5]="Adam";
		Names[6]="Grzegorz";
		Names[7]="Stanislaw";
		Names[8]="Zbyszek";
		Names[9]="Robert";
		
		string oneName="";
		int nr=rand()%10;
		if(nr==0)
		{
			oneName=Names[0];
		}
		if(nr==1)
		{
			oneName=Names[1];
		}
		if(nr==2)
		{
			oneName=Names[2];
		}
		if(nr==3)
		{
			oneName=Names[3];
		}
		if(nr==4)
		{
			oneName=Names[4];
		}
		if(nr==5)
		{
			oneName=Names[5];
		}
		if(nr==6)
		{
			oneName=Names[6];
		}
		if(nr==7)
		{
			oneName=Names[7];
		}
		if(nr==8)
		{
			oneName=Names[8];
		}
		if(nr==9)
		{
			oneName=Names[9];
		}
		return oneName;
		}
		
string RandomSurName()
		{		
	string surNames[10]=
		surNames[0]="Pawlowski";
		surNames[1]="Piotrowski";				
		surNames[2]="Maciejowski";
		surNames[3]="Jakubowski";
		surNames[4]="Andrzejowski";
		surNames[5]="Adamski";
		surNames[6]="Grzegorski";
		surNames[7]="Stanislawowski";
		surNames[8]="Zbyszekowski";
		surNames[9]="Robertowski";
		
		string oneSurname="";
		int nr=rand()%10;
		
		if(nr==0)
		{
			oneSurname=surNames[0];
		}
		if(nr==1)
		{
			oneSurname=surNames[1];
		}
		if(nr==2)
		{
			oneSurname=surNames[2];
		}
		if(nr==3)
		{
			oneSurname=surNames[3];
		}
		if(nr==4)
		{
			oneSurname=surNames[4];
		}
		if(nr==5)
		{
			oneSurname=surNames[5];
		}
		if(nr==6)
		{
			oneSurname=surNames[6];
		}
		if(nr==7)
		{
			oneSurname=surNames[7];
		}
		if(nr==8)
		{
			oneSurname=surNames[8];
		}
		if(nr==9)
		{
			oneSurname=surNames[9];
		}
		return oneSurname;	
		}
		
string IsStudent()
{
	int nr=rand()%2;
	string Status="";
	if(nr==0)
	{
		Status="No";
	}
	if(nr==1)
	{
		Status="Yes";
	}
	return Status;
}		

int main() {
	vector<Student> students;
	srand(time(NULL));
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		Student student;
		student.setStudentNo(getRandomStudentNumber());
		students.push_back(student);
	}
	
	cout  << "Students group have been filled." << endl << endl;
	
	for(int i = 0; i < students.size(); i++) {
		Student student = students.at(i);
		cout << RandomSurName()+ " " + randomName() + " " + student.getStudentNo() + " 		Is a student?:" + IsStudent()  << endl;
	}
	
	return 0;
}
