//Unit 5 Assignment Tuition
//Bowlby, Dr_T COSC 1437-58001
//A Collabortated effort w/ Rafael Martinez



#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h> //for sleep command
using namespace std;


class StudentType //Base Class *****
{
  protected:
    static const int hoursPerCLass = 3;
    static const int monthsInOneSemester = 4;
    static const int semestersInAYear = 3;
    int hoursTheStudentTakes;
    int hoursInTheDegree;
    string schoolName;
    int fullTime = 12;
    int partTime = 9;
    int halfTime = 6;
 
    double costPerHour;
    double costPerClass;
    double costOfBoard;
    double costOfFood;
    double costOfBooks;
    double costOfTravel;

  public:
    StudentType()//Default Constructor ************
    {
      hoursTheStudentTakes = 0; //based on studen type
      hoursInTheDegree = 60;
      schoolName = "TCC";
      costPerClass = 59.00;
      costOfBooks = 100.00;
      costOfBoard = 400.00;
      costOfFood = 150.00;
      costOfTravel = 90.00;
    }
  //Paramaterized Constructor **********************
  StudentType(int hTST, int hID, string sN, double cPC, double bCPC, double rABC, double fCPM, double tCPM):
  hoursTheStudentTakes(hTST), hoursInTheDegree(hID), schoolName(sN), costPerClass(cPC), costOfBooks(bCPC), costOfBoard(rABC), costOfFood(fCPM), costOfTravel(tCPM) {}
  
  //sets & gets STUDENT TYPE *******
  void setFullTime(int fT) { fullTime = fT; }//FullTime
  int getFullTime() const { return fullTime; }
  
  void setPartTime(int pT) { partTime = pT; }//PartTime
  int getPartTime() const { return partTime; }
  
  void setHalfTime(int hT) { halfTime = hT; }//HalfTime
  int getHalfTime() const { return halfTime; }
  
  void setCostOfBooks(double bC) { costOfBooks = bC; }//Cost Books
  double getCostOfBooks() const { return costOfBooks; }
  
  void setCostPerHour(double cH) { costPerHour = cH; }//Cost Per Hour
  double getCostPerHour() const { return costPerHour; }
  
  void setCostPerClass(double cC) { costPerClass = cC; }//Cost Per Class
  double getCostPerClass() const { return costPerClass; }
  
  void setCostOfBoard(double cB) { costOfBoard = cB; }//Cost of Board
  double getCostOfBoard() const { return costOfBoard; }
  
  void setCostOfFood(double cF) { costOfFood = cF; }//Cost of Food
  double getCostOfFood() const { return costOfFood; }
  
  void setCostOfTravel(double cT) { costOfTravel = cT; }//Cost of Travel
  double getCostOfTravel() const { return costOfTravel; }
  
  void setHoursAStudentTakes(int h) {hoursTheStudentTakes = h; }
  int getHoursAStudentTakes() const {return hoursTheStudentTakes; }
  
  void setSchoolName(string sN) {schoolName = sN; }
  string getSchoolName() const { return schoolName; }
  
  //*****************************************************************************
 
//Calculations **********

 double calculateTuition()//Tuition **
 { 
   return (hoursTheStudentTakes * costPerClass);
 }
 
 double calculateRoomAndBoard()//Room and Board **
 {
   return monthsInOneSemester * costOfBoard;
 }
 
 double calculateTravel()//Travel Costs **
 {
   return costOfTravel * monthsInOneSemester;
 }
 
 double calculateFood()//Food Cost **
 {
  return costOfFood * monthsInOneSemester;
 }
 
 double calculateBookCost()//Book Cost **
 {
  return costOfBooks * (hoursTheStudentTakes/hoursPerCLass);
 }
 double totalCostPerSemester()//Total for Semester (4mths) ****
 {
   return calculateTuition() + calculateRoomAndBoard() + calculateBookCost() + calculateFood() + calculateTravel();
 }
};//************************END BASE CLASS************************


class Cost : public StudentType //Derived Class *****************
{
 private: 
  
 public:
 
  void displayCollegeInfo()
  {
   int newHours = 0,newDegree = 0, selection = 8;
   string newSchoolName;
   double newBooks = 0.0;
   double newCostPCH = 0.0;
   double newRoomAndBoard = 0.0;
   double newFood = 0.0;
   double newTravel = 0.0;

  int hoursAFullTimeStudent = 12;
  int hoursAPartTimeStudent = 9;
  int hoursAHalfTimeStudent = 6;
  
  cout << fixed << setprecision(2) << endl;
  
  StudentType ftCollege; //calls defaut constructor
  StudentType ptCollege; //calls defaut constructor
  StudentType htCollege; //calls defaut constructor
  
  ftCollege.setHoursAStudentTakes(hoursAFullTimeStudent);
  ptCollege.setHoursAStudentTakes(hoursAPartTimeStudent);
  htCollege.setHoursAStudentTakes(hoursAHalfTimeStudent);
/*  StudentType ftCollege(hoursAFullTimeStudent, getHoursAStudentTakes(), getSchoolName(), 1565.00, 100.00, 1000.00, 150.00, 90.00);
  StudentType ptCollege(hoursAPartTimeStudent, getHoursAStudentTakes(), getSchoolName(), 1565.00, 100.00, 1000.00, 150.00, 90.00);
  StudentType htCollege(hoursAHalfTimeStudent, getHoursAStudentTakes(), getSchoolName(), 1565.00, 100.00, 1000.00, 150.00, 90.00);
*/
  // pass semester objects by reference to display sumary results via function*/

  //calculate and display tuition for each object in the program

  do 
  { 
    cout << "\n**************************" << endl;
    cout << "\nAverage Cost per Semester for " << ftCollege.getSchoolName() << ":" << endl;
    
    //FULL TIME STUDENT DISPLAY
    cout << "\nFULL TIME: " << endl;
    cout << "Average Cost per Semester for " << endl;
    cout << "Tuition = $" << ftCollege.calculateTuition() << endl;
    cout << "Room and Board = $" << ftCollege.calculateRoomAndBoard() << endl;
    cout << "Travel = $" << ftCollege.calculateTravel() << endl;
    cout << "Food = $" << ftCollege.calculateFood() << endl;
    cout << "Books = $" << ftCollege.calculateBookCost() << endl;
    cout << "Total for the semester = $" << ftCollege.totalCostPerSemester() << endl;
    cout << " " << endl;

    //PART TIME STUDENT DISPLAY
    cout << "\nPART TIME: " << endl;
    cout << "Tuition = $" << ptCollege.calculateTuition() << endl;
    cout << "Room and Board = $" << ptCollege.calculateRoomAndBoard() << endl;
    cout << "Travel = $" << ptCollege.calculateTravel() << endl;
    cout << "Food = $" << ptCollege.calculateFood() << endl;
    cout << "Books = $" << ptCollege.calculateBookCost() << endl;
    cout << "Total for the semester = $" << ptCollege.totalCostPerSemester() << endl;
    
    //HALF TIME STUDENT DISPLAY
    cout << "\nHALF TIME: " << endl;
    cout << "Tuition = $" << htCollege.calculateTuition() << endl;
    cout << "Room and Board = $" << htCollege.calculateRoomAndBoard() << endl;
    cout << "Travel = $" << htCollege.calculateTravel() << endl;
    cout << "Food = $" << htCollege.calculateFood() << endl;
    cout << "Books = $" << htCollege.calculateBookCost() << endl;
    cout << "Total for the semester = $" << htCollege.totalCostPerSemester() << endl;

  
  //****** MENU INFO *************
    cout << "\nAdjustments Menu: " << endl;
    cout << "Please Select An Option: " << endl;
    cout << "1.) Hours Taking "<< " - Current value (" << getHoursAStudentTakes()<< ")" << endl;
    cout << "2.) Name of School " << " - Current value (" << getSchoolName()<< ")" <<endl;
    cout << "3.) What is the Cost Per Credit Hour " << " - Current Value ( " << getCostPerHour() << endl;
    cout << "4.) What is the Cost of Books Per Class (average) " << endl;
    cout << "5.) What is the Cost of Room and Board " << endl;
    cout << "6.) What is the Cost of Food (per month) " << endl;
    cout << "7.) What is your Average Cost in Travel per month " << endl;
    cout << "8.) Exit " << endl;
    cin >> selection;
    
    if(selection == 1)
    {  
      cout << "Please tell me how many hours in your degree" << endl;
      cin >> newHours;
      setHoursAStudentTakes(newHours);
      cout << "\nNew Hours taken value: " << getHoursAStudentTakes() << endl; 
      sleep(3); //3 seconds 
    }
    else if (selection == 2)
    { 
      cout << "What is the name of your school " << endl;
      cin >> newSchoolName;
      setSchoolName(newSchoolName);
      cout << "\nNew Name of School: " << getSchoolName() << endl; 
      sleep(3); //3 seconds 
    }
    else if (selection == 3)
    {  
      cout << "What is the cost per credit hour? " << endl;
      cin >> newCostPCH;
      setCostPerHour(newCostPCH);
    }
    else if (selection == 4)
    { 
      cout << "What is the cost of books per class? " << endl;
      cin >> newBooks;
      setCostOfBooks(newBooks);
    }
    else if (selection == 5)
    { 
      cout << "What is the cost of Room and Board? " << endl;
      cin >> newRoomAndBoard;
      setCostOfBoard(newRoomAndBoard);
    }
    else if (selection == 6)
    {  
      cout << "What is the cost of food? " << endl;
      cin >> newFood;
      setCostOfFood(newFood);
    }
    else if (selection == 7)
    { 
      cout << "What is the cost of your travel? " << endl;
      cin >> newTravel;
      setCostOfTravel(newTravel);
    }
    
    cout << "\033[2J\033[1;1H";
  
   }while (selection != 8);
  
   cout << "Have a Great Day !!! " << endl;
  }
  
};
int main()//*************************************
{
  Cost c;
  int selection = 0;
    
    c.displayCollegeInfo();
  
  return 0;
}