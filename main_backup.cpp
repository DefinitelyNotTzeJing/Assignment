#define _CRT_SECURE_NO_DEPRECATE

// library
#include <iostream> //cin and cout
#include <iomanip> //setw, left, right, fixed
#include <climits> 
#include <cctype> //isalpha, isnum, isalnum, ispunc, isupper, islower
#include <cmath> //pow, abs, fabs, ceil, floor, sqrt
#include <cstring> //strcat, strncat, strcpy, strncpy
#include <ctime> 
#include <stdlib.h> 
#include <fstream> 
#include <string> 
#include <vector> 
using namespace std;




// typedef for client
typedef struct
{
	char username[50];
	char password[50];
	char ic[30];
	char contactnum[30];
	char status[20];
	char feedbacks[600];
}USER;

// typedef for doctor
typedef struct
{
	char d_name[50];
	char d_password[50];
	char d_ic[30];
	char d_contactnum[30];
}DOCTOR;




// Doctor login interface functions
void doctor_login_interface(DOCTOR d[], int* id_ptr);
int doctor_login(DOCTOR d[], int* i_ptr);
void doctor_signup(DOCTOR d[]);




// Patients login interface functions
void user_login_interface(USER c[], int* id_ptr);
int user_login(USER c[], int* i_ptr);
void user_signup(USER c[]);




// Doctor main menu functions
void doctor_mainmenu(USER c[], int id);
int doctor_resetpwd(DOCTOR d[], int* i_ptr);
void doctor_feedback(USER c[], int id);




// Patients main menu functions
void user_mainmenu(USER c[], int id);
int user_resetpwd(USER c[], int* i_ptr);
int user_update(USER c[], int id);
void diagnose(USER c[], int id);
int updatePhonenum(USER c[], int id);
int updateStatus(USER c[], int id);
void faq(USER c[], int id);
void feedback(USER c[], int id);




// Diagnose functions
void hyperglycemia_test(void);
void hypoglycemia_test(void);




//faq functions
void hyperglycemia_faq(USER c[], int id);
void hypoglycemia_faq(USER c[], int id);




//other functions
void exit(); // Function used to logout of the account
bool check_number(string str); //Check input is number or no




//                       _oo0oo_                                          _oo0oo_                  
//                      o8888888o                                        o8888888o
//                      88" . "88                                        88" . "88
//                      (| -_- |)                                        (| -_- |)
//                      0\  =  /0                                        0\  =  /0
//                    ___/`---'\___                                    ___/`---'\___
//                  .' \\|     |// '.                                .' \\|     |// '.
//                 / \\|||  :  |||// \							    / \\|||  :  |||// \
//                / _||||| -:- |||||- \							   / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |						  |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |						  | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /						  \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___						___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".				 ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |				| | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /				\  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====		=====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='						                  `=---='
//
//               佛祖保佑         永无BUG								佛祖保佑         永无BUG
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




//main function
int main()
{
	// Clear screen
	system("CLS");

	// Create an array of CLIENT structs
	USER c[20];
	DOCTOR d[20];

	// Open input files (patients)
	ifstream name_file("username.txt", ios::in);
	ifstream pass_file("userpassword.txt", ios::in);
	ifstream ic_file("useric.txt", ios::in);
	ifstream phonenum_file("userphone.txt", ios::in);
	ifstream stats_file("status.txt", ios::in);
	ifstream feedback_file("feedback.txt", ios::in);

	// Open input files (doctor)
	ifstream doc_name_file("d_username.txt", ios::in);
	ifstream doc_pass_file("d_password.txt", ios::in);
	ifstream doc_ic_file("d_ic.txt", ios::in);
	ifstream doc_phonenum_file("d_phone.txt", ios::in);

	// Check if file opening was successful (patient)
	if (!name_file)
		cout << "Error opening username file\n";
	else if (!pass_file)
		cout << "Error opening userpassword file\n";
	else if (!ic_file)
		cout << "Error opening useric file\n";
	else if (!phonenum_file)
		cout << "Error opening user phone number file\n";
	else if (!stats_file)
		cout << "Error opening user status file\n";
	else if (!feedback_file)
		cout << "Error opening user feedback file\n";
	else
	{
		// Read data from input files into the CLIENT array
		for (int i = 0; i < 20; i++)
		{
			name_file >> c[i].username;
			pass_file >> c[i].password;
			ic_file >> c[i].ic;
			phonenum_file >> c[i].contactnum;
			stats_file >> c[i].status;
			feedback_file >> c[i].feedbacks;
		}
		// Close input files
		name_file.close();
		pass_file.close();
		ic_file.close();
		phonenum_file.close();
		stats_file.close();
		feedback_file.close();
	}

	// Check if file opening was successful (doctor)
	if (!doc_name_file)
		cout << "Error opening doctor name file\n";
	else if (!doc_pass_file)
		cout << "Error opening doctor password file\n";
	else if (!doc_ic_file)
		cout << "Error opening doctor ic file\n";
	else if (!doc_phonenum_file)
		cout << "Error opening doctor phone number file\n";
	else
	{
		// Read data from input files into the CLIENT array
		for (int i = 0; i < 20; i++)
		{
			doc_name_file >> d[i].d_name;
			doc_pass_file >> d[i].d_password;
			doc_ic_file >> d[i].d_ic;
			doc_phonenum_file >> d[i].d_contactnum;
		}
		// Close input files
		doc_name_file.close();
		doc_pass_file.close();
		doc_ic_file.close();
		doc_phonenum_file.close();
	}

	// Call login interface function
	int decision;
	int id;
	do {
		cout << "Are you a doctor or patient?";
		cout << endl;
		cout << "<1> Patient" << endl;
		cout << "<2> Doctor" << endl;
		cout << "--->\t";
		cin >> decision;
	} while (decision != 1 && decision != 2);

	// Login and call respective main menu function
	if (decision == 1)
	{
		user_login_interface(c, &id);
		user_mainmenu(c, id);
	}
	else
	{
		doctor_login_interface(d, &id);
		doctor_mainmenu(c, id);
	}
	return 0;
}

//function to validate if the string is number
bool check_number(string str) {
	for (int i = 0; i < str.length(); i++) {
		// Check if the character at position i is not a digit
		if (isdigit(str[i]) == false) {
			return false; // If a non-digit character is found, return false
		}
	}
	return true; // If all characters are digits, return true
}



//user login function definitions
void user_login_interface(USER c[], int* id_ptr)
{
	char interfaceAns;
	do
	{
		cout << "\nDo you want to <L>ogin or <S>ign up or <R>eset password? >>> ";
		cin >> interfaceAns;
		interfaceAns = toupper(interfaceAns);
	} while (interfaceAns != 'L' && interfaceAns != 'S' && interfaceAns != 'R');

	int i;

	if (interfaceAns == 'L') // If user chooses to login
	{
		user_login(c, &i); // Call the login function to perform login process
		*id_ptr = i; // Store the user ID in the memory location pointed by id_ptr
	}
	else if (interfaceAns == 'S') // If user chooses to sign up
	{
		user_signup(c); // Call the signup function to perform sign up process
	}
	else if (interfaceAns == 'R') // If user chooses to reset password
	{
		user_resetpwd(c, &i); // Call the resetpwd function to perform password reset process
		*id_ptr = i; // Store the user ID in the memory location pointed by id_ptr
		main(); // Call the main function to restart the program after password reset
	}

	return;
}

//function for user login
int user_login(USER c[], int* i_ptr)
{
	char username[50], password[50];
	bool userpassopt, usernameopt;

	int i;
	do
	{
		cin.ignore(1); // Ignore a single character in the input buffer to clear any remaining newline characters
		cout << "Please enter your username --> ";
		cin >> username; // Read user input for username

		cout << "Please enter your password --> ";
		cin >> password; // Read user input for password

		fflush(stdin); // Flush the input buffer to clear any remaining characters

		for (int i = 0; i < 50; i++) // Iterate through the array of CLIENT objects
		{
			if (strcmp(c[i].username, username) == 0) // Compare the entered username with the username in CLIENT object
			{
				usernameopt = true; // Set usernameopt flag to true indicating username match

				if (strcmp(c[i].password, password) == 0) // Compare the entered password with the password in CLIENT object
				{
					userpassopt = true; // Set userpassopt flag to true indicating password match
					*i_ptr = i; // Store the index of the matched CLIENT object in the memory location pointed by i_ptr
					break; // Break out of the loop as the login is successful
				}
				else
				{
					userpassopt = false; // Set userpassopt flag to false indicating incorrect password
				}
			}
			else
			{
				usernameopt = false; // Set usernameopt flag to false indicating no username match
			}
		}

		if ((userpassopt == false || usernameopt == false))
		{
			cout << "\nIncorrect password or username\n" << endl; // Display error message for incorrect username or password
		}
		else
		{
			cout << "\nLogin successful\n" << endl; // Display success message for successful login
		}

	} while (usernameopt == false); // Continue looping until a valid username is entered

	return 0;
}

//function for user to signup
void user_signup(USER c[])
{
	int phone_len, ic_len;
	string name, password1, password2, contact_num, ic, stats, temp_feedback;
	bool validate, validrange, validateic, validrangeic, validate2, validrangephone;
	validateic = true;
	validate2 = true;
	validate = true;
	stats = "NULL";
	temp_feedback = "NULL";

	// Get user's name
	cout << "Please enter your name: ";
	getline(cin >> ws, name);

	// Get user's IC number
	cout << "Please enter your ic number without '-' (123456789012): ";
	do
	{
		cin >> ic;
		// Validate if IC number is a number
		bool validateic = check_number(ic);
		if (validateic == true)
		{
			char icarray[30];
			strcpy(icarray, ic.c_str());
			ic_len = strlen(icarray);
			// Check if IC number length is within valid range (11 to 13)
			if ((ic_len < 13) && (ic_len > 11))
			{
				validrangeic = true;
			}
			else
			{
				validrangeic = false;
			}
		}
		else
		{
			cout << "Invalid input" << endl;
		}

		if (validateic == false || validrangeic == false)
			cout << "Please enter your ic again: ";

	} while (validateic == false || validrangeic == false);

	// Get user's contact number
	cout << "Please enter your contact number without '-' (i.e:0183958711): ";
	do
	{
		cin >> contact_num;
		// Validate if contact number is a number
		bool validate2 = check_number(contact_num);
		char contactnumarray[30];
		strcpy(contactnumarray, contact_num.c_str());
		phone_len = strlen(contactnumarray);
		// Check if contact number length is within valid range (10 to 13)
		if ((phone_len <= 13) && (phone_len >= 10))
		{
			validrangephone = true;
		}
		else
		{
			validrangephone = false;
		}
		if (validate2 == false || validrangephone == false)
		{
			cout << "Invalid input" << endl;
			cout << "Please enter your contact number again without '-' (i.e:0183958711): ";
		}
	} while (validate2 == false || validrangephone == false);

	// Get user's password
	do
	{
		cout << "Please enter your password: ";
		cin >> password1;

		cout << "Please enter your password again: ";
		cin >> password2;
		if (password1 != password2)
		{
			cout << "Different password entered \n"; // Prompt user that different passwords were entered
			cout << "Please try again\n"; // Prompt user to try again
			cout << "Please enter your password: "; // Prompt user to enter password again
			cin >> password1;

			cout << "Please enter your password again: "; // Prompt user to enter password again
			cin >> password2;
		}

	} while (password1 != password2); // Repeat until password1 and password2 match


	ofstream passwordfile("userpassword.txt", ios::app); // Create an output file stream to append to userpassword.txt file
	passwordfile << password2 << endl; // Write password2 to userpassword.txt followed by newline


	ofstream username("username.txt", ios::app); // Create an output file stream to append to username.txt file
	username << name << endl; // Write name to username.txt followed by newline


	ofstream phonenumfile("userphone.txt", ios::app); // Create an output file stream to append to userphone.txt file
	phonenumfile << contact_num << endl; // Write contact_num to userphone.txt followed by newline


	ofstream icfile("useric.txt", ios::app); // Create an output file stream to append to useric.txt file
	icfile << ic << endl; // Write ic to useric.txt followed by newline


	ofstream stats_file("status.txt", ios::app); // Create an output file stream to append to status.txt file
	stats_file << stats << endl; // Write status to status.txt followed by newline


	ofstream feedback_file("feedback.txt", ios::app); // Create an output file stream to append to feedback.txt file
	feedback_file << temp_feedback << endl; // Write a temporary feedback to feedback.txt followed by newline


	system("CLS"); // Clear screen
	cout << "Sign up complete \n"; // Prompt user that sign up is complete
	main(); // Call main() function to restart the program
}

//function to reset user's password
int user_resetpwd(USER c[], int* i_ptr)
{
	// Input for username and new password
	string username, resetpassword;
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your new password: ";
	cin >> resetpassword;

	string usernameToFind = username; // Username to find
	string newPassword = resetpassword; // New password to replace

	// Open the username text file for reading
	ifstream usernameFile("username.txt");
	if (!usernameFile.is_open()) {
		cout << "Failed to open username file." << endl;
		//return 1;
	}

	// Open the password text file for reading
	ifstream passwordFile("userpassword.txt");
	if (!passwordFile.is_open()) {
		cout << "Failed to open password file." << endl;
		usernameFile.close();
		//return 1;
	}

	vector<string> usernames; // Vector to store usernames from file
	vector<string> passwords; // Vector to store passwords from file
	string line;

	// Read usernames and passwords from the files into memory
	while (getline(usernameFile, line)) {
		usernames.push_back(line);
		getline(passwordFile, line);
		passwords.push_back(line);
	}

	usernameFile.close(); // Close username file
	passwordFile.close(); // Close password file

	// Search for the username to find and update the corresponding password
	bool found = false;
	for (size_t i = 0; i < usernames.size(); ++i) {
		if (usernames[i] == usernameToFind) {
			found = true;
			passwords[i] = newPassword; // Update password
			*i_ptr = i; // Store index of updated password
			break;
		}
	}

	if (found) {
		// Write the updated passwords back to the password file
		ofstream updatedPasswordFile("userpassword.txt");
		if (!updatedPasswordFile.is_open()) {
			cout << "Failed to open updated password file." << endl;
			return 1;
		}

		for (size_t i = 0; i < passwords.size(); ++i) {
			updatedPasswordFile << passwords[i] << endl;
		}

		updatedPasswordFile.close(); // Close updated password file

		cout << "Password updated successfully." << endl;

	}
	else {
		cout << "Username not found." << endl;
	}
	return 0;
}




// doctor login function definitions
void doctor_login_interface(DOCTOR d[], int* id_ptr)
{
	char interfaceAns;
	do
	{
		cout << "\nDo you want to <L>ogin or <S>ign up or <R>eset password? >>> ";
		cin >> interfaceAns;
		interfaceAns = toupper(interfaceAns);
	} while (interfaceAns != 'L' && interfaceAns != 'S' && interfaceAns != 'R');

	int i;

	if (interfaceAns == 'L') // If doctor chooses to login
	{
		doctor_login(d, &i); // Call the login function to perform login process
		*id_ptr = i; // Store the user ID in the memory location pointed by id_ptr
	}
	else if (interfaceAns == 'S') // If user chooses to sign up
	{
		doctor_signup(d); // Call the signup function to perform sign up process
	}
	else if (interfaceAns == 'R') // If user chooses to reset password
	{
		doctor_resetpwd(d, &i); // Call the resetpwd function to perform password reset process
		*id_ptr = i; // Store the user ID in the memory location pointed by id_ptr
		main(); // Call the main function to restart the program after password reset
	}

	return;
}

//function for doctor login
int doctor_login(DOCTOR d[], int* i_ptr)
{
	char username[50], password[50];
	bool userpassopt, usernameopt;

	int i;
	do
	{
		cin.ignore(1); // Ignore a single character in the input buffer to clear any remaining newline characters
		cout << "Please enter your username --> ";
		cin >> username; // Read user input for username

		cout << "Please enter your password --> ";
		cin >> password; // Read user input for password

		fflush(stdin); // Flush the input buffer to clear any remaining characters

		for (int i = 0; i < 50; i++) // Iterate through the array of CLIENT objects
		{
			if (strcmp(d[i].d_name, username) == 0) // Compare the entered username with the username in CLIENT object
			{
				usernameopt = true; // Set usernameopt flag to true indicating username match

				if (strcmp(d[i].d_password, password) == 0) // Compare the entered password with the password in CLIENT object
				{
					userpassopt = true; // Set userpassopt flag to true indicating password match
					*i_ptr = i; // Store the index of the matched CLIENT object in the memory location pointed by i_ptr
					break; // Break out of the loop as the login is successful
				}
				else
				{
					userpassopt = false; // Set userpassopt flag to false indicating incorrect password
				}
			}
			else
			{
				usernameopt = false; // Set usernameopt flag to false indicating no username match
			}
		}

		if ((userpassopt == false || usernameopt == false))
		{
			cout << "\nIncorrect password or username\n" << endl; // Display error message for incorrect username or password
		}
		else
		{
			cout << "\nLogin successful\n" << endl; // Display success message for successful login
		}

	} while (usernameopt == false); // Continue looping until a valid username is entered

	return 0;
}

//function for doctor to signup
void doctor_signup(DOCTOR d[])
{
	int phone_len, ic_len;
	string name, password1, password2, contact_num, ic;
	bool validate, validrange, validateic, validrangeic, validate2, validrangephone;
	validateic = true;
	validate2 = true;
	validate = true;

	// Get doctor's name
	cout << "Please enter your name: ";
	getline(cin >> ws, name);

	// Get user's IC number
	cout << "Please enter your ic number without '-' (123456789012): ";
	do
	{
		cin >> ic;
		// Validate if IC number is a number
		bool validateic = check_number(ic);
		if (validateic == true)
		{
			char icarray[30];
			strcpy(icarray, ic.c_str());
			ic_len = strlen(icarray);
			// Check if IC number length is within valid range (11 to 13)
			if ((ic_len < 13) && (ic_len > 11))
			{
				validrangeic = true;
			}
			else
			{
				validrangeic = false;
			}
		}
		else
		{
			cout << "Invalid input" << endl;
		}

		if (validateic == false || validrangeic == false)
			cout << "Please enter your ic again: ";

	} while (validateic == false || validrangeic == false);

	// Get user's contact number
	cout << "Please enter your contact number without '-' (i.e:0183958711): ";
	do
	{
		cin >> contact_num;
		// Validate if contact number is a number
		bool validate2 = check_number(contact_num);
		char contactnumarray[30];
		strcpy(contactnumarray, contact_num.c_str());
		phone_len = strlen(contactnumarray);
		// Check if contact number length is within valid range (10 to 13)
		if ((phone_len <= 13) && (phone_len >= 10))
		{
			validrangephone = true;
		}
		else
		{
			validrangephone = false;
		}
		if (validate2 == false || validrangephone == false)
		{
			cout << "Invalid input" << endl;
			cout << "Please enter your contact number again without '-' (i.e:0183958711): ";
		}
	} while (validate2 == false || validrangephone == false);

	// Get user's password
	do
	{
		cout << "Please enter your password: ";
		cin >> password1;

		cout << "Please enter your password again: ";
		cin >> password2;
		if (password1 != password2)
		{
			cout << "Different password entered \n"; // Prompt user that different passwords were entered
			cout << "Please try again\n"; // Prompt user to try again
			cout << "Please enter your password: "; // Prompt user to enter password again
			cin >> password1;

			cout << "Please enter your password again: "; // Prompt user to enter password again
			cin >> password2;
		}

	} while (password1 != password2); // Repeat until password1 and password2 match


	ofstream passwordfile("d_password.txt", ios::app); // Create an output file stream to append to doctor_password.txt file
	passwordfile << password2 << endl; // Write password2 to doctor_password.txt followed by newline


	ofstream username("d_username.txt", ios::app); // Create an output file stream to append to doctor_name.txt file
	username << name << endl; // Write name to doctor_name.txt followed by newline


	ofstream phonenumfile("d_phone.txt", ios::app); // Create an output file stream to append to doctor_phone.txt file
	phonenumfile << contact_num << endl; // Write contact_num to doctor_phone.txt followed by newline


	ofstream icfile("d_ic.txt", ios::app); // Create an output file stream to append to doctor_ic.txt file
	icfile << ic << endl; // Write ic to doctor_ic.txt followed by newline


	system("CLS"); // Clear screen
	cout << "Sign up complete \n"; // Prompt user that sign up is complete
	main(); // Call main() function to restart the program
}

//function to reset doctor's password
int doctor_resetpwd(DOCTOR d[], int* i_ptr)
{
	// Input for username and new password
	string username, resetpassword;
	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your new password: ";
	cin >> resetpassword;

	string usernameToFind = username; // Username to find
	string newPassword = resetpassword; // New password to replace

	// Open the username text file for reading
	ifstream usernameFile("d_username.txt");
	if (!usernameFile.is_open()) {
		cout << "Failed to open doctor_name file." << endl;
		//return 1;
	}

	// Open the password text file for reading
	ifstream passwordFile("d_password.txt");
	if (!passwordFile.is_open()) {
		cout << "Failed to open d_password file." << endl;
		usernameFile.close();
		//return 1;
	}

	vector<string> usernames; // Vector to store usernames from file
	vector<string> passwords; // Vector to store passwords from file
	string line;

	// Read usernames and passwords from the files into memory
	while (getline(usernameFile, line))
	{
		usernames.push_back(line);
		getline(passwordFile, line);
		passwords.push_back(line);
	}

	usernameFile.close(); // Close username file
	passwordFile.close(); // Close password file

	// Search for the username to find and update the corresponding password
	bool found = false;
	for (size_t i = 0; i < usernames.size(); ++i) {
		if (usernames[i] == usernameToFind) {
			found = true;
			passwords[i] = newPassword; // Update password
			*i_ptr = i; // Store index of updated password
			break;
		}
	}

	if (found) {
		// Write the updated passwords back to the password file
		ofstream updatedPasswordFile("d_password.txt");
		if (!updatedPasswordFile.is_open()) {
			cout << "Failed to open updated password file." << endl;
			return 1;
		}

		for (size_t i = 0; i < passwords.size(); ++i) {
			updatedPasswordFile << passwords[i] << endl;
		}

		updatedPasswordFile.close(); // Close updated password file

		cout << "Password updated successfully." << endl;

	}
	else {
		cout << "Username not found." << endl;
	}
	return 0;
}



// main menu function definitions
void user_mainmenu(USER c[], int id)
{
	system("CLS"); // Clear the screen
	time_t ttime = time(0); // Variable to store current time
	char* dt = ctime(&ttime); // Get current time as string
	cout << "Today's Date and Time -->\t" << dt << endl; // Print current date and time
	char status = ' '; // Variable to store status
	cout << "========================================================================================================================" << endl;
	cout << left << setw(25) << "Name" << left << setw(20) << "Ic number" << left << setw(23) << "Contact Number" << left << setw(25) << "Status" << left << setw(18) << endl; // Display column headers
	cout << "========================================================================================================================" << endl;
	cout << left << setw(25);
	cout << c[id].username; // Display username from the USER array
	cout << left << setw(20);
	cout << c[id].ic; // Display IC number from the USER array
	cout << left << setw(23);
	cout << c[id].contactnum; // Display contact number from the USER array
	cout << left << setw(25);
	cout << c[id].status; // Display status from the USER array
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	char ans;

	do {
		cout << "Press <1> to do diagnose" << endl; // Display menu option
		cout << "Press <2> to update your user profile" << endl; // Display menu option
		cout << "Press <3> to review the FAQ" << endl; // Display menu option
		cout << "Press <4> to review feedback from doctor" << endl; //Display doctor feedback 
		cout << "Press <5> to Exit" << endl << endl; // Display menu option
		cout << "--->";
		cin >> ans; // Get user input
		cout << endl;
	} while (ans != '1' && ans != '2' && ans != '3' && ans != '4' && ans != '5'); // Continue to display the menu if input is invalid

	if (ans == '1')
	{
		system("CLS"); // Clear the screen
		diagnose(c, id); // Call the diagnose() function to diagnose
	}

	else if (ans == '2')
	{
		system("CLS"); // Clear the screen
		user_update(c, id); // Call the userupdate() function
	}

	else if (ans == '3')
	{
		system("CLS"); // Clear the screen
		faq(c, id); // Call the faq() function
	}

	else if (ans == '4')
	{
		system("CLS"); // Clear the screen
		feedback(c, id); // Call the feedback() function
	}

	else if (ans == '5')
	{
		system("CLS"); // Clear the screen
		exit(); // Call the exit() function
	}

	else
	{
		cout << "invalid input please try again"; // Display error message
		user_mainmenu(c, id); // Call the user_mainmenu() function recursively to retry
	}

	return; // Return from the function
}

//function for user to diagnose their status
void diagnose(USER c[], int id)
{
	int disease; //1 for hyperglycemia, 2 for hypoglycemia, 3 for back to mainmenu
	do {
		cout << "Diagnose interface:\n\n";
		cout << "<1> Hyperglycemia test\n";
		cout << "<2> Hypoglycemia test\n";
		cout << "<3> Back to main menu\n\n";
		cout << "--->\t";
		cin >> disease;
	} while (disease != 1 && disease != 2 && disease != 3);

	if (disease == 1)
		hyperglycemia_test();
	else if (disease == 2)
		hypoglycemia_test();
	else
		user_mainmenu(c, id);
}

//hyperglycemia test, if has the symptoms, yes +1, if yes > 3, u have hyperglycemia
void hyperglycemia_test(void)
{
	system("CLS");
	int yes = 0;
	char ans1, ans2, ans3, ans4, ans5, ans6;
	cout << "Hyperglycemia test:\n";

	do {
		cout << "1. Do you have frequent urine? <Y/N>\t\t>>> ";
		cin >> ans1;
		ans1 = toupper(ans1);
	} while (ans1 != 'Y' && ans1 != 'N');

	if (ans1 == 'Y')
		yes++;


	do {
		cout << "2. Do you have excessive thirst? <Y/N>\t\t>>> ";
		cin >> ans2;
		ans2 = toupper(ans2);
	} while (ans2 != 'Y' && ans2 != 'N');

	if (ans2 == 'Y')
		yes++;


	do {
		cout << "3. Do you have dry mouth? <Y/N>\t\t\t>>> ";
		cin >> ans3;
		ans3 = toupper(ans3);
	} while (ans3 != 'Y' && ans3 != 'N');

	if (ans3 == 'Y')
		yes++;


	do {
		cout << "4. Do you have exhaustion? <Y/N>\t\t>>> ";
		cin >> ans4;
		ans4 = toupper(ans4);
	} while (ans4 != 'Y' && ans4 != 'N');

	if (ans4 == 'Y')
		yes++;


	do {
		cout << "5. Do you have nausea? <Y/N>\t\t\t>>> ";
		cin >> ans5;
		ans5 = toupper(ans5);
	} while (ans5 != 'Y' && ans5 != 'N');

	if (ans5 == 'Y')
		yes++;


	do {
		cout << "6. Do you have high blood sugar? <Y/N>\t\t>>> ";
		cin >> ans6;
		ans6 = toupper(ans6);
	} while (ans6 != 'Y' && ans6 != 'N');

	if (ans6 == 'Y')
		yes++;

	if (yes > 3)
		cout << "\n\nYou might have hyperglycemia, please update your user profile before seek help from doctor for more informations\n";
	else
		cout << "\n\nCongratulations, you doesn't seems like you are having hyperglycemia\n";
}

//hypoglycemia test, if has the symptoms, yes +1, if yes > 3, u have hypoglycemia
void hypoglycemia_test(void)
{
	system("CLS");
	int yes = 0;
	char ans1, ans2, ans3, ans4, ans5, ans6;
	cout << "Hypoglycemia test:\n";

	do {
		cout << "1. Do you sweat a lot? <Y/N>\t\t>>> ";
		cin >> ans1;
		ans1 = toupper(ans1);
	} while (ans1 != 'Y' && ans1 != 'N');

	if (ans1 == 'Y')
		yes++;


	do {
		cout << "2. Do you shiver frequently? <Y/N>\t\t>>> ";
		cin >> ans2;
		ans2 = toupper(ans2);
	} while (ans2 != 'Y' && ans2 != 'N');

	if (ans2 == 'Y')
		yes++;


	do {
		cout << "3. Do you have a quick heartbeat? <Y/N>\t\t>>> ";
		cin >> ans3;
		ans3 = toupper(ans3);
	} while (ans3 != 'Y' && ans3 != 'N');

	if (ans3 == 'Y')
		yes++;


	do {
		cout << "4. Do you have low blood sugar? <Y/N>\t\t>>> ";
		cin >> ans4;
		ans4 = toupper(ans4);
	} while (ans4 != 'Y' && ans4 != 'N');

	if (ans4 == 'Y')
		yes++;


	do {
		cout << "5. Do you have headache? <Y/N>\t\t>>> ";
		cin >> ans5;
		ans5 = toupper(ans5);
	} while (ans5 != 'Y' && ans5 != 'N');

	if (ans5 == 'Y')
		yes++;


	do {
		cout << "6. Do you have blurred vision? <Y/N>\t\t>>> ";
		cin >> ans6;
		ans6 = toupper(ans6);
	} while (ans6 != 'Y' && ans6 != 'N');

	if (ans6 == 'Y')
		yes++;

	if (yes > 3)
		cout << "\n\nYou might have hypoglycemia, please seek help from doctor for more informations\n";
	else
		cout << "\n\nCongratulations, you doesn't seems like you are having hypoglycemia\n";
}




//function for user to update their info
int user_update(USER c[], int id)
{
	char choice;
	cout << "    Name: " << c[id].username << endl; // Displaying current name
	cout << "    Ic number: " << c[id].ic << endl; // Displaying current IC number
	cout << "<1> Contact number: " << c[id].contactnum << endl; // Displaying current contact number
	cout << "<2> Status: " << c[id].status << endl; // Displaying current status
	cout << "---------------------------------------------------" << endl; // Displaying separator line
	cout << "Enter number to change: "; // Prompting user to enter their choice
	cin >> choice; // Reading user's choice

	switch (choice)
	{
	case '1':
		updatePhonenum(c, id); // Calling function to update contact number
		break;
	case '2':
		updateStatus(c, id); // Calling function to update status
		break;
	default:
		user_update(c, id); // If invalid choice, recursively calling the same function again
		break;
	}
	return 0;
}

//function for user to update their contact number
int updatePhonenum(USER c[], int id)
{
	string resetphonenum;
	cout << "Enter your new contact number: "; // Prompting user to enter new contact number
	cin >> resetphonenum; // Reading new contact number from user

	string usernameToFind = c[id].username; // Username to find
	string newPhonenum = resetphonenum;

	ifstream usernameFile("username.txt"); // Opening username file for reading
	if (!usernameFile.is_open()) {
		cout << "Failed to open username file." << endl; // Displaying error message if failed to open file
		return 1;
	}

	ifstream phonenumFile("userphone.txt"); // Opening userphone file for reading
	if (!phonenumFile.is_open()) {
		cout << "Failed to open phone number file." << endl; // Displaying error message if failed to open file
		usernameFile.close();
		return 1;
	}

	vector<string> usernames; // Vector to store usernames
	vector<string> phonenum; // Vector to store contact numbers
	string line;

	// Reading usernames and contact numbers from respective files
	while (getline(usernameFile, line)) {
		usernames.push_back(line);
		getline(phonenumFile, line);
		phonenum.push_back(line);
	}

	usernameFile.close();
	phonenumFile.close();

	bool found = false;
	for (size_t i = 0; i < usernames.size(); ++i) {
		if (usernames[i] == usernameToFind) { // Finding username in the vector
			found = true;
			phonenum[i] = newPhonenum; // Updating contact number in the vector
			break;
		}
	}

	if (found) {
		ofstream updatedPhonenumFile("userphone.txt"); // Opening userphone file for writing
		if (!updatedPhonenumFile.is_open()) {
			cout << "Failed to open updated phonenum file." << endl; // Displaying error message if failed to open file
			return 1;
		}

		// Writing updated contact numbers to the file
		for (size_t i = 0; i < phonenum.size(); ++i) {
			updatedPhonenumFile << phonenum[i] << endl;
		}

		updatedPhonenumFile.close();

		cout << "Contact number updated successfully." << endl; // Displaying success message
	}
	else {
		cout << "Username not found." << endl; // Displaying error message if username not found
	}

	return 0;
}

//function for user to update their status
int updateStatus(USER c[], int id)
{
	string resetstatus;
	do {
		cout << "\n\nEnter your new status:\n";
		cout << "<1> Hyperglycemia\n";
		cout << "<2> Hypoglycemia\n";
		cout << "--->\t";
		cin >> resetstatus; // Get the new status from user input
	} while (resetstatus != "1" && resetstatus != "2" && resetstatus != "3");

	if (resetstatus == "1")
		resetstatus = "Hyperglycemia";
	else
		resetstatus = "Hypoglycemia";

	string usernameToFind = c[id].username; // Username to find
	string newstatus = resetstatus; // Store the new status

	// Open the username text file for reading
	ifstream usernameFile("username.txt");
	if (!usernameFile.is_open()) {
		cout << "Failed to open username file." << endl;
		return 1;
	}

	// Open the status text file for reading
	ifstream statusFile("status.txt");
	if (!statusFile.is_open()) {
		cout << "Failed to open status file." << endl;
		usernameFile.close();
		return 1;
	}

	vector<string> usernames;
	vector<string> status;
	string line;

	// Read usernames and status from the files into memory
	while (getline(usernameFile, line)) {
		usernames.push_back(line);
		getline(statusFile, line);
		status.push_back(line);
	}

	usernameFile.close();
	statusFile.close();

	bool found = false;
	// Search for the username to find and update the corresponding status
	for (size_t i = 0; i < usernames.size(); ++i) {
		if (usernames[i] == usernameToFind) {
			found = true;
			status[i] = newstatus; // Update the status
			break;
		}
	}

	if (found) {
		// Write the updated status back to the status file
		ofstream updatedstatusFile("status.txt");
		if (!updatedstatusFile.is_open()) {
			cout << "Failed to open updated status file." << endl;
			return 1;
		}

		for (size_t i = 0; i < status.size(); ++i) {
			updatedstatusFile << status[i] << endl;
		}

		updatedstatusFile.close();

		cout << "Status updated successfully." << endl;
	}
	else {
		cout << "Username not found." << endl;
	}

	return 0;
}




//function for FAQ
void faq(USER c[], int id)
{
	char choose;
	do
	{
		system("CLS");
		cout << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "This is FAQ:" << endl;
		cout << endl;
		cout << "<1> Questions about Hyperglycemia" << endl;
		cout << "<2> Questions about Hypoglycemia" << endl;
		cout << "<3> Back to Main Menu" << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "Please type in number\t>>> ";
		cin >> choose;
		cout << "" << endl;

		if (choose != '1' && choose != '2' && choose != '3')
		{
			system("CLS");
			cout << "Invalid input, please type in a valid number!";
		}

	} while (choose != '1' && choose != '2' && choose != '3');

	//------------------------FAQ main page--------------------------------

	if (choose == '1')
	{
		system("CLS");
		hyperglycemia_faq(c, id);
	}

	else if (choose == '2')
	{
		system("CLS");
		hypoglycemia_faq(c, id);
	}

	else
	{
		system("CLS");
		user_mainmenu(c, id);
	}
}

void hyperglycemia_faq(USER c[], int id)
{
	char choose;
	do
	{
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "Here are most frequent question asked:" << endl;
		cout << endl;
		cout << "<1> What is hyperglycemia?" << endl;
		cout << "<2> What are the symptoms of hyperglycemia?" << endl;
		cout << "<3> Can hyperglycemia be dangerous?" << endl;
		cout << "<4> What foods should I avoid during hyperglycemia?" << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "Type in a number\t>>> ";
		cin >> choose;

		if (choose != '1' && choose != '2' && choose != '3' && choose != '4')
		{
			system("CLS");
			cout << "Invalid input, please type in a valid number!";
		}

	} while (choose != '1' && choose != '2' && choose != '3' && choose != '4');

	//----------------------Hyperglycemia faq main page---------------------

	if (choose == '1')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "What is hyperglycemia?" << endl;
		cout << endl;
		cout << "High blood sugar levels characterize the disease known as hyperglycemia, " << endl;
		cout << "which is frequently linked to diabetes. It happens when the body can't" << endl;
		cout << " utilise insulin properly or doesn't produce enough of it." << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			cout << "wait for program done";
			//back to main menu
		}
	}

	if (choose == '2')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "What is the symptoms of hyperglycemia?" << endl;
		cout << endl;
		cout << "Frequent urine, excessive thirst, increased hunger, exhaustion, impaired vision, dry mouth, " << endl;
		cout << "sluggish wound healing, recurring infections, unexplained weight loss, and occasionally " << endl;
		cout << "disorientation or nausea are signs of hyperglycemia, or high blood sugar. These signs and " << endl;
		cout << "symptoms result from the body's failure to control blood sugar levels effectively. " << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			cout << "wait for program done";
			//back to main menu
		}

	}

	if (choose == '3')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "Can hyperglycemia be dangerous?" << endl;
		cout << endl;
		cout << "Yes, Diabetes complications, such as diabetic ketoacidosis (DKA) in Type 1 diabetes, " << endl;
		cout << "can result from persistent or extreme high blood sugar levels. In the extreme condition" << endl;
		cout << "known as DKA, the body begins metabolizing fat for energy, which causes an accumulation of" << endl;
		cout << "ketones and a risky change in blood pH. Persistent hyperglycemia in Type 2 diabetes can lead" << endl;
		cout << "to long-term issues with the heart, kidneys, nerves, vision, and blood vessels." << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			cout << "wait for program done";
			//back to main menu
		}
	}

	if (choose == '4')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "What foods should I avoid during hyperglycemia?" << endl;
		cout << endl;
		cout << "Its crucial to stay away from meals that might quickly boost blood sugar levels when you have hyperglycemia. " << endl;
		cout << "Sugary drinks, sweets, desserts, and other foods high in refined sugars are some examples.Limit your" << endl;
		cout << "intake of processed foods as well, especially those with high carbohydrate and sugar content. White bread, " << endl;
		cout << "white rice, and sugary cereals should be avoided. Instead, emphasize full,unprocessed foods that can help" << endl;
		cout << "regulate blood sugar levels and improve general health, such as vegetables, whole grains, lean meats, and healthy fats." << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			cout << "wait for program done";
			//back to main menu
		}
	}

}

void hypoglycemia_faq(USER c[], int id)
{
	char choose;
	do
	{
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "Here are most frequent question asked:" << endl;
		cout << endl;
		cout << "<1> What is hypoglycemia?" << endl;
		cout << "<2> What causes hypoglycemia?" << endl;
		cout << "<3> What are the symptoms of hypoglycemia？" << endl;
		cout << "<4> How can I prevent hypoglycemia?" << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "Type in a number\t>>> ";
		cin >> choose;

		if (choose != '1' && choose != '2' && choose != '3' && choose != '4')
		{
			system("CLS");
			cout << "Invalid input, please type in a valid number!";
		}

	} while (choose != '1' && choose != '2' && choose != '3' && choose != '4');

	//----------------------Hypoglycemia faq main page---------------------

	if (choose == '1')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "What is hypoglycemia?" << endl;
		cout << endl;
		cout << "Blood sugar levels that are excessively low, usually below 70 mg/dL, are indicative of the condition known" << endl;
		cout << "as hypoglycemia. From minor pain to serious consequences, it may produce symptoms." << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			system("CLS");
			user_mainmenu(c, id);
		}

	}

	if (choose == '2')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "What causes hypoglycemia?" << endl;
		cout << endl;
		cout << "If you take too much insulin or some diabetic drugs, skip meals, exercise a lot without adjusting" << endl;
		cout << "your insulin or food intake, take alcohol without eating enough, or postpone or skip meals," << endl;
		cout << "you could develop hypoglycemia." << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			cout << "wait for program done";
			//back to main menu
		}

	}

	if (choose == '3')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "What are the symptoms of hypoglycemia？" << endl;
		cout << endl;
		cout << "Shivering, sweating, dizziness, irritability, a quick heartbeat, hunger, and confusion are just" << endl;
		cout << "a few of the symptoms of hypoglycemia, or low blood sugar. More severe cases may cause memory" << endl;
		cout << "loss, headaches, blurred vision, weakness, convulsions, or even coma. These signs and symptoms" << endl;
		cout << "appear because the brain uses glucose as fuel and is affected when blood sugar levels go too low." << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			cout << "wait for program done";
			//back to main menu
		}
	}

	if (choose == '4')
	{
		system("CLS");
		char choose_BM;
		//display information for faq of hyperglycemia
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "WHow can I prevent hypoglycemia?" << endl;
		cout << endl;
		cout << "Maintain a regular eating schedule with well-balanced meals and snacks to prevent hypoglycemia." << endl;
		cout << "Maintain regular blood sugar monitoring, and adjust insulin or medicine dosages as necessary." << endl;
		cout << "To swiftly treat moderate episodes, carry fast-acting carbs like glucose pills, fruit juice, or candies." << endl;
		cout << " If you want to exercise, check your blood sugar levels before and after, and make any necessary diet" << endl;
		cout << " or insulin adjustments. To fine-tune your management strategy and reduce the risk of hypoglycemia," << endl;
		cout << " communication with your healthcare practitioner and diabetes care team is crucial." << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "<B>ack		<M>ain menu" << endl;
		cout << "(B/M)?--->";
		cin >> choose_BM;

		// Take user input for choice and convert it to uppercase
		choose_BM = toupper(choose_BM);

		// Validate user input and loop until a valid choice is entered
		while (choose_BM != 'B' && choose_BM != 'M')
		{
			cout << "Invalid input, please try again" << endl;
			cout << "(B/M)?--->";
			cin >> choose_BM;
			choose_BM = toupper(choose_BM);
		}

		// Based on user choice, call appropriate functions (faq or mainmenu)
		if (choose_BM == 'B')
		{
			faq(c, id);
		}
		else if (choose_BM == 'M')
		{
			cout << "wait for program done";
			//back to main menu
		}
	}

}




// Doctor login function definition
void doctor_mainmenu(USER c[], int id)
{
	system("CLS"); // Clear the screen
	time_t ttime = time(0); // Variable to store current time
	char* dt = ctime(&ttime); // Get current time as string
	cout << "Today's Date and Time -->\t" << dt << endl; // Print current date and time
	char status = ' '; // Variable to store status
	cout << "========================================================================================================================" << endl;
	cout << "No.\t" << left << setw(25) << "Name" << left << setw(20) << "Ic number" << left << setw(23) << "Contact Number" << left << setw(25) << "Status" << left << setw(18) << endl; // Display column headers
	cout << "========================================================================================================================" << endl;
	for (int id = 0; id < 20; id++)
	{
		cout << id + 1 << ".\t";
		cout << left << setw(25);
		cout << c[id].username; // Display username from the USER array
		cout << left << setw(20);
		cout << c[id].ic; // Display IC number from the USER array
		cout << left << setw(23);
		cout << c[id].contactnum; // Display contact number from the USER array
		cout << left << setw(25);
		cout << c[id].status; // Display status from the USER array
		cout << endl;
	}
	cout << endl;
	cout << endl;
	int decision;
	do {

		cout << "\nPlease enter numerical numbers only\n";
		cout << "Enter the index number of the patient to provide feedback:\t>>> ";
		cin >> decision;
	} while (decision < 1 || decision > 20);
	decision--;

	//make decision redirect to the specific patient and record down the feedback in feedback.txt
	doctor_feedback(c, decision);
}




//patient feedback
void feedback(USER c[], int id)
{

	char ans;
	do
	{
		system("CLS");
		cout << "Username:\t\t" << c[id].username << endl;
		cout << "User ic:\t\t" << c[id].ic << endl;
		cout << "User status:\t\t" << c[id].status << endl;
		cout << "Feedback:\t\t" << c[id].feedbacks << endl;
		cout << "\n\n\n";
		cout << "Enter <B> to back to main menu\t >>> ";
		cin >> ans;
		ans = toupper(ans);
	} while (ans != 'B');

	user_mainmenu(c, id);
}




//doctor feedback
void doctor_feedback(USER c[], int id)
{
	cin.clear();
	system("CLS");
	string d_feedback;
	cout << "Name\t\t\t\t\t: " << c[id].username << endl;
	cout << "Contact Number\t\t\t\t: " << c[id].contactnum << endl;
	cout << "Feedback (Use \"_\" as the spacing)\t: "; // Prompting doctor to enter new feedback
	cin >> d_feedback; // Reading new feedback from user

	string usernameToFind = c[id].username; // Username to find
	string newFeedback = d_feedback;

	ifstream usernameFile("username.txt"); // Opening username file for reading
	if (!usernameFile.is_open()) {
		cout << "Failed to open username file." << endl; // Displaying error message if failed to open file
		//return 1;
	}

	ifstream feedbackFile("feedback.txt"); // Opening feedback file for reading
	if (!feedbackFile.is_open()) {
		cout << "Failed to open feedback file." << endl; // Displaying error message if failed to open file
		usernameFile.close();
		//return 1;
	}

	vector<string> usernames; // Vector to store usernames
	vector<string> feedbacks; // Vector to store feedback
	string line;

	// Reading usernames and feedback from respective files
	while (getline(usernameFile, line)) {
		usernames.push_back(line);
		getline(feedbackFile, line);
		feedbacks.push_back(line);
	}

	usernameFile.close();
	feedbackFile.close();

	bool found = false;
	for (size_t i = 0; i < usernames.size(); ++i) {
		if (usernames[i] == usernameToFind) { // Finding username in the vector
			found = true;
			feedbacks[i] = newFeedback; // Updating feedback in the vector
			break;
		}
	}

	if (found) {
		ofstream updatedFeedbackFile("feedback.txt"); // Opening feedback file for writing
		if (!updatedFeedbackFile.is_open()) {
			cout << "Failed to open updated feedback file." << endl; // Displaying error message if failed to open file
			//return 1;
		}

		// Writing updated feedback to the file
		for (size_t i = 0; i < feedbacks.size(); ++i) {
			updatedFeedbackFile << feedbacks[i] << endl;
		}

		updatedFeedbackFile.close();

		cout << "Feedback updated successfully." << endl; // Displaying success message
	}
	else {
		cout << "Username not found." << endl; // Displaying error message if username not found
	}

	//return 0;
}




// Exit (logout)
void exit()
{
	cout << "EXIT" << endl;
	cout << "Logged out successfully..." << endl;
}