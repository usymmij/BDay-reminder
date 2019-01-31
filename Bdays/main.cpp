#include <iostream>
#include <time.h>
#include <windows.h>
#include <string>
#include <fstream>
bool BdayPositive;
//¯\_("/)_/¯
int checkNotSlash(char x){//check if x is a letter
	if (x=='a'||x=='b'||x=='c'||x=='d'||x=='e'||x=='f'||x=='g'||x=='h'||x=='i'||x=='E'||x=='O'||x=='T'||x=='U'){
		return 0;
	}
	else if (x=='l'||x=='m'||x=='n'||x=='o'||x=='p'||x=='q'||x=='r'||x=='s'||x=='A'||x=='P'||x=='Q'||x=='W'||x=='X'){
		return 0;
	}
	else if(x=='t'||x=='u'||x=='v'||x=='w'||x=='x'||x=='y'||x=='z'||x=='B'||x=='C'||x=='D'||x=='R'||x=='S'||x=='Y'){
		return 0;
	}
	else if(x=='j'||x=='k'||x=='F'||x=='G'||x=='H'||x=='I'||x=='J'||x=='K'||x=='L'||x=='M'||x=='N'||x=='V'||x=='Z'){
		return 0;
	}
	else{
		return 1;
	}
}
//¯\_("/)_/¯
int leapYearStuff(int day, int mode){
	int nowLeap = 1;
	day = day - 1096;
	for(; ;){
		for(int i = 0; i <= 1; i++){
			if (day > 365){
				day = day - 365;
				nowLeap = 0;
			}
			else {
				if (mode == 0){
					return nowLeap;
				}
				else if (mode == 1){
					return day;
				}
			}
		}
		if (day > 365){
			day = day - 365;
			nowLeap = 1;
		}
		else {
			if (mode == 0){
				return nowLeap;
			}
			else if (mode == 1){
				return day;
			}
		}
		if (day > 366){
			day = day - 366;
			nowLeap = 0;
		}
		else {
			if (mode == 0){
				return nowLeap;
			}
			else if (mode == 1){
				return day;
			}
		}
	}
}
//¯\_("/)_/¯
long int todayis(long int currentTime,bool DayOrMonth){
	int month = 1;
	int currentTimeZone;//variables
	std::ifstream infile;
	infile.open("timeZone.txt");
	infile >> currentTimeZone;
	infile.close();//input the timezone from a text file to variable
	currentTimeZone = currentTimeZone * 3600;
	currentTime = currentTimeZone + currentTime;
	currentTime = (currentTime/86400);
	bool nowLeap = leapYearStuff(currentTime,0);
	currentTime = leapYearStuff(currentTime,1) + 1;//find timezone, leapyear, do math
	if (currentTime > 31){
		month = month + 1;
		currentTime = currentTime - 31;
	}
	if (currentTime > (28 + nowLeap)){
		month = month + 1;
		currentTime = currentTime - 28 - nowLeap;
	}
	for(int i = 0; i <= 1; i++){
		if (currentTime > 31){
			month = month + 1;
			currentTime = currentTime - 31;
		}
		if (currentTime > 30){
			month = month + 1;
			currentTime = currentTime - 30;
		}
	}
	for (int i = 0; i<= 1; i++){
		if (currentTime > 31){
			month = month + 1;
			currentTime = currentTime - 31;
		}//more math to find month and day
	}
	for(int i = 0; i <= 1; i++){
		if (currentTime>31){
			month = month + 1;
			currentTime = currentTime - 31;
		}
		if (currentTime>30){
			month = month + 1;
			currentTime = currentTime - 30;
		}
	}
	if(DayOrMonth == 0)
	{
		return currentTime;//return the day
	}
	else if (DayOrMonth == 1){
		return month;//return the month
	}
}
//¯\_("/)_/¯
bool checkForAnomalys(long int cDay, long int cMonth){
	char name[49];
	int diffCounter;//gah im too tired for comments
	long int prevCounter = 0;//do this tmmrw
	long int loopCounter = 1;
	long int charCounter = 0;
	char infileChar;
	long int day;
	long int month;
	int nameLength = 0 - 1;//variables
	name[0] = '0';//edit variables
	std::ifstream infile;
	infile.open("BDays.txt");
	if (!infile){
		std::ofstream outfile("BDays.txt");
		outfile << "01/01 example"<<std::endl<<"00000 DO NOT REMOVE THIS LINE";
		std::cout<<"There was an error, please place Birthdays in (BDays.txt) in the format"<<std::endl;
		std::cout<<"DD/MM NameOfPerson";
		outfile.close();
		return 1;
	}
	for(; ;){
		infile >> infileChar;
		diffCounter = loopCounter - prevCounter;
		if(nameLength >= 0 && day == cDay && month == cMonth && infileChar >= 48 && infileChar <= 57){
			std::cout<<"                               (             )"<<std::endl;
			std::cout<<"                       )      (*)           (*)      ("<<std::endl;
			std::cout<<"                      (*)      |             |      (*)"<<std::endl;
			std::cout<<"                       |      |~|           |~|      |"<<std::endl;
			std::cout<<"                      |~|     | |           | |     |~|"<<std::endl;
			std::cout<<"                      | |     | |           | |     | |"<<std::endl;
			std::cout<<"                     ,| |a@@@@| |@@@@@@@@@@@| |@@@@a| |."<<std::endl;
			std::cout<<"                .,a@@@| |@@@@@| |@@@@@@@@@@@| |@@@@@| |@@@@a,."<<std::endl;
			std::cout<<"              ,a@@@@@@| |@@@@@@@@@@@@.@@@@@@@@@@@@@@| |@@@@@@@a,"<<std::endl;
			std::cout<<"             a@@@@@@@@@@@@@@@@@@@@@' . `@@@@@@@@@@@@@@@@@@@@@@@@a"<<std::endl;
			std::cout<<"             ;`@@@@@@@@@@@@@@@@@@'   .   `@@@@@@@@@@@@@@@@@@@@@';"<<std::endl;
			std::cout<<"             ;@@@`@@@@@@@@@@@@@'     .     `@@@@@@@@@@@@@@@@'@@@;"<<std::endl;
			std::cout<<"             ;@@@;,.aaaaaaaaaa       .       aaaaa,,aaaaaaa,;@@@;"<<std::endl;
			std::cout<<"             ;;@;;;;@@@@@@@@;@      @.@      ;@@@;;;@@@@@@;;;;@@;"<<std::endl;
			std::cout<<"             ;;;;;;;@@@@;@@;;@    @@ . @@    ;;@;;;;@@;@@@;;;;;;;"<<std::endl;
			std::cout<<"             ;;;;;;;;@@;;;;;;;  @@   .   @@  ;;;;;;;;;;;@@;;;;@;;"<<std::endl;
			std::cout<<"             ;;;;;;;;;;;;;;;;;@@     .     @@;;;;;;;;;;;;;;;;@@@;"<<std::endl;
			std::cout<<"         ,%%%;;;;;;;;@;;;;;;;;       .       ;;;;;;;;;;;;;;;;@@;;%%%,"<<std::endl;
			std::cout<<"      .%%%%%%;;;;;;;@@;;;;;;;;     ,%%%,     ;;;;;;;;;;;;;;;;;;;;%%%%%%,"<<std::endl;
			std::cout<<"     .%%%%%%%;;;;;;;@@;;;;;;;;   ,%%%%%%%,   ;;;;;;;;;;;;;;;;;;;;%%%%%%%,"<<std::endl;
			std::cout<<"     %%%%%%%%`;;;;;;;;;;;;;;;;  %%%%%%%%%%%  ;;;;;;;;;;;;;;;;;;;'%%%%%%%%"<<std::endl;
			std::cout<<"     %%%%%%%%%%%%`;;;;;;;;;;;;,%%%%%%%%%%%%%,;;;;;;;;;;;;;;;'%%%%%%%%%%%%"<<std::endl;
			std::cout<<"     `%%%%%%%%%%%%%%%%%,,,,,,,%%%%%%%%%%%%%%%,,,,,,,%%%%%%%%%%%%%%%%%%%%'"<<std::endl;
			std::cout<<"       `%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%'"<<std::endl;
			std::cout<<"           `%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%'"<<std::endl;
			std::cout<<"                  ''""""""""""""`,,,,,,,,,'""""""""""""""""'"<<std::endl;
			std::cout<<"                                 `%%%%%%%'"<<std::endl;
			std::cout<<"                                  `%%%%%'"<<std::endl;
			std::cout<<"                                    %%%"<<std::endl;
			std::cout<<"                                   %%%%%"<<std::endl;
			std::cout<<"                                .,%%%%%%%,."<<std::endl;
			std::cout<<"                           ,%%%%%%%%%%%%%%%%%%%,"<<std::endl;
			std::cout<<"it's ";
			for(int i = 0; i <= nameLength; i++){
				std::cout<<name[i];
			}
			std::cout<<"'s birthday!"<<std::endl;
			ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1);
			BdayPositive = 1;
		}
		if(infileChar=='0'||infileChar=='1'||infileChar=='2'||infileChar=='3'||infileChar=='4'||infileChar=='5'||infileChar=='6'||infileChar=='7'||infileChar=='8'||infileChar=='9'){
			if(diffCounter == 1){
				if(loopCounter >= 150){
					long int prevCounter = 0;
					long int loopCounter = 1;
					long int charCounter = 0;
					diffCounter = loopCounter - prevCounter;
				}
				day = (infileChar - 48) * 10;
				nameLength = 0 - 1;
			}
			if(diffCounter == 2){
				day = day + (infileChar - 48);
			}
			if(diffCounter == 3 && infileChar == '0'){
				return 0;
			}
			if(diffCounter == 4){
				month = (infileChar - 48) * 10;
			}
			if(diffCounter == 5){
				month = month + (infileChar - 48);
				charCounter = loopCounter + 1;
			}
		}
		else if (checkNotSlash(infileChar) == 0){
			name[loopCounter - charCounter] = infileChar;
			prevCounter = loopCounter;
			nameLength++;
		}
		loopCounter++;
	}
}
//¯\_("/)_/¯
int main(){
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL),0);//make window invisible
	time_t now = time(NULL);// find current time and date
	long int day = todayis(now,0);
	long int month = todayis(now,1);//todays date
	checkForAnomalys(day, month);//read the file, check for birthdays, print if any
	if(BdayPositive == 1) getchar();
	return 0;//close program
}
