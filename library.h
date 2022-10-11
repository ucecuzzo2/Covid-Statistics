#include <string>
using namespace std;


struct Covid {
  string county, state; 
  int highest_case, lowest_case, population, deaths;
  int cases[14]; // covid cases in the past 14 days // for each day 
};

//collect fucntion 
void collect_one_set(istream& input, Covid& c );
bool collect_data (Covid arr[], int&n);

//display functions
void display_all_cases (const Covid arr[], int n);
void display_all_highest (const Covid arr[], int n);
void display_case_to_fatlity (const Covid arr[], int n);


//filter functions 
void display_choosen_county(const Covid arr[], int n, string county);
void display_choosen_state(const Covid arr[], int n, string state);

//sort functions 
void sort_by_highest_case (Covid arr[], int n );
void sort_by_highest_population (Covid arr[], int n );

// one analysis function
int highest_case(const Covid arr[], int n);
int lowest_case (const Covid arr[], int c);

//single analysis
double average_single_county (Covid county);
int lowest_single_case (Covid county);
int highest_single_case (Covid county);
int total_single_case (Covid county);
double cases_to_fatality (Covid county);

//remove function 
void remove_picked_member (Covid arr[], int n, string remove);

