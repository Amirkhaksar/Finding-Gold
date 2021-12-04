#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <gl/freeglut.h>
using namespace std;

int Display_Player1_X, Display_Player1_Y;
int Display_Player2_X, Display_Player2_Y;
int Display_Player3_X, Display_Player3_Y;
int Display_Player4_X, Display_Player4_Y;

std::string Display_PlayerName;
enum class Pieces { Knight = 0, Rook = 1, Bishop = 2 };
int Rows, Columns;
bool arePlayer;

int random_generator(int number)
{
	unsigned int Temp_random;
	std::random_device random;
	std::mt19937 gen(random());
	switch (number)
	{
	case 8:
		Temp_random = (gen() % 8);
		return Temp_random;
		break;
	case 3:
		Temp_random = ((gen() % 3));
		return Temp_random;
		break;
	case 2:
		Temp_random = (gen() % 2);
		return Temp_random;
		break;
	}
}

void myInit(void)
{
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(10);
	glutInitDisplayMode(GLUT_SINGLE | GL_RGBA);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluOrtho2D(240, 0, 240, 0);
	gluOrtho2D(0, 240, 240, 0);
}


void processInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 13:
		//Enter for open Log file
		system("log.csv");
	case 27:
		//Escape for terminate program
		const int windowID = glutCreateWindow("FindingGold");
		glutDestroyWindow(windowID);
		exit(0);
		break;
	}
}


void DisplayChessBoard(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	unsigned int Gold_Position_Rows = ((Rows - 1) * 30);
	if (Gold_Position_Rows >= 240 )
	{
		Gold_Position_Rows = 0;
	}
	
	
	unsigned int Gold_Position_Columns = ((Columns - 1) * 30);
	if (Gold_Position_Columns >= 240)
	{
		Gold_Position_Columns = 0;
	}
	
	
	unsigned int Position_Player1_X = ((Display_Player1_X - 1) * 30);
	if (Position_Player1_X >= 240)
	{
		Position_Player1_X = 0;
	}
	
	
	unsigned int Position_Player1_Y = ((Display_Player1_Y - 1) * 30);
	if (Position_Player1_Y >= 240)
	{
		Position_Player1_Y = 0;
	}
	
	
	unsigned int Position_Player2_X = ((Display_Player2_X - 1) * 30);
	if (Position_Player2_X >= 240)
	{
		Position_Player2_X = 0;
	}
	
	unsigned int Position_Player2_Y = ((Display_Player2_Y - 1) * 30);
	if (Position_Player2_Y >= 240)
	{
		Position_Player2_Y = 0;
	}
	
	
	unsigned int Position_Player3_X = ((Display_Player3_X - 1) * 30);
	if (Position_Player3_X >= 240)
	{
		Position_Player3_X = 0;
	}
	if (arePlayer == false)
	{
		if ((Display_Player3_X == 0) && (Position_Player3_X == 0))
		{
			Position_Player3_X = random_generator(8) * 1000;
		}
	}

	
	unsigned int Position_Player3_Y = ((Display_Player3_Y - 1) * 30);
	if (Position_Player3_Y >= 240)
	{
		Position_Player3_Y = 0;
	}
	if (arePlayer == false)
	{
		if ((Display_Player3_Y == 0) && (Position_Player3_Y == 0))
		{
			Position_Player3_Y = random_generator(8) * 1000;
		}
	}
	
	
	unsigned int Position_Player4_X = ((Display_Player4_X - 1) * 30);
	if (Position_Player4_X >= 240)
	{
		Position_Player4_X = 0;
	}
	if (arePlayer == false)
	{
		if ((Display_Player4_X == 0) && (Position_Player4_X == 0))
		{
			Position_Player4_X = random_generator(8) * 1000;
		}
	}
	
	
	unsigned int Position_Player4_Y = ((Display_Player4_Y - 1) * 30);
	if (Position_Player4_Y >= 240)
	{
		Position_Player4_Y = 0;
	}
	if (arePlayer == false)
	{
		if ((Display_Player4_Y == 0) && (Position_Player4_Y == 0))
		{
			Position_Player4_Y = random_generator(8) * 1000;
		}
	}
	
	
	for (GLint x = 0; x < 240; x += 30)
	{
		for (GLint y = 0; y < 240; y += 30)
		{
			if (((x + y) / 30) & 1)
			{

				glColor3f(1, 1, 1);

			}
			else
			{

				glColor3f(0, 0, 0);


			}

			if (x == Position_Player1_X)
			{
				if (y == Position_Player1_Y)
				{
					glColor4f(0, 1, 0, 1);
				}
			}
			if (x == Position_Player2_X)
			{
				if (y == Position_Player2_Y)
				{
					glColor4f(1, 0, 0, 1);
				}
			}
			if (x == Position_Player3_X)
			{
				if (y == Position_Player3_Y)
				{
					glColor4f(0, 0, 1, 1);
				}
			}
			if (x == Position_Player4_X)
			{
				if (y == Position_Player4_Y)
				{
					glColor4f(0.5, 0.5, 0.5, 1);
				}
			}

			if (x == Gold_Position_Rows)
			{
				if (y == Gold_Position_Columns)
				{
					glColor4f(1, 1, 0, 1);
				}
			}
			glRecti(x, y, (x + 30), (y + 30));
		}//end of y
	}//end of x

	glutSwapBuffers();
	glFlush();
}

void RenderString(GLint x, GLint y, const unsigned char* string)
{
	glColor3f(1, 0, 0);
	glRasterPos2i(x, y);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, string);
}

void MassageBox(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	auto const PlayerName_2Show_ONScreen = reinterpret_cast<const unsigned char*> (Display_PlayerName.c_str());
	RenderString(20, 130, PlayerName_2Show_ONScreen);
	auto const Congratulations_Massage = reinterpret_cast<const unsigned char*>("Congratulations you won this game");
	RenderString(50, 130, Congratulations_Massage);
	glutSwapBuffers();
	glFlush();
}