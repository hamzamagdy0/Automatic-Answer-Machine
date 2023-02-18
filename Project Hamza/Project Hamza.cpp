#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
using namespace std;


bool adminMenu();
bool loginCode();
bool checkAdmin(string UserName, int Password);
void adminSwitch();
void accessStudentGrades();
void addQuestions();
void studentMenu();
void generateQuestions();

int main()
{
		// Color of the console
		HANDLE console_color;
		console_color = GetStdHandle(STD_OUTPUT_HANDLE);

		// Print color 10(Green) on output screen(compiler)
		SetConsoleTextAttribute(console_color, 10);

		//prompt type of user
		int choice;
		cout <<"Log in as:" << endl;
		cout << "\n<><><><><><><><><>" << endl;
		cout << "<>              <>" << endl;
		cout << "<>   1)Student  <> " << endl << "<>   2)Admin    <> " << endl;
		cout << "<>              <>" << endl;
		cout << "<><><><><><><><><>" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			//student code
			studentMenu();
			break;
		case 2:
			//admin code
			adminMenu();
		}
	}


bool adminMenu() {
	//menu that's shown to admin
	system("cls");

	//prompt option from admin
	int adminOption, Option1;
	cout << "Choose one of the following : " << endl;
	cout << "1)Login\n2)Exit\n";
	cin >> Option1;
	system("cls");
	switch (Option1) {
	case 1:
		//login code
		if (loginCode()) {
			cout << "Welcome Admin1234\n";
			adminSwitch();
		}
		break;
	case 2:
		//exit code
		cout << "Exit Successful \n";
		exit(0);
		break;
	}
}

bool checkAdmin(string UserName, int Password) {
	//compare prompted UN and PASS to the correct UN and PASS
	string name = "Admin1234";
	int pass = 1234;
	if (name == UserName && pass == Password) {
		return true;
	}
	else if (name == UserName && pass != Password || name != UserName && pass == Password || name != UserName && pass != Password)
		return false;
	else
		return false;
}

bool loginCode() {
	//prompting UN and PASS 5 times max; else blocked
	int password;
	string userName;
	cout << "To continue, please enter the following :\n";
	for (int i = 1; i <= 5; i++) {
		cout << "Username: \n";
		cin >> userName;
		cout << "Password: \n";
		cin >> password;
		if (checkAdmin(userName, password)) {
			system("cls"); // << command to clear screen
			return true;
		}
		else
			if (i == 5) {
				system("cls");
				cout << "Error , You are Blocked !! :(\n";
				exit(0);
			}
			else {
				cout << "\nYour Password or Username is incorrect.\nTry again, You have " << 5 - i << " try(s) left.\n";
			}
	}
	
}

void adminSwitch() {
	//admin's options
	int adminOption;
	cout << "Choose one of the following :"<< endl ;
	cout << "\n1)Access Student Names and Grades List\n2)Add Questions\n3)Logout\n4)Exit\n";
	cin >> adminOption;
	switch (adminOption) {
	case 1:
		//access student grades and names
		accessStudentGrades();
		break;
	case 2:
		//add new questions
		addQuestions();
		break;
	case 3:
		//logout
		main();
		break;
	case 4:
		//exit code
		exit(0);
		break;
	}
}

void accessStudentGrades() {
	//access the students' names and grades

	//initialize counter for array
	short i = 1;

	//open files
	ifstream students("Names.txt");
	ifstream grades("Grades.txt");
	string studentsArray[100];
	int gradesArray[100];

	//while files aren't at the end of the file input data to array
	if (students.is_open() && grades.is_open()) {
		while (!students.eof() && !grades.eof())
		{
			getline(students, studentsArray[i]);
			grades >> gradesArray[i];
			cout << studentsArray[i] << " " << gradesArray[i] << "/5\n";
			i++;
		}
	}
	else
		cout << "Error, File Failed to Open.\n"; //file failed to open


	//return to admin switch
		adminSwitch();
	
	
}

void addQuestions() {
	string newQuestion = "", newAnswer = "";
	short numOfQuestions;

	//prompt from admin number of questions
	cout << "Number of Questions you want to add:\n";
	cin >> numOfQuestions;

	//open question and answer files
	ofstream questions;
	questions.open("QuestionBank.txt", ios::app);
	ofstream answers;
	answers.open("Answers.txt", ios::app);
	system("cls");

	//if files are open, fill arrays with opened files
	if (questions.is_open() && answers.is_open()) {
		cin.ignore();
		cout << "Please Enter the following" << endl;
		for (int i = 1; i <= numOfQuestions; i++) {
			cout << "The Question you want to add:"<<endl;
			getline(cin, newQuestion);
			cout << "\nThe corresponding correct Answer:"<<endl;
			getline(cin, newAnswer);
			questions << endl << newQuestion;
			answers << endl << newAnswer;
			system("cls");
		}
	}
	else
		//file failed to open
		cout << "Error, File Failed to open. ";


	//return to admin switch
	adminSwitch();

}

void studentMenu() {
	//student signing up
	string quizName;

	//open name file
	ofstream studentnames;
	studentnames.open("Names.txt", ios::app);

	//if file is opened, enter name of student to names file
	if (studentnames.is_open()) {
		cin.ignore();
		cout << "Please enter your name: ";
		getline(cin, quizName);
		studentnames << endl << quizName;
	}
	else {
		//file failed to open
		cout << "File Failed to open. :(";
	}
	//go to generate questions
	generateQuestions();
}

void generateQuestions() {
	//displaying questions to students
	srand(time(0));

	//open question and answer files
	ifstream questions("QuestionBank.txt");
	ifstream answers("Answers.txt");
	string AnswerArray[100];
	string QuestionsArray[100];
	string answer;
	int points = 0, i = 0;

	//while files aren't at the end of the file, fill arrays with files
	while (!questions.eof() && !answers.eof()) {
		getline(questions, QuestionsArray[i]);
		getline(answers, AnswerArray[i]);
		i++;
	}

	//generate random index number and show respective question
	for (int i = 0; i < 5; i++) {
		int j = rand() % 49;
		cout << QuestionsArray[j] << endl;
		cin >> answer;
		string x = answer;
		//turn uppercase characters into lowercase to match model answer
		for (int i = 0; i < x.length(); i++) {
			x[i] = tolower(x[i]);
		}
		//calculate grade
		if (AnswerArray[j] == x) {
			points++;
		}

	}

	cout << points << "/5";
	//input grade of student into grades file
	ofstream Grades("Grades.txt", ios::app);
	Grades << endl << points;
	//logout code
	exit(0);
}