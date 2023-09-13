//#include <iostream>
//#include <cstring>
//#include <iomanip>
//#include <fstream>
//using namespace std;
//
////ask for advice or contact doctor
//typedef struct
//{
//	char username[50];
//	char password[50];
//	char ic[30];
//	char contactnum[30];
//	char status[10];
//}USER;
//
//void display_report(USER c[], int no_c);
////string feedback(USER c[50], int ptr_id);
//
//int main()
//{
//	USER c[50];
//
//	ifstream name_file("username.txt");
//	ifstream pass_file("userpassword.txt");
//	ifstream ic_file("useric.txt");
//	ifstream phonenum_file("userphone.txt");
//	ifstream stats_file("status.txt");
//
//	if (!name_file)
//		cout << "Error opening username file\n";
//	else if (!pass_file)
//		cout << "Error opening userpassword file\n";
//	else if (!ic_file)
//		cout << "Error opening useric file\n";
//	else if (!phonenum_file)
//		cout << "Error opening user phone number file\n";
//	else if (!stats_file)
//		cout << "Error opening user status file\n";
//	else
//	{
//		// Read data from input files into the CLIENT array
//		for (int i = 0; i < 50; i++)
//		{
//			name_file >> c[i].username;
//			pass_file >> c[i].password;
//			ic_file >> c[i].ic;
//			phonenum_file >> c[i].contactnum;
//			stats_file >> c[i].status;
//		}
//
//		// Close input files
//		name_file.close();
//		pass_file.close();
//		ic_file.close();
//		phonenum_file.close();
//		stats_file.close();
//	}
//
//	int num_c;//the total number of patient
//	int id;//the number of patient in the list
//
//	cout << "Enter number of patient:";
//	cin >> num_c;
//	display_report(c, num_c);
//	cout << "Enter the id of patient(ID means the patient's number in the list）:";
//	cin >> id;
//}
//
//void display_report(USER c[], int no_c)
//{
//	cout << "\nList of Patient\n";
//	cout << left << "\t no\t ----------Name-----------\t IC\t ------------------- Status\t\n";
//	for (int i = 0; i < no_c; i++)
//		cout << "<" << i + 1 << ">" << left << setw(25) << c[i].username << c[i].ic << c[i].status << endl;
//}
//
///*string feedback(USER c[], int ptr_id)
//{
//	cout << "Enter the id of the patient :";
//	cout << "Name   ：" << c[id].username；
//	cout << "IC    \t:" << c[id].IC;
//	cout << "Status \t:" << c[id].status;
//
//	cout << "Enter the your feedback:" << endl;
//	getline(cin,feedback);
//
//	return feedback;
//}*/