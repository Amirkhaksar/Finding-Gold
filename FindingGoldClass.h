#pragma once
#include "FindingGoldHeaderFile.h"
class FindingGold
{
private:
	std::string PlayerName;
	Pieces chesspeces;
	
	int Knight_X, Knight_Y;
	int Rook_X, Rook_Y;
	int Bishop_X, Bishop_Y;
	int Knight_Make_X[8] = { 0 };
	int Knight_Make_Y[8] = { 0 };
	
	void Make_Knight_Move(int x, int y)
	{
		Knight_Make_X[0] = x - 2;
		Knight_Make_Y[0] = y + 1;

		Knight_Make_X[1] = x - 2;
		Knight_Make_Y[1] = y - 1;

		Knight_Make_X[2] = x + 2;
		Knight_Make_Y[2] = y + 1;

		Knight_Make_X[3] = x + 2;
		Knight_Make_Y[3] = y - 1;

		Knight_Make_X[4] = x - 1;
		Knight_Make_Y[4] = y + 2;

		Knight_Make_X[5] = x + 1;
		Knight_Make_Y[5] = y + 2;

		Knight_Make_X[6] = x - 1;
		Knight_Make_Y[6] = y - 2;

		Knight_Make_X[7] = x + 1;
		Knight_Make_Y[7] = y - 2;

		for (int i = 0; i < 8; i++)
		{
			if (Knight_Make_X[i] < 0)
			{
				Knight_Make_X[i] = -1;
			}
			if (Knight_Make_Y[i] < 0)
			{
				Knight_Make_Y[i] = -1;

			}
		}
	}
	
public:

	FindingGold(std::string name)
	{
		try
		{
			std::ofstream ObjectWrite2log;
			ObjectWrite2log.open("log.csv", std::ios::app);
			if (name.empty())
			{
				throw (PlayerName);
			}
			this->PlayerName = name;
			int i = random_generator(3);
			chesspeces = static_cast<Pieces>(i);
			ObjectWrite2log << PlayerName << ",";
			switch (chesspeces)
			{
			case Pieces::Knight:
				Knight_X = random_generator(8);
				Knight_Y = random_generator(8);
				Make_Knight_Move(Knight_X, Knight_Y);
				ObjectWrite2log << "Knight" << "," << Knight_X << "," << Knight_Y << "\n";
				break;
			case Pieces::Rook:
				Rook_X = random_generator(8);
				Rook_Y = random_generator(8);
				ObjectWrite2log << "Rook" << "," << Rook_X << "," << Rook_Y << "\n";
				break;
			case Pieces::Bishop:
				Bishop_X = random_generator(8);
				Bishop_Y = random_generator(8);
				ObjectWrite2log << "Bishop" << "," << Bishop_X << "," << Bishop_Y << "\n";
				break;
			default:
				break;
			}
			ObjectWrite2log.close();
		}
		catch (string name)
		{
			arePlayer = false;
			cout << "\a";
		}
		
	}

	void Move_Knight()
	{
		std::ofstream ObjectWrite2log;
		ObjectWrite2log.open("log.csv", std::ios::app);
		Make_Knight_Move(Knight_X, Knight_Y);
		int random = random_generator(8) + 1;
		while (true)
		{
			
			random = random_generator(8);
			Knight_X = Knight_Make_X[random];
			Knight_Y = Knight_Make_Y[random];
			
		
			if (Knight_X > 7 || Knight_Y > 7)
				continue;
			if (Knight_X == -1 || Knight_Y == -1)
				continue;
			else
				break;
		}

		ObjectWrite2log << "\n" << this->PlayerName << "," << "Knight" << "," << Knight_X << "," << Knight_Y << ",";

		if (random == 0 || random == 1)
		{
			ObjectWrite2log << "Left" << "\n";
		}
		else if (random == 2 || random == 3)
		{
			ObjectWrite2log << "Right" << "\n";
		}
		else if (random == 4 || random == 5)
		{
			ObjectWrite2log << "Up" << "\n";
		}
		else if (random == 6 || random == 7)
		{
			ObjectWrite2log << "Down" << "\n";
		}
		ObjectWrite2log.close();
	}
	
	void Move_Rook()
	{
		std::ofstream ObjectWrite2log;
		ObjectWrite2log.open("log.csv", std::ios::app);
		int Temp_RookX = Rook_X;
		int Temp_RookY = Rook_Y;
		int random = random_generator(2);;

		if (random == 0)
		{
			while (true)
			{
				Rook_Y = random_generator(8) + 1;
				if (Rook_Y == Temp_RookY)
				{
					continue;
				}
				break;
			}
		}
		else
		{
			while (true)
			{
				Rook_X = random_generator(8) + 1;
				if (Rook_X == Temp_RookX)
				{
					continue;
				}
				break;
			}
		}
		ObjectWrite2log << "\n" << this->PlayerName << "," << "Rook" << "," << Rook_X << "," << Rook_Y << ",";
		
		if (Temp_RookX > Rook_X&& Rook_Y == Temp_RookY)
		{
			ObjectWrite2log << "Left & 1" << "\n";
		}
		else if (Temp_RookX == Rook_X && Rook_Y > Temp_RookY)
		{
			ObjectWrite2log << "Up & 2" << "\n";
		}
		else if (Temp_RookX == Rook_X && Rook_Y < Temp_RookY)
		{
			ObjectWrite2log << "Down & 3" << "\n";
		}
		else if (Temp_RookX < Rook_X && Rook_Y == Temp_RookY)
		{
			ObjectWrite2log << "Right & 4" << "\n";
		}
		ObjectWrite2log.close();
	}
	
	void Move_Bishop()
	{
		std::ofstream ObjectWrite2log;
		ObjectWrite2log.open("log.csv", std::ios::app);
		int Temp_BishopX = Bishop_X;
		int Temp_bishopY = Bishop_Y;
		while (true)
		{
			Bishop_X = random_generator(8) + 1;
			Bishop_Y = random_generator(8) + 1;
			if ((abs(Bishop_X - Temp_BishopX) == abs(Bishop_Y - Temp_bishopY)) && Bishop_X - Temp_BishopX != 0)
			{
				break;
			}
		}
		
		ObjectWrite2log << "\n" << this->PlayerName << "," << "Bishop" << "," << Bishop_X << "," << Bishop_Y << ",";

		if ((Temp_BishopX < Bishop_X) && (Temp_bishopY > Bishop_Y))
		{
			ObjectWrite2log << "Down and Right & 1" << "\n";
		}
		else if ((Temp_BishopX > Bishop_X )&& (Temp_bishopY > Bishop_Y))
		{
			ObjectWrite2log << "Down and Left & 2 " << "\n";
		}
		else if ((Temp_BishopX > Bishop_X )&& (Temp_bishopY < Bishop_Y))
		{
			ObjectWrite2log << "Up and Left & 3" << "\n";
		}
		else if ((Temp_BishopX < Bishop_X) && (Temp_bishopY < Bishop_Y))
		{
			ObjectWrite2log << "Up and Right & 4" << "\n";
		}
		ObjectWrite2log.close();
	}

	bool CheckingPosition(Pieces TempForChecking)
	{
		
		if (TempForChecking == Pieces::Knight)
		{
			if (Knight_X == Rows && Knight_Y == Columns)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (TempForChecking == Pieces::Rook)
		{
			if (Rook_X == Rows && Rook_Y == Columns)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (TempForChecking == Pieces::Bishop)
		{
			if (Bishop_X == Rows && Bishop_Y == Columns)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}
	
	int GetRows() { return Rows; }

	int GetColumns() { return Columns; }

	int GetKnightX() { return Knight_X; }

	int GetKnightY() { return Knight_Y; }

	int GetRookX() { return Rook_X; }

	int GetRookY() { return Rook_Y; }

	int GetBishopX() { return Bishop_X; }
	
	int GetBishopY() { return Bishop_Y; }

	Pieces GetPiece() { return chesspeces; }

	std::string GetPlayerName() { return PlayerName; }
};