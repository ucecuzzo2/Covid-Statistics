#include "library.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	const int capacity = 14;
	Covid covid_cases[capacity];
	int num_cases = 0;
	if (!collect_data(covid_cases, num_cases)) {
		cout << "Unable to collect data.\n";
		return 1;
	}

  
	cout << setfill('=');
	cout << '=' << setw(120) << '=' << endl;
	cout << setw(5) << "Welocme To Main Menu.\nThis Program analyzes and displays covid cases from counties in California and Arizona within the past 14 days. " << endl;
	cout << '=' << setw(120) << '=' << endl;
	int answer;
	string county;
	string yes_no;
	string remove;
  string state;

	do {
		cout << "If you would like to see all the data of covid cases enter 1 "
			 << endl;
		cout << "If you would like to see the highest cases in order enter 2 "
			 << endl;
		cout << "If you would like to see data based on highest to "
				"lowest population eneter 3 "
			 << endl;
		cout << "If you would like to see an individual county enter 4 " << endl;
		cout << "If you would like to remove an object enter 5 " << endl;
		cout << "If you would like to highest and lowest cases from the entire data "
				"set enter 6"
			 << endl;
    cout << "If you would like to see the Case-Fatality percentage from each county enter 7 ";
    cout << endl;
    cout << "If you would like to see a speicifc state enter 8 " << endl;
		cout << "If you would like to exit enter 0 " << endl;
		cin >> answer;
		cin.ignore();
		cout << endl;

		switch (answer) {
		case 1:
			display_all_cases(covid_cases, num_cases);
			cout << endl;
			break;
		case 2:
			sort_by_highest_case(covid_cases, num_cases);
			cout << endl;
			//display_all_cases(covid_cases, num_cases);
			cout << endl;
			break;
		case 3:
			sort_by_highest_population(covid_cases, num_cases);
			cout << endl;
			display_all_cases(covid_cases, num_cases);
			cout << endl;
			break;
		case 4:
			cout << "Which county are you intrested in for analysis : ";
			getline(cin, county);
			cout << "County selected is: " << county << endl;
			display_choosen_county(covid_cases, num_cases, county);
			break;
		case 5:
			cout << "What county would you like to remove? ";
			getline(cin, remove);
			cout << "The county you selected to remove is: " << remove << endl;
			remove_picked_member(covid_cases, num_cases, remove);
			cout << endl;
			display_all_cases(covid_cases, num_cases-1);
			break;
		case 6:
			highest_case(covid_cases, num_cases);
			lowest_case(covid_cases, num_cases);
			cout << endl;
			break;
    case 7: 
      display_case_to_fatlity(covid_cases, num_cases);
      cout << endl;
      break;
    case 8:
      cout << "Which state are you intrested in: ";
      getline (cin, state);
      cout << "State seleted is " << state << endl;
      display_choosen_state(covid_cases,num_cases,state);
      break;
    }

	} while (answer != 0);
	cout << "Thank you for using this porgram see you soon! " << endl;

}
  


