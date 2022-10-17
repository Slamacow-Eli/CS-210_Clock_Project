/*
 * Clock Project
 *
 *  Date: [September 20, 2022]
 *  Author: [Elijah Herbert]
 *  Professor: [Michael Rissover]
 *  Class: [CS-210]
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
//Structure that will be used as global variables
struct {
	int myNum;
}hour24, hour, minute, second, i;
//function to take an int an format it into a two digit string with padding of 0's to the left if applicable
string twoDigitString(unsigned int n)
{
	ostringstream as; // stringstream allows me to turn int into string

	as << setw(2) << setfill('0') << n; // manipulate string to print two digits via setw()
	//cout << as.str();
	return as.str();
}
//function that lets me print a char a specified amount of times to remove redundancy of multiple cout statements
string stringFormatting(unsigned int num, char j)
{
	ostringstream bs;
	int i;

	for (i = 0; i < num; i++) // for loop to specificy the amount of characters i want
	{
		bs << j; 
	}

	cout << bs.str(); // prints desired character
	return bs.str();
}
//function to format the hour, minute, and seconds into a 24 hour clock
string formattedClock24(unsigned int h, unsigned int m, unsigned int s)
{
	ostringstream cs; // allows me to stream int into strings

	cs << twoDigitString(h) << ':' << twoDigitString(m) << ':' << twoDigitString(s);
	cout << cs.str(); // prints 24 hour clock
	return cs.str();

}
// function to display a 12 hour clock using an hour, minute, and second parameter
string formattedClock12(unsigned int h, unsigned int m, unsigned s)
{
	ostringstream ds1;
	ostringstream ds2; // stringstream variables for the int 

	if (h > 0 && h < 12)// conditional to check if am should be printed
	{
		ds1 << twoDigitString(h) << ':' << twoDigitString(m) << ':' << twoDigitString(s) << " AM";
		cout << ds1.str();
		return ds1.str();
	}
	else if (h > 11) //conditional to check if pm should be printed
	{
		if (h > 12) //conditional to keep the int under 24
		{
			h = h - 12;
		}
		ds1 << twoDigitString(h) << ':' << twoDigitString(m) << ':' << twoDigitString(s) << " PM";
		cout << ds1.str();
		return ds1.str();
	}
}
//function to display the menu options
void menuDisplay()
{
	stringFormatting(26, '*'); // top line
	cout << endl;

	cout << "* 1 - Add One Hour"; // option 1
	stringFormatting(7, ' ');
	cout << "*";
	cout << endl << endl;
	
	cout << "* 2 - Add One Minute"; // option 2
	stringFormatting(5, ' ');
	cout << "*";
	cout << endl << endl;
	
	cout << "* 3 - Add One Second"; // option 3
	stringFormatting(5, ' ');
	cout << "*";
	cout << endl << endl;
	
	cout << "* 4 - Exit Program"; // option 4
	stringFormatting(7, ' ');
	cout << "*";
	cout << endl;

	stringFormatting(26, '*');//bottom line
}
//function to process the choice chosen from menuDisplay
int menuInput()
{
	int m;
	cin >> m; // collect users choice
	//conditional actions based on choice
	if (m == 1)// conditional to add an hour
	{
		int addHour();
		int addHour24(); // call add hour functions
		hour24.myNum = addHour24();
		hour.myNum = addHour(); // store new value after function call for hours
		i.myNum = 1; // update conditional variable for the while loop in main()
	}
	else if (m == 2) // conditional to add a minute
	{
		int addMinute(); // call add minute function
		minute.myNum = addMinute(); //store new value after function call for minutes
		i.myNum = 2;// update conditional variable for the while loop in main()
	}
	else if (m == 3)//conditional to add a second
	{
		int addSecond();// call add second function
		second.myNum = addSecond(); // store new value after function call for seconds
		i.myNum = 3;// update conditional variable for the while loop in main()
	}
	else if (m == 4)
	{
		i.myNum = 4;// update conditional variable for the while loop in main()
	}
	else {
		cout << "invalid choice, please try again" << endl;
	}
	return i.myNum; // return updated while loop variable in main()
}
// function to display both the 12 and 24 hour clock
void duoClockDisplay()
{
	
	stringFormatting(26, '*');// top line for 12 hour clock
	stringFormatting(5, ' ');//spacing to separate the 12 hour clock and 24 hour clock boxes

	stringFormatting(26, '*');//top line for 24 hour clock
	cout << endl;
	// formatting for 12 hour clock
	cout << "*";
	stringFormatting(6, ' ');
	cout << "12-Hour Clock";
	stringFormatting(5, ' ');
	cout << "*";
	//formatting for 24 hour clock
	stringFormatting(5, ' ');
	cout << "*";
	stringFormatting(6, ' ');
	cout << "24-Hour Clock";
	stringFormatting(5, ' ');
	cout << "*";
	cout << endl;
	//formatting for 12 hour clock
	cout << "*";
	stringFormatting(7, ' ');
	formattedClock12(hour.myNum, minute.myNum, second.myNum);
	stringFormatting(6, ' ');
	cout << "*";
	//formatting for 24 hour clock
	stringFormatting(5, ' ');
	cout << "*";
	stringFormatting(8, ' ');
	formattedClock24(hour24.myNum, minute.myNum, second.myNum);
	stringFormatting(8, ' ');
	cout << "*";
	cout << endl;
	//bottom line for both boxes
	stringFormatting(26, '*');
	stringFormatting(5, ' '); // space the clocks apart
	stringFormatting(26, '*');
	cout << endl;



}
//function to add hour to the 24 hour clock
int addHour24()
{
	if (hour24.myNum == 23)// conditional to make sure hours doesnt run to 100 etc...
	{
		hour24.myNum = 0;//resets to 0 after 23
	}
	else {//if not at 23 yet then continue to this 
		hour24.myNum += 1; // add an hour to the 24 hour clock and store the value
	}

	return hour24.myNum; // return the new value
}
//function to add hour to the 12 hour clock
int addHour()
{
	if (hour.myNum > 23)//conditional to reset the hours so it doesnt run on
	{
		hour.myNum = 1;//resets the hours to 1 after 12 am(24)
		
	}
	else {// if not 24 then just add an hour and store the new value
		hour.myNum += 1;
	}

	return hour.myNum; // return the new value
}
//function to add a minute to both clocks
int addMinute()
{
	if (minute.myNum == 59)// conditional if minutes were to equal 60
	{
		minute.myNum = 0;//reset minutes to 0
		addHour();
		addHour24();//add an hour ot both 12 and 24 hour clocks
	}
	else {// if not at 59 then just add a minute
		minute.myNum += 1;//add a minute then store the new value...60 min = 1 hr
	}
	return minute.myNum;//return the new value
}
//function to add a second
int addSecond()
{
	if (second.myNum == 59)//conditional for if seconds were equal to 60
	{
		second.myNum = 0;//reset seconds to 0
		addMinute();//add a minute...60 sec = 1 min
	}
	else {//if not at 59 seconds then add a second
		second.myNum += 1;//add a second then store the new value
	}
	return second.myNum; // return the new value
}
void clrscr()
{
	system("cls");
}
//main function that will call functions to execute this program
int main()
{
	//objects created from the struct at the top of this program
	i.myNum = 0;// this variable/object is for the while loop variable
	hour.myNum = 15; // variable/object that serves as the hours for the 12 hour clock, preset to 14
	hour24.myNum = 15; // variable/object that serves as the hours for the 24 hour clock, preset to 14
	minute.myNum = 22; // variable/object that serves as the minutes for both the 12 and 24 hour clock, preset to 55
	second.myNum = 1;// variable/object that serves as the seconds for both the 12 and 24 hour clock, preset to 2

	//while loop to keep running program until i.myNum/userchoice is 4
	while (i.myNum != 4)
	{
		duoClockDisplay();//display current preset time
		menuDisplay();//display menu options
		i.myNum = menuInput();//collect users input choice of 1,2,3, or 4
		clrscr();
	
	}
	cout << "Thank you for using the clock display, Goodbye! :)"; // message to let the user know that the program has ended
	return 0;
}

