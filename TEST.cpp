//inclusions
#include <stdio.h> //i keyboard
#include <ctime> //random int
#include <cstdlib> //library for random

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//globals
string qa[100][2];
int Q = 0;
int A = 1;
int max_qa = 0;

//functions
int init_qa();
int game_on();

//main function
int main()
{
	//init all vars
	init_qa();

	//play game
	game_on();

	//print game over
	printf("Game Over!");
	getchar();
	return 0;
}

//init all vars
int init_qa()
{
	//open file
	ifstream infile;
	infile.open("test.txt");

	//cannot read file
	if(!infile)
	{
		printf("Unable to open file.");
		getchar();
		exit(1);   // call system to stop
	}

	//read values
	string tmp;
	getline(infile,tmp);
	for(int i = 0;!infile.eof();i++)
	{
		getline(infile,qa[i][A]);
		getline(infile,qa[i][Q]);
		getline(infile,tmp);
		max_qa++;
		printf("IMPORTING Q: %s;A: %s \n",qa[i][Q].c_str(),qa[i][A].c_str());
	}
	max_qa--;

	//cleanup
	infile.close();
	return 0;
}

//game play
int game_on()
{
	//init vars
	string status = "";
	string v_q = "";
	string v_a[4];
	int correct = 0;
	int select = 0;
	int tmp = 0;
	srand(static_cast<unsigned int>(time(0)));

	//header
	printf("Test!\nAttempt to study!! Press 5 to exit\n");

	//check for exit
	while(select < 5)
	{
		//collect a question
		correct = rand() % max_qa;
		v_q = qa[correct][Q];
		tmp = rand() % 4;
		v_a[tmp % 4] = qa[correct][A];
		v_a[(tmp + 1) % 4] = qa[rand() % max_qa][A];
		v_a[(tmp + 2) % 4] = qa[rand() % max_qa][A];
		v_a[(tmp + 3) % 4] = qa[rand() % max_qa][A];
		correct = tmp;

		//printing game
		printf("\n\n%s \n Q: %s \n A1: %s \n A2: %s \n A3: %s \n A4: %s \n Select an answer number>",status.c_str(),v_q.c_str(),v_a[0].c_str(),v_a[1].c_str(),v_a[2].c_str(),v_a[3].c_str());
		scanf("%d",&select);
		getchar();

		//check for exit command
		if(select < 5)
		{
			select--;
			if(select == correct)
			{
				status = "CORRECT";
			}
			else
			{
				status = "INCORRECT";
			}
		}

		//loop
	}
}
