//#include <iostream>
//using namespace std;
//
////function prototype
//char hasSymptom(SYMPTOM s[], char response[], int size);
//char response();
//
//typedef struct
//{
//	string sweating[15];
//	string trembling[15];
//	string hunger[15];
//	string dizziness[15];
//}SYMPTOM;
//
////main function
//int main()
//{
//	system("CLS");
//	SYMPTOM s[50];
//	char response [2];
//	hasSymptom(s, response, 2);
//}
//
////function definitions
//char hasSymptom(SYMPTOM s[], char response[], int size)
//{
//	char ans;
//	for (int i = 0; i < 4; i++)
//	{
//		do {
//			cout << "Do you have " << s[i] << " ?\t <Y/N>: >>>\t";
//			cin >> ans;
//			ans = toupper(ans);
//		} while (ans != 'Y' && ans != 'N');
//		if (ans == 'Y')
//			response[0]++;
//		if (ans == 'N')
//			response[1]++;
//	}
//}
//
////char response() {
////	for (int i = 0; i < 3; i++);
////	{
////		void hasSymptom();
////			do
////			{
////				cout << "Do you have " << symptom << "? <Y/N>:\t";
////				cin >> response[3];
////				response[3] = toupper(response[3]);
////			} while (response != 'Y' && response != 'N'); // Loop until valid input (Y or N) is provided
////	}
////}
////do
////{
////	bool response = 'Y' or 'N'; // Prompt for response
////	response = toupper(response); // Convert input to uppercase
////
////	return (response == 'Y' || response == 'N');
////
////} while (response != 'Y' && response != 'N'); // Loop until valid input (Y or N) is provided
////cout << " " << endl;
////
////string symptom[15];
////do
////{
////	bool sweating = "Sweating";
////	bool trembling = "Trembling";
////	bool hunger = "Hunger";
////	bool dizziness = "Dizziness";
////
////	cout << "" << endl;
////
////} while (symptom != 'Y' && symptom != 'N'); // Loop until valid input (Y or N) is provided
////cout << " " << endl;
////
////if (symptom == 'Y')
////{
////	cout << "You may be experiencing in hypoglycemia.\n";
////}
////else
////{
////	cout << "You do not seem to have hypoglycemia.\n";
////}