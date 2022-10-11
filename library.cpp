#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "library.h"
using namespace std;

 


void collect_one_set(istream& input, Covid& c ) { 
  getline(input, c.county, ',' );
  //cout << c.county << endl;
  getline(input, c.state, ',');
  //cout << c.state << endl;
  input >> c.population;
  //cout << c.population << endl;
  input.ignore();
  input >> c.deaths;
  //cout << c.deaths << endl;
  c.highest_case = -9999;
  c.lowest_case = 9999;
  for (int i = 0; i < 14; i++) {
    input >> c.cases[i];
    if (c.highest_case < c.cases[i]) {
      c.highest_case = c.cases[i];
    }
    if (c.lowest_case > c.cases[i]) {
      c.lowest_case = c.cases[i];
    }
    
    //cout << c.cases[i] << ", ";
  }
  input.ignore();
} 
bool collect_data(Covid arr[], int&n) {
  ifstream file_input("input.dat");
  if (!file_input.is_open()) {
    n++;
    cout << "Can't open file." << endl;
    return false;
  } 
  string credit_url;
  getline(file_input, credit_url);
  //cout << credit_url << endl;
  while (!file_input.eof()) {
    collect_one_set(file_input, arr[n]);
    n++;
    //cout << "pos n " << n <<  endl;
  }
    return true;
  }
  void display_all_cases (const Covid arr[], int n) {
    cout << setfill (' ');
    cout << left << setw(10) << "COUNTY" << setw(16) << "STATE";
    cout << right << setw(46) << "POPULATION";
    cout << setw(24) << "DEATHS" << endl;
    cout << setfill ('=');
    cout << '=' << setw(96) << '=' << endl;
    for (int x = 0; x < n; x++) {
      cout << setfill (' ');
      cout << left << setw(50) << arr[x].county + ", " + arr[x].state;
      cout << right << setw(20) <<  arr[x].population;
      cout << right << setw(25) << arr[x].deaths << endl;
      cout << "Cases: ";
      for (int i = 0; i < 14; i++) {
        cout << arr[x].cases[i] << " "; 
      }
      cout << endl;
      cout << setfill ('-');
      cout << '-' << setw(96) << '-' << endl;
      int i;
      //cout << "Position county: " << i << endl;
      i++;
      //cout << '\n' << '\n';
    }
  }
  void sort_by_highest_case (Covid arr[], int n ) {
    for (int j = 1; j < n; j++) {
      
      for (int i = j; i > 0 && arr[i - 1].highest_case < arr[i].highest_case; i--) {
        swap(arr[i - 1], arr[i]);
      }
      cout << endl;
    }
    cout << "HIGHEST CASES IN DESCENDING ORDER: \n\n";
    cout << setfill (' ');
    cout << left << setw(10) << "COUNTY" << setw(16) << "STATE";
    cout << right << setw(46) << "POPULATION";
    cout << setw(24) << "DEATHS" << endl;
    cout << setfill ('=');
    cout << '=' << setw(96) << '=' << endl;
    for (int x = 0; x < n; x++) {
      cout << setfill (' ');
      cout << left << setw(50) << arr[x].county + ", " + arr[x].state;
      cout << right << setw(20) <<  arr[x].population;
      cout << right << setw(25) << arr[x].deaths << endl;
      cout << "Cases: ";
      for (int i = 0; i < 14; i++) {
        cout << arr[x].cases[i] << " "; 
      }
      cout << endl;
      cout << setfill ('-');
       cout << "Highest case in this county: " << arr[x].highest_case << endl;
      cout << '-' << setw(96) << '-' << endl;
      int i;
      //cout << "Position county: " << i << endl;
      i++;
      //cout << '\n' << '\n';
    }
  }
  void sort_by_highest_population (Covid arr[], int n ) {
    for (int j = 1; j < n; j++) {
      for (int i = j; i > 0 && arr[i - 1].population < arr[i].population; i--) {
        swap(arr[i - 1], arr[i]);
      }
    }
   cout << "Sorted from Highest to Lowest poulation:" << endl;

  }
  int highest_case(const Covid arr[], int n) {
    int highest = 0;
      for (int i = 0; i < n; i++) {
         if (highest < arr[i].highest_case ) {
          highest = arr[i].highest_case;
    }
  }
  cout << "Highest case of entire data in the past 14 days is: " << highest << endl;
  return highest;
}
  int lowest_case (const Covid arr[], int n) {
    int lowest = 9999;
     for (int g = 0; g < n; g++) {
      for (int i = 0; i < 14; i++) {
        if (lowest > arr[i].lowest_case) {
          lowest = arr[i].lowest_case;
        }
      } 
     }
     cout << "Lowest case of entire data in the past 14 days is: " <<  lowest << endl;
     return lowest;
  }
  
  int lowest_single_case (Covid county) {
    int lowest = 9999;
      for (int i = 0; i < 14; i ++) {
        if (lowest > county.lowest_case) {
          lowest = county.lowest_case;
      }
     }
    return lowest;
   }
   int highest_single_case (Covid county) {
     int highest = 0;
     int total = 0;
      for (int i = 0; i < 14; i ++) {
        if (highest < county.highest_case ) {
          highest = county.highest_case;
      }
     }
     return highest;
   }
  double average_single_county (Covid county) {
    double sum = 0;
    int average = 0;
      for(int j = 0; j < 14; j++) {
        sum += county.cases[j];
      }
      average = sum / 14 ;
      return average;
    }
  int total_single_case (Covid county) {
    int total = 0;
      for (int i = 0; i < 14; i++) {
        total += county.cases[i];
      }
      return total;
    }
  double cases_to_fatality (Covid county) {
    return 100 * double(county.deaths) / (county.population);
  }
  void display_case_to_fatlity (const Covid arr[], int n) {
    cout << setfill (' ');
    cout << "CASE-FATALITY PERCENTAGE: \n\n";
    cout << left << setw(40) << "COUNTY";
    cout << setw(10) << "DEATHS" << setw(10) << "% of CASES-FATALITY" << endl;
      for (int i = 0; i < n; i++) {
        cout << fixed << showpoint<< setprecision(2);
        cout << setw(40) << arr[i].county;
        cout << setw(10) << arr[i].deaths;
        cout << setw(10) << cases_to_fatality(arr[i]) << endl;

      }

  } 
  
  void display_choosen_county(const Covid arr[], int n, string county) {
    string yes_no;
    cout << setfill (' ');
    cout << left << setw(10) << "COUNTY" << setw(16) << "STATE";
    cout << right << setw(46) << "POPULATION";
    cout << setw(24) << "DEATHS" << endl;
    cout << setfill ('=');
    cout << '=' << setw(96) << '=' << endl;
      for (int j = 0; j < n; j++) {
        if (arr[j].county == county) {
          cout << setfill (' '); // add the idividual analysis within here
          cout << left << setw(50) << arr[j].county + ", " + arr[j].state;
          cout << right << setw(20) <<  arr[j].population;
          cout << right << setw(25) << arr[j].deaths << endl;
          cout << "Cases:";
          for (int i = 0; i < 14; i ++) {
            cout << arr[j].cases[i] << " ";
          }
          cout << endl;
          cout << setfill ('-');
          cout << '-' << setw(96) << '-' << endl;
          cout << "Type Yes if you would you like to see an analysis of " << county << " county or type any key if you wish to exit this section: ";
          cin >> yes_no;
          cout << "\n";
          if (yes_no == "Yes" || yes_no == "yes") {
            cout << "The total cases of " << county << " in the past 14 days is: " << total_single_case(arr[j]) << endl;
            cout << "The average cases of " << county << " in the past 14 days is: " << average_single_county(arr[j]) << endl;
            cout << "The lowest case of " << county << " in the past 14 days is: " << lowest_single_case(arr[j]) << endl;
            cout << "The highest case of " << county << " in the past 14 days is: " << highest_single_case(arr[j]) << endl;
            //cout << "percentage:" << cases_to_fatality(arr[j]) << endl;
            cout << '-' << setw(96) << '-' << endl;
         } else {
           cout << "Thank you";
        }
        //cout << '\n' << '\n';     
      } 
    }
  }
  
 
  void remove_picked_member ( Covid arr[], int n, string remove) {
    //n = 10;
    int pos;
    for (int i = 0; i < n; i++) {
      if (arr[i].county == remove) {
        pos= i;
        
      }
    }
    cout << "To verify the right position is found: " << arr[pos].county << endl;
    for (int i = pos; i < n - 1; i++) {
      arr[i] = arr[i+1];
    }
    n--;  // subtract 1 from length of covid array 
    
  }
  
  

  void display_choosen_state(const Covid arr[], int n, string state) {
    string yes_no;
    cout << setfill (' ');
    cout << left << setw(10) << "COUNTY" << setw(16) << "STATE";
    cout << right << setw(46) << "POPULATION";
    cout << setw(24) << "DEATHS" << endl;
    cout << setfill ('=');
    cout << '=' << setw(96) << '=' << endl;
      for (int j = 0; j < n; j++) {
        if (arr[j].state == state) {
          cout << setfill (' '); // add the idividual analysis within here
          cout << left << setw(50) << arr[j].county + ", " + arr[j].state;
          cout << right << setw(20) <<  arr[j].population;
          cout << right << setw(25) << arr[j].deaths << endl;
          cout << "Cases:";
          for (int i = 0; i < 14; i ++) {
            cout << arr[j].cases[i] << " ";
          }
          cout << endl;
          cout << setfill ('-');
          cout << '-' << setw(96) << '-' << endl;
        
        } 
        
      }
    }
    
  


    



  
  





    
      





    















  



























  






  