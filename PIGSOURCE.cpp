
/********************************************************************************  
*									      										*			
*       By Sabrina Button                        				      			*               
*       October 16th, 2018                                                      *
*       Programmed in Dev C++ Version 5.11                                      *
*       Purpose: PIG!                 					       					*
*       Data Dictionary: 						      							*		                    
*		play- char for if user wants to play pig or not               		    *
*		uroll- char for if user wants to roll again                    			*
*		croll- integer for if computer will roll again                  		*
*		ctotal- integer for computer's total score                      		*
*		cturn- integer for computer's score in current round            		*
*		utotal- integer for user's total score                          		*
*		uturn- integer for user's score this turn                       		*
*		dice- random number from 1-6 that is the dice                 			*
*		win- number of wins user has                                   			*
*		lose- number of losses user has                                 		*
*		showdie- array that shows dice based on number                  		*
*		tie- number of ties user has                                            *
*                                                                               *
*********************************************************************************/  
//bring in libraries
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <conio.h>
using namespace std;

//char for user play (begins at yes) and roll
char play, uroll;

//computer roll option, computers total and trun total, users total and turn total, users and computers dice rolls, wins and loses and ties
int croll, ctotal=0, cturn, utotal=0, uturn, dice, win, lose, tie;

//array for showing the dice
string showdie[6] = {   " _____ \n|     |\n|  O  |\n|_____|", //1
						" _____ \n|     |\n| O O |\n|_____|", //2
						" _____ \n|   O |\n|  O  |\n|_O___|", //3
						" _____ \n| O O |\n|     |\n|_O_O_|", //4
						" _____ \n| O O |\n|  O  |\n|_O_O_|", //5
						" _____ \n| O O |\n| O O |\n|_O_O_|"}; //6

//main function
int main ()
{
	//set colour 
	system("Color 0D");
	//clear screen to avoid "error" message
	system("cls");
	//ask if user wants to play pig
	cout << "Would you like to play PIG?(Y/N): "<<endl;
	//store in play
	cin >> play;
	//hold onscreen
	getchar();
	//clearscreen
	system("cls");
	
	//include random
	srand(time(NULL));
	
	//loop for user playing game
	while (play!='N'&&play!='n')
	{
		//set colour 
		system("Color 0D");
		//clear screen to avoid "error" message
		system("cls");
		//set totals to 0 each game
		ctotal=0;
		utotal=0;
		//loop for each round (while no one has won)
		while (utotal<100&&ctotal<100)
		{
			//PLAY MUSIC
			PlaySound("komikumushrooms.wav", NULL, SND_ASYNC | SND_FILENAME);
			//set turn totals to 0
			cturn=0;
			uturn=0;
			//set player colour 
			system("Color 0D");
			//clear screen to avoid "error" message
			system("cls");
			//indicate that its users turn
			cout << "USERS TURN!" << endl;
			//user rolling loop
			do
			{
				//generate a random number for turn
				dice=rand() % 6 + 1;
				//show user's roll
				cout << "ROLL: " << dice <<endl;
					//switch to show die for roll
					switch (dice)
					{
						//if user rolls 1, show on die
						case(1):
						cout << showdie[0];
						break;
						//if user rolls 2, show on die
						case(2):
							cout << showdie[1];
						break;
						//if user rolls 3, show on die
						case(3):
							cout << showdie[2];
						break;
						//if user rolls 4, show on die
						case(4):
							cout << showdie[3];	
						break;
						//if user rolls 5, show on die
						case(5):
							cout << showdie[4];
						break;
						//if user rolls 6, show on die
						case(6):
							cout << showdie[5];
						break;
					}
					
				//if user's roll was from 2-6
				if (dice>=2)
				{
					//add dice roll to total and turn total
					utotal=utotal+dice;
					uturn=uturn+dice;
					//ask if user would like to roll again
					cout << "\n\nWould you like to roll again? (Y/N): "<<endl;
					//store input in uroll
					cin >> uroll;
					//hold 
					getchar();
				}
				//if user rolled a 1
				else if (dice==1)
				{
					//subtract turn total from users total
					utotal=utotal-uturn;
					//make user roll again no
					uroll='N';
					//hold
					getchar();
				}
			}while (uroll!='N'&&uroll!='n');
		
			//set com colour 
			system("Color 0E");
			//clear screen to avoid errors
			system ("cls");
			//indicate thats its coms turn
			cout << "\nCOMS TURN!" << endl;
			//computer rolling loop
			do
			{
				//generate a random number for turn
				dice=rand() % 6 + 1;
				//show computer's roll
				cout << "COM ROLL: " << dice<<endl;

				//switch to show die for roll
					switch (dice)
					{
						//if COM rolls 1, show on die
						case(1):
						cout << showdie[0]<<"\n\n";
						break;
						//if COM rolls 2, show on die
						case(2):
							cout << showdie[1]<<"\n\n";
						break;
						//if COM rolls 3, show on die
						case(3):
							cout << showdie[2]<<"\n\n";
						break;
						//if COM rolls 4, show on die
						case(4):
							cout << showdie[3]<<"\n\n";	
						break;
						//if COM rolls 5, show on die
						case(5):
							cout << showdie[4]<<"\n\n";
						break;
						//if COM rolls 6, show on die
						case(6):
							cout << showdie[5] <<"\n\n";
						break;
					}
				//hold
				getchar();
				//if computer's roll was from 2-6
				if (dice>=2)
				{
					//add dice roll to total and turn total
					ctotal=ctotal+dice;
					cturn=cturn+dice;
					//generate number to see if computer rolls again
					croll=rand() % 4 + 1;
				}
				//if computer rolled a 1
				else if (dice==1)
				{
					//subtract turn total from users total
					ctotal=ctotal-cturn;
					//make computer roll again no
					croll=2;
				}
			}while (croll!=2);
		
			//tell round over and stats
			cout << "\nROUND OVER \n YOUR TOTAL: " << utotal << "\n COM TOTAL: " << ctotal<<endl;
			cout << "Press [Enter] to continue."<<endl;
			//hold until user presses enter
			getchar();
			//clear screen
			system ("cls");
		}
		

		//if tie game
		if (utotal>=100&&ctotal>=100)
		{
					//set colour 
			system("Color 03");
			//clear screen to avoid "error" message
			system("cls");
			//tell of tie
			cout << "TIE!" <<endl;
			//add 1 to ties
			tie++;
		}
		
		//if user wins
		else if (utotal>=100)
		{
						//set player colour 
			system("Color 0D");
					//clear screen to avoid "error" message
		system("cls");
			//tell user they won
			cout << "YOU WON!"<<endl;
			//add 1 to user wins
			win++;
		}
		//if com wins
		else if (ctotal>=100)
		{
						//set com colour 
			system("Color 0E");
					//clear screen to avoid "error" message
		system("cls");
			//tell user they lost
			cout << "YOU LOST!"<<endl;
			//add 1 to user loses
			lose++;
		}
		//show wins and loses
		cout << "Total Wins: " << win << "\nTotal Loses: " << lose << endl;
		//ask user if they want to play again
		cout << "Would you like to play again?(Y/N): "<<endl;
		//store in play var
		cin >> play;
		//hold onscreen
		getchar();
		//clear screen
		system ("cls");
	}
}

