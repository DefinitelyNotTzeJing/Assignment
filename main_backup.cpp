//#define _CRT_SECURE_NO_DEPRECATE
//
// library
//#include <iostream> //cin and cout
//#include <iomanip> //setw, left, right, fixed
//#include <climits> 
//#include <cctype> //isalpha, isnum, isalnum, ispunc, isupper, islower
//#include <cmath> //pow, abs, fabs, ceil, floor, sqrt
//#include <cstring> //strcat, strncat, strcpy, strncpy
//#include <ctime> 
//#include <stdlib.h> 
//#include <fstream> 
//#include <string> 
//#include <vector> 
//using namespace std;
//
// typedef for client
//typedef struct
//{
//	char username[50];
//	char password[50];
//	char ic[30];
//	char contactnum[30];
//	char status[10];
//}USER;
//
//typedef struct
//{
//	char username[50];
//	char password[50];
//	char doctor_id[30];
//}DOCTOR;
//
// login interface functions
//void login_interface(USER c[], int* id_ptr);
//int login(USER c[], int* i_ptr);
//void signup(USER c[]);
//bool check_number(string str);
//
// main menu functions
//void mainmenu(USER C[], int id);
//int resetpwd(USER c[], int* i_ptr);
//int userupdate(USER c[], int id);
//int updatePhonenum(USER c[], int id);
//int updateStatus(USER c[], int id);
//int faq(USER c[], int id);
//void exit();
//
//
// main function
//int main()
//{
//	 Clear screen
//	system("CLS");
//
//	 Create an array of CLIENT and DOCTOR structs
//	USER c[50];
//	DOCTOR d[50];
//
//	 Open input files
//	ifstream name_file("username.txt");
//	ifstream pass_file("userpassword.txt");
//	ifstream ic_file("useric.txt");
//	ifstream phonenum_file("userphone.txt");
//	ifstream stats_file("status.txt");
//
//	 Check if file opening was successful
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
//		 Read data from input files into the CLIENT array
//		for (int i = 0; i < 50; i++)
//		{
//			name_file >> c[i].username;
//			pass_file >> c[i].password;
//			ic_file >> c[i].ic;
//			phonenum_file >> c[i].contactnum;
//			stats_file >> c[i].status;
//		}
//		 Close input files
//		name_file.close();
//		pass_file.close();
//		ic_file.close();
//		phonenum_file.close();
//		stats_file.close();
//	}
//
//	 Call login interface function
//	int id;
//	login_interface(c, &id);
//
//	 Call main menu function
//	mainmenu(c, id);
//
//	return 0;
//}
//
// login function definitions
//void login_interface(USER c[], int* id_ptr)
//{
//	char interfaceAns;
//	do
//	{
//		cout << "Do you want to <L>ogin or <S>ign up or <R>eset password? >>> ";
//		cin >> interfaceAns;
//		interfaceAns = toupper(interfaceAns);
//	} while (interfaceAns != 'L' && interfaceAns != 'S' && interfaceAns != 'R');
//
//	int i;
//
//	if (interfaceAns == 'L') // If user chooses to login
//	{
//		login(c, &i); // Call the login function to perform login process
//		*id_ptr = i; // Store the user ID in the memory location pointed by id_ptr
//	}
//	else if (interfaceAns == 'S') // If user chooses to sign up
//	{
//		signup(c); // Call the signup function to perform sign up process
//	}
//	else if (interfaceAns == 'R') // If user chooses to reset password
//	{
//		resetpwd(c, &i); // Call the resetpwd function to perform password reset process
//		*id_ptr = i; // Store the user ID in the memory location pointed by id_ptr
//		main(); // Call the main function to restart the program after password reset
//	}
//
//	return;
//}
//
//function for user login
//int login(USER c[], int* i_ptr)
//{
//	char username[50], password[50];
//	bool userpassopt, usernameopt;
//
//	int i;
//	do
//	{
//		cin.ignore(1); // Ignore a single character in the input buffer to clear any remaining newline characters
//		cout << "Please enter your username --> ";
//		cin >> username; // Read user input for username
//
//		cout << "Please enter your password --> ";
//		cin >> password; // Read user input for password
//
//		fflush(stdin); // Flush the input buffer to clear any remaining characters
//
//		for (int i = 0; i < 50; i++) // Iterate through the array of CLIENT objects
//		{
//			if (strcmp(c[i].username, username) == 0) // Compare the entered username with the username in CLIENT object
//			{
//				usernameopt = true; // Set usernameopt flag to true indicating username match
//
//				if (strcmp(c[i].password, password) == 0) // Compare the entered password with the password in CLIENT object
//				{
//					userpassopt = true; // Set userpassopt flag to true indicating password match
//					*i_ptr = i; // Store the index of the matched CLIENT object in the memory location pointed by i_ptr
//					break; // Break out of the loop as the login is successful
//				}
//				else
//				{
//					userpassopt = false; // Set userpassopt flag to false indicating incorrect password
//				}
//			}
//			else
//			{
//				usernameopt = false; // Set usernameopt flag to false indicating no username match
//			}
//		}
//
//		if ((userpassopt == false || usernameopt == false))
//		{
//			cout << "\nIncorrect password or username\n" << endl; // Display error message for incorrect username or password
//		}
//		else
//		{
//			cout << "\nLogin successful\n" << endl; // Display success message for successful login
//		}
//
//	} while (usernameopt == false); // Continue looping until a valid username is entered
//
//	return 0;
//}
//
//function for user to signup
//void signup(USER c[])
//{
//	int phone_len, ic_len;
//	string name, password1, password2, age, contact_num, ic, stats;
//	bool validate, validrange, validateic, validrangeic, validate2, validrangephone;
//	validateic = true;
//	validate2 = true;
//	validate = true;
//	stats = "NULL";
//
//	 Get user's name
//	cout << "Please enter your name: ";
//	getline(cin >> ws, name);
//
//	 Get user's age
//	cout << "Please enter your age: ";
//	do
//	{
//		cin >> age;
//		 Validate if age is a number
//		bool validate = check_number(age);
//		if (validate == true)
//		{
//			 Check if age is within valid range (12 to 110)
//			if ((atoi(age.c_str()) <= 110) && (atoi(age.c_str()) >= 12))
//			{
//				validrange = true;
//			}
//			else
//			{
//				validrange = false;
//			}
//		}
//		else
//		{
//			cout << "Invalid input" << endl;
//		}
//
//		if (validate == false || validrange == false)
//			cout << "Please enter your age again: ";
//
//	} while (validate == false || validrange == false);
//
//	 Get user's IC number
//	cout << "Please enter your ic number without '-' (0123456789012): ";
//	do
//	{
//		cin >> ic;
//		 Validate if IC number is a number
//		bool validateic = check_number(ic);
//		if (validateic == true)
//		{
//			char icarray[30];
//			strcpy(icarray, ic.c_str());
//			ic_len = strlen(icarray);
//			 Check if IC number length is within valid range (11 to 13)
//			if ((ic_len < 13) && (ic_len > 11))
//			{
//				validrangeic = true;
//			}
//			else
//			{
//				validrangeic = false;
//			}
//		}
//		else
//		{
//			cout << "Invalid input" << endl;
//		}
//
//		if (validateic == false || validrangeic == false)
//			cout << "Please enter your ic again: ";
//
//	} while (validateic == false || validrangeic == false);
//
//	 Get user's contact number
//	cout << "Please enter your contact number without '-' (i.e:0183958711): ";
//	do
//	{
//		cin >> contact_num;
//		 Validate if contact number is a number
//		bool validate2 = check_number(contact_num);
//		char contactnumarray[30];
//		strcpy(contactnumarray, contact_num.c_str());
//		phone_len = strlen(contactnumarray);
//		 Check if contact number length is within valid range (10 to 13)
//		if ((phone_len <= 13) && (phone_len >= 10))
//		{
//			validrangephone = true;
//		}
//		else
//		{
//			validrangephone = false;
//		}
//		if (validate2 == false || validrangephone == false)
//		{
//			cout << "Invalid input" << endl;
//			cout << "Please enter your contact number again without '-' (i.e:0183958711): ";
//		}
//	} while (validate2 == false || validrangephone == false);
//
//	 Get user's password
//	do
//	{
//		cout << "Please enter your password: ";
//		cin >> password1;
//
//		cout << "Please enter your password again: ";
//		cin >> password2;
//		if (password1 != password2)
//		{
//			cout << "Different password entered \n"; // Prompt user that different passwords were entered
//			cout << "Please try again\n"; // Prompt user to try again
//			cout << "Please enter your password: "; // Prompt user to enter password again
//			cin >> password1;
//
//			cout << "Please enter your password again: "; // Prompt user to enter password again
//			cin >> password2;
//		}
//
//	} while (password1 != password2); // Repeat until password1 and password2 match
//
//
//	ofstream passwordfile("userpassword.txt", ios::app); // Create an output file stream to append to userpassword.txt file
//	passwordfile << password2 << endl; // Write password2 to userpassword.txt followed by newline
//
//
//	ofstream username("username.txt", ios::app); // Create an output file stream to append to username.txt file
//	username << name << endl; // Write name to username.txt followed by newline
//
//
//	ofstream agefile("userage.txt", ios::app); // Create an output file stream to append to userage.txt file
//	agefile << age << endl; // Write age to userage.txt followed by newline
//
//
//	ofstream phonenumfile("userphone.txt", ios::app); // Create an output file stream to append to userphone.txt file
//	phonenumfile << contact_num << endl; // Write contact_num to userphone.txt followed by newline
//
//
//	ofstream icfile("useric.txt", ios::app); // Create an output file stream to append to useric.txt file
//	icfile << ic << endl; // Write ic to useric.txt followed by newline
//
//
//	ofstream stats_file("status.txt", ios::app); // Create an output file stream to append to stats.txt file
//	stats_file << stats << endl; // Write vac to vac_stats.txt followed by newline
//
//
//	system("CLS"); // Clear screen
//	cout << "Sign up complete \n"; // Prompt user that sign up is complete
//	main(); // Call main() function to restart the program
//}
//
//function to reset user's password
//int resetpwd(USER c[], int* i_ptr)
//{
//	 Input for username and new password
//	string username, resetpassword;
//	cout << "Enter your username: ";
//	cin >> username;
//	cout << "Enter your new password: ";
//	cin >> resetpassword;
//
//	string usernameToFind = username; // Username to find
//	string newPassword = resetpassword; // New password to replace
//
//	 Open the username text file for reading
//	ifstream usernameFile("username.txt");
//	if (!usernameFile.is_open()) {
//		cout << "Failed to open username file." << endl;
//		return 1;
//	}
//
//	 Open the password text file for reading
//	ifstream passwordFile("userpassword.txt");
//	if (!passwordFile.is_open()) {
//		cout << "Failed to open password file." << endl;
//		usernameFile.close();
//		return 1;
//	}
//
//	vector<string> usernames; // Vector to store usernames from file
//	vector<string> passwords; // Vector to store passwords from file
//	string line;
//
//	 Read usernames and passwords from the files into memory
//	while (getline(usernameFile, line)) {
//		usernames.push_back(line);
//		getline(passwordFile, line);
//		passwords.push_back(line);
//	}
//
//	usernameFile.close(); // Close username file
//	passwordFile.close(); // Close password file
//
//	 Search for the username to find and update the corresponding password
//	bool found = false;
//	for (size_t i = 0; i < usernames.size(); ++i) {
//		if (usernames[i] == usernameToFind) {
//			found = true;
//			passwords[i] = newPassword; // Update password
//			*i_ptr = i; // Store index of updated password
//			break;
//		}
//	}
//
//	if (found) {
//		 Write the updated passwords back to the password file
//		ofstream updatedPasswordFile("userpassword.txt");
//		if (!updatedPasswordFile.is_open()) {
//			cout << "Failed to open updated password file." << endl;
//			return 1;
//		}
//
//		for (size_t i = 0; i < passwords.size(); ++i) {
//			updatedPasswordFile << passwords[i] << endl;
//		}
//
//		updatedPasswordFile.close(); // Close updated password file
//
//		cout << "Password updated successfully." << endl;
//
//	}
//	else {
//		cout << "Username not found." << endl;
//	}
//	return 0;
//}
//
//function to validate if the string is number
//bool check_number(string str) {
//	for (int i = 0; i < str.length(); i++) {
//		 Check if the character at position i is not a digit
//		if (isdigit(str[i]) == false) {
//			return false; // If a non-digit character is found, return false
//		}
//	}
//	return true; // If all characters are digits, return true
//}
//
//
// main menu function definitions
//void mainmenu(USER c[], int id)
//{
//	system("CLS"); // Clear the screen
//	time_t ttime = time(0); // Variable to store current time
//	char* dt = ctime(&ttime); // Get current time as string
//	cout << "Today's Date and Time -->\t" << dt << endl; // Print current date and time
//	char status = ' '; // Variable to store status
//	cout << "========================================================================================================================" << endl;
//	cout << left << setw(25) << "Name" << left << setw(20) << "Ic number" << left << setw(23) << "Contact Number" << left << setw(25) << "Status" << left << setw(18)<< endl; // Display column headers
//	cout << "========================================================================================================================" << endl;
//	cout << left << setw(25);
//	cout << c[id].username; // Display username from the USER array
//	cout << left << setw(20);
//	cout << c[id].ic; // Display IC number from the USER array
//	cout << left << setw(23);
//	cout << c[id].contactnum; // Display contact number from the USER array
//	cout << left << setw(25);
//	cout << c[id].status; // Display status from the USER array
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	char ans;
//
//	do {
//		cout << "Press <1> to do diagnose" << endl; // Display menu option
//		cout << "Press <2> to update your user profile" << endl; // Display menu option
//		cout << "Press <3> to review the FAQ" << endl; // Display menu option
//		cout << "Press <4> to Exit" << endl << endl; // Display menu option
//		cout << "--->";
//		cin >> ans; // Get user input
//		cout << endl;
//	} while (ans != '1' && ans != '2' && ans != '3' && ans != '4'); // Continue to display the menu if input is invalid
//
//	if (ans == '1')
//	{
//		system("CLS"); // Clear the screen
//		diagnose(c, id); // Call the covidcategory() function
//		cout << "Diagnose waiting to be done";
//	}
//
//	else if (ans == '2')
//	{
//		system("CLS"); // Clear the screen
//		userupdate(c, id); // Call the userupdate() function
//	}
//
//	else if (ans == '3')
//	{
//		system("CLS"); // Clear the screen
//		faq(c, id); // Call the faq() function
//	}
//
//	else if (ans == '4')
//	{
//		system("CLS"); // Clear the screen
//		exit(); // Call the exit() function
//	}
//
//	else
//	{
//		cout << "invalid input please try again"; // Display error message
//		mainmenu(c, id); // Call the mainmenu() function recursively to retry
//	}
//
//	return; // Return from the function
//}
//
//
//function for user to update their info
//int userupdate(USER c[], int id)
//{
//	char choice;
//	cout << "    Name: " << c[id].username << endl; // Displaying current name
//	cout << "    Ic number: " << c[id].ic << endl; // Displaying current IC number
//	cout << "<1> Contact number: " << c[id].contactnum << endl; // Displaying current contact number
//	cout << "<2> Status: " << c[id].status << endl; // Displaying current status
//	cout << "---------------------------------------------------" << endl; // Displaying separator line
//	cout << "Enter number to change: "; // Prompting user to enter their choice
//	cin >> choice; // Reading user's choice
//
//	switch (choice)
//	{
//	case '1':
//		updatePhonenum(c, id); // Calling function to update contact number
//		break;
//	case '2':
//		updateStatus(c, id); // Calling function to update category
//		break;
//	default:
//		userupdate(c, id); // If invalid choice, recursively calling the same function again
//		break;
//	}
//	return 0;
//}
//
//function for user to update their contact number
//int updatePhonenum(USER c[], int id)
//{
//	string resetphonenum;
//	cout << "Enter your new contact number: "; // Prompting user to enter new contact number
//	cin >> resetphonenum; // Reading new contact number from user
//
//	string usernameToFind = c[id].username; // Username to find
//	string newPhonenum = resetphonenum;
//
//	ifstream usernameFile("username.txt"); // Opening username file for reading
//	if (!usernameFile.is_open()) {
//		cout << "Failed to open username file." << endl; // Displaying error message if failed to open file
//		return 1;
//	}
//
//	ifstream phonenumFile("userphone.txt"); // Opening userphone file for reading
//	if (!phonenumFile.is_open()) {
//		cout << "Failed to open phone number file." << endl; // Displaying error message if failed to open file
//		usernameFile.close();
//		return 1;
//	}
//
//	vector<string> usernames; // Vector to store usernames
//	vector<string> phonenum; // Vector to store contact numbers
//	string line;
//
//	 Reading usernames and contact numbers from respective files
//	while (getline(usernameFile, line)) {
//		usernames.push_back(line);
//		getline(phonenumFile, line);
//		phonenum.push_back(line);
//	}
//
//	usernameFile.close();
//	phonenumFile.close();
//
//	bool found = false;
//	for (size_t i = 0; i < usernames.size(); ++i) {
//		if (usernames[i] == usernameToFind) { // Finding username in the vector
//			found = true;
//			phonenum[i] = newPhonenum; // Updating contact number in the vector
//			break;
//		}
//	}
//
//	if (found) {
//		ofstream updatedPhonenumFile("userphone.txt"); // Opening userphone file for writing
//		if (!updatedPhonenumFile.is_open()) {
//			cout << "Failed to open updated phonenum file." << endl; // Displaying error message if failed to open file
//			return 1;
//		}
//
//		 Writing updated contact numbers to the file
//		for (size_t i = 0; i < phonenum.size(); ++i) {
//			updatedPhonenumFile << phonenum[i] << endl;
//		}
//
//		updatedPhonenumFile.close();
//
//		cout << "Contact number updated successfully." << endl; // Displaying success message
//	}
//	else {
//		cout << "Username not found." << endl; // Displaying error message if username not found
//	}
//
//	return 0;
//}
//
//function for user to update their category
//int updateStatus(USER c[], int id)
//{
//	string resetcategory;
//	cout << "Enter your new category: ";
//	cin >> resetcategory; // Get the new category from user input
//
//	string usernameToFind = c[id].username; // Username to find
//	string newCategory = resetcategory; // Store the new category
//
//	 Open the username text file for reading
//	ifstream usernameFile("username.txt");
//	if (!usernameFile.is_open()) {
//		cout << "Failed to open username file." << endl;
//		return 1;
//	}
//
//	 Open the category text file for reading
//	ifstream categoryFile("category.txt");
//	if (!categoryFile.is_open()) {
//		cout << "Failed to open category file." << endl;
//		usernameFile.close();
//		return 1;
//	}
//
//	vector<string> usernames;
//	vector<string> category;
//	string line;
//
//	 Read usernames and category from the files into memory
//	while (getline(usernameFile, line)) {
//		usernames.push_back(line);
//		getline(categoryFile, line);
//		category.push_back(line);
//	}
//
//	usernameFile.close();
//	categoryFile.close();
//
//	bool found = false;
//	 Search for the username to find and update the corresponding category
//	for (size_t i = 0; i < usernames.size(); ++i) {
//		if (usernames[i] == usernameToFind) {
//			found = true;
//			category[i] = newCategory; // Update the category
//			break;
//		}
//	}
//
//	if (found) {
//		 Write the updated category back to the category file
//		ofstream updatedcategoryFile("category.txt");
//		if (!updatedcategoryFile.is_open()) {
//			cout << "Failed to open updated category file." << endl;
//			return 1;
//		}
//
//		for (size_t i = 0; i < category.size(); ++i) {
//			updatedcategoryFile << category[i] << endl;
//		}
//
//		updatedcategoryFile.close();
//
//		cout << "Category updated successfully." << endl;
//	}
//	else {
//		cout << "Username not found." << endl;
//	}
//
//	return 0;
//}
//
//function for FAQ
//int faq(USER c[], int id)
//{
//	system("CLS");
//	cout << "FAQ";
//	return 0;
//}
//
//void exit()
//{
//	cout << "EXIT";
//}