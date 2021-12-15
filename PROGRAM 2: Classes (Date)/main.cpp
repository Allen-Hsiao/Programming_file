#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <locale>
using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

// creates the date January 1st, 2000.
Date::Date(){
   monthName = "January";
   month = 1;
   day = 1;
   year = 2000;
}
/* parameterized constructor: month number, day, year 
      - e.g. (3, 1, 2010) will construct the date March 1st, 2010

      If any of the arguments are invalid (e.g. 15 for month or 32 for day)
      then the constructor will construct instead a valid Date as close
      as possible to the arguments provided - e.g. in above example,
      Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
      In case of such invalid input, the constructor will issue a console error message: 

      Invalid date values: Date corrected to 12/31/2010.
      (with a newline at the end).
*/
Date::Date(unsigned m, unsigned d, unsigned y){
   year = y;
   if (m > 12){
      month = 12;
   }
   else if (m < 1){
      month = 1;
   }
   else{
      month = m;
   }
   if (m <= 12 && m >=1 && d >=1 && d <= 31){
      if (d > daysPerMonth(m,y)){
         day = daysPerMonth(m,y);
      }
      else if (d < 1){
         day = 1;
      }
      else{
         day = d;
      }
      if(d > daysPerMonth(m, y)|| d < 1){
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
   }
   else{
      if (d > daysPerMonth(month, y)){
         day = daysPerMonth(month,y);
      }
      else if (d < 1){
         day = 1;
      }
      else{
         day = d;
      }
   }
   monthName = name(month);

   if ( (m < 1) || (m > 12) || (d > 31) || (d < 1) ){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
}

/* parameterized constructor: month name, day, year
   - e.g. (December, 15, 2012) will construct the date December 15th, 2012

      If the constructor is unable to recognize the string argument as a valid month name,
      then it will issue a console error message: 

      Invalid month name: the Date was set to 1/1/2000.
      (with a newline at the end).

      If the day argument is invalid for the given month (but the month name was valid),
      then the constructor will handle this error in the same manner as the other
      parameterized constructor. 

      This constructor will recognize both "december" and "December"
      as month name.
*/
Date::Date(const string &mn, unsigned d, unsigned y){
   vector<string>Date_list(12);
   string inputmonth;
   Date_list.at(0) = "January";
   Date_list.at(1) = "February";
   Date_list.at(2) = "March";
   Date_list.at(3) = "April";
   Date_list.at(4) = "May";
   Date_list.at(5) = "June";
   Date_list.at(6) = "July";
   Date_list.at(7) = "August";
   Date_list.at(8) = "September";
   Date_list.at(9) = "October";
   Date_list.at(10) = "November";
   Date_list.at(11) = "December";
   for (unsigned i =0; i < mn.size(); ++i){
      if (i == 0){
         inputmonth.push_back(toupper(mn[i]));
      }
      else{
         inputmonth.push_back(mn[i]);
      }
   }
   int count = 0;
   for (unsigned x = 0; x < Date_list.size(); ++x){
      if (inputmonth == Date_list.at(x)){
         monthName = Date_list.at(x);
         count += 1;
      }
   }
   if (count == 0){
      day = 1;
      month = 1;
      year = 2000;
      monthName = "January";
      cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
   }
   else{
      if (d > daysPerMonth(number(inputmonth),y)){
         day = daysPerMonth(number(inputmonth),y);
      }
      else if (d < 1){
         day = 1;
      }
      else{
         day = d;
      }
      year = y;
      month = number(inputmonth);
      monthName = inputmonth;
   }
   if ( (count != 0) && ((month > 12) || (d > 31) || (d < 1)||(d > daysPerMonth(number(inputmonth),y)))){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }   
}

/* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
   Does not output a newline at the end.
*/
void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year;
}

/* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
   The first letter of the month name is upper case, and the month name is
   printed in full - January, not Jan, jan, or january. 
   Does not output a newline at the end.
*/
void Date::printAlpha() const{
   cout << monthName << " " << day << ", " << year;
}

/* Returns true if the year passed in is a leap year, otherwise returns false.
*/
bool Date::isLeap(unsigned y) const{
   bool result = false;
   if (y % 4 == 0) {
      if (y % 100 == 0) {
         if (y % 400 == 0){
            result = true;
         }
         else{
            result = false;
         }
      }
      else{
         result = true;
      }
   }
   else{
      result = false;
   }
   return result;
}

/* Returns number of days allowed in a given month
   -  e.g. daysPerMonth(9, 2000) returns 30.
   Calculates February's days for leap and non-leap years,
   thus, the reason year is also a parameter.
*/
unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
   if (isLeap(y) == true){
      if (m == 2){
         return 29;
      }
      else if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)){
         return 31;
      }
      else{
         return 30;
      }
   }
   else{
      if (m == 2){
         return 28;
      }
      else if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)){
         return 31;
      }
      else{
         return 30;
      }
   }
}

/* Returns the name of a given month
   - e.g. name(12) returns the string "December"
*/
string Date::name(unsigned m) const{
   vector<string>Date_list(12);
   string result;

   Date_list.at(0) = "January";
   Date_list.at(1) = "February";
   Date_list.at(2) = "March";
   Date_list.at(3) = "April";
   Date_list.at(4) = "May";
   Date_list.at(5) = "June";
   Date_list.at(6) = "July";
   Date_list.at(7) = "August";
   Date_list.at(8) = "September";
   Date_list.at(9) = "October";
   Date_list.at(10) = "November";
   Date_list.at(11) = "December";
   
   result = Date_list.at(m-1);
   return result;
}

/* Returns the number of a given named month
   - e.g. number("March") returns 3
*/
unsigned Date::number(const string &mn) const{
   vector<string>Date_list(12);
   int result;

   Date_list.at(0) = "January";
   Date_list.at(1) = "February";
   Date_list.at(2) = "March";
   Date_list.at(3) = "April";
   Date_list.at(4) = "May";
   Date_list.at(5) = "June";
   Date_list.at(6) = "July";
   Date_list.at(7) = "August";
   Date_list.at(8) = "September";
   Date_list.at(9) = "October";
   Date_list.at(10) = "November";
   Date_list.at(11) = "December";
   
   for (unsigned i = 0; i < Date_list.size(); ++i){
      if (mn == Date_list.at(i)){
         result = i + 1;
      }
   }
   return result;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}