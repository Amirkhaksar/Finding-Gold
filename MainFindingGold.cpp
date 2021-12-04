#include "FindingGoldHeaderFile.h"
#include "FindingGoldClass.h"

int main(int argc, char** argv)
{
	std::ofstream ObjectWrite2log;
	bool fileCantOpen = false;
	try
	{
		remove("log.csv");
		ObjectWrite2log.open("log.csv", std::ios::app);
		if (!ObjectWrite2log.is_open())
		{
			throw fileCantOpen ;
		}
		ObjectWrite2log << "PlayerName" << "," << "Name of Piece" << "," << "Rows For begin" << "," << "Columns for begin" << "," << "Color of Player" << "\n";
		ObjectWrite2log.close();
	}
	catch (bool fileCantOpen)
	{
		cout << "We can't open this file.\nPlease close the file and run the program again for the program to run properly.\n";
		system("pause");
	}
	
	std::string PlayerName[4];
	
	int MaxPlayer = 2;
	int addplayer;

	
	for (int count = 0; count < 4; count++)
	{
		if (MaxPlayer == 2)
		{
			for (int i = 0 ; i < 2 ; i++)
			{
				std::cout << "Enter Player  " << i + 1 << "  name: ";
				std::cin >> PlayerName[i];
				
			}
		}
		else if (MaxPlayer > 2)
		{
			std::cout << "Enter Player  " << MaxPlayer << "  name: ";
			std::cin >> PlayerName[MaxPlayer - 1];
		}
		
		if (MaxPlayer == 4)
		{
			break;
		}
		else
		{
			std::cout << "\nDo you want add player?  1)Yes 0)no   ";
			std::cin >> addplayer;

			if (addplayer == 1)
			{
				MaxPlayer++;
			}
			else if (addplayer == 0)
			{
				
				PlayerName[MaxPlayer].empty();
				break;
			}
			else
			{
				std::cout << "Error invalid option" << std::endl;
				exit(0);
			}
		}
	}
	
	Rows = random_generator(8) + 1;
	Columns = random_generator(8) + 1;
	
	FindingGold Player1(PlayerName[0]), Player2(PlayerName[1]) ,Player3(PlayerName[2]) , Player4(PlayerName[3]);
		
	ObjectWrite2log.open("log.csv", std::ios::app);
	ObjectWrite2log << "..........................................................................................................................." << "\n";
	ObjectWrite2log << " Gold  " << "," << " Gold" << "," << Rows << "," << Columns << "\n";
	ObjectWrite2log << "..........................................................................................................................." << "\n";
	ObjectWrite2log << "PlayerName"<<"," <<" Name of Piece "<< "," << "Rows" << "," << "Columns" << "," <<"Direction & Type of Move " << "," << "\n";
	ObjectWrite2log.close(); 

	while (true)
	{
		if (MaxPlayer == 2)
		{
			if (Player1.GetPiece() == Pieces::Knight)
			{
				Player1.Move_Knight();
				if (Player1.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
			}

			else if (Player1.GetPiece() == Pieces::Rook)
			{
				Player1.Move_Rook();
				if (Player1.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();

				}
			}

			else if (Player1.GetPiece() == Pieces::Bishop)
			{
				Player1.Move_Bishop();
				if (Player1.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}
			}

			if (Player1.CheckingPosition(Pieces::Knight) || Player1.CheckingPosition(Pieces::Rook) || Player1.CheckingPosition(Pieces::Bishop))
			{
				if (Player2.GetPiece() == Pieces::Knight)
				{
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
				else if (Player2.GetPiece() == Pieces::Rook)
				{
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
				else if (Player2.GetPiece() == Pieces::Bishop)
				{
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();
				}
				break;
			}

			if (Player2.GetPiece() == Pieces::Knight)
			{
				Player2.Move_Knight();
				if (Player2.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
			}

			else if (Player2.GetPiece() == Pieces::Rook)
			{
				Player2.Move_Rook();
				if (Player2.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
			}

			else if (Player2.GetPiece() == Pieces::Bishop)
			{
				Player2.Move_Bishop();
				if (Player2.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();

				}
			}

			if (Player2.CheckingPosition(Pieces::Knight) || Player2.CheckingPosition(Pieces::Rook) || Player2.CheckingPosition(Pieces::Bishop))
			{
				if (Player1.GetPiece() == Pieces::Knight)
				{
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
				else if (Player1.GetPiece() == Pieces::Rook)
				{
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();
				}
				else  if (Player1.GetPiece() == Pieces::Bishop)
				{
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}
				break;
			}
		}
		if (MaxPlayer == 3)
		{
			if (Player1.GetPiece() == Pieces::Knight)
			{
				Player1.Move_Knight();
				if (Player1.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
			}

			else if (Player1.GetPiece() == Pieces::Rook)
			{
				Player1.Move_Rook();
				if (Player1.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();

				}
			}

			else if (Player1.GetPiece() == Pieces::Bishop)
			{
				Player1.Move_Bishop();
				if (Player1.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}
			}

			if (Player1.CheckingPosition(Pieces::Knight) || Player1.CheckingPosition(Pieces::Rook) || Player1.CheckingPosition(Pieces::Bishop))
			{
				if (Player2.GetPiece() == Pieces::Knight)
				{
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
				else if (Player2.GetPiece() == Pieces::Rook)
				{
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
				else if (Player2.GetPiece() == Pieces::Bishop)
				{
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();
				}

				if (Player3.GetPiece() == Pieces::Knight)
				{
					Display_Player3_X = Player3.GetKnightX();
					Display_Player3_Y = Player3.GetKnightY();
				}
				else if (Player3.GetPiece() == Pieces::Rook)
				{
					Display_Player3_X = Player3.GetRookX();
					Display_Player3_Y = Player3.GetRookY();
				}
				else if (Player3.GetPiece() == Pieces::Bishop)
				{
					Display_Player3_X = Player3.GetBishopX();
					Display_Player3_Y = Player3.GetBishopY();
				}

				break;

			}

			if (Player2.GetPiece() == Pieces::Knight)
			{
				Player2.Move_Knight();
				if (Player2.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
			}

			else if (Player2.GetPiece() == Pieces::Rook)
			{
				Player2.Move_Rook();
				if (Player2.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
			}

			else if (Player2.GetPiece() == Pieces::Bishop)
			{
				Player2.Move_Bishop();
				if (Player2.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();

				}
			}

			if (Player2.CheckingPosition(Pieces::Knight) || Player2.CheckingPosition(Pieces::Rook) || Player2.CheckingPosition(Pieces::Bishop))
			{
				if (Player1.GetPiece() == Pieces::Knight)
				{
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
				else if (Player1.GetPiece() == Pieces::Rook)
				{
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();
				}
				else  if (Player1.GetPiece() == Pieces::Bishop)
				{
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}

				if (Player3.GetPiece() == Pieces::Knight)
				{
					Display_Player3_X = Player3.GetKnightX();
					Display_Player3_Y = Player3.GetKnightY();
				}
				else if (Player3.GetPiece() == Pieces::Rook)
				{
					Display_Player3_X = Player3.GetRookX();
					Display_Player3_Y = Player3.GetRookY();
				}
				else if (Player3.GetPiece() == Pieces::Bishop)
				{
					Display_Player3_X = Player3.GetBishopX();
					Display_Player3_Y = Player3.GetBishopY();
				}
				break;

			}

			if (Player3.GetPiece() == Pieces::Knight)
			{
				Player3.Move_Knight();
				if (Player3.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player3.GetPlayerName();
					Rows = Player3.GetRows();
					Columns = Player3.GetColumns();
					Display_Player3_X = Player3.GetKnightX();
					Display_Player3_Y = Player3.GetKnightY();

				}
			}

			else if (Player3.GetPiece() == Pieces::Rook)
			{
				Player3.Move_Rook();
				if (Player3.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player3.GetPlayerName();
					Rows = Player3.GetRows();
					Columns = Player3.GetColumns();
					Display_Player3_X = Player3.GetRookX();
					Display_Player3_Y = Player3.GetRookY();

				}
			}

			else if (Player3.GetPiece() == Pieces::Bishop)
			{
				Player3.Move_Bishop();
				if (Player3.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player3.GetPlayerName();
					Rows = Player3.GetRows();
					Columns = Player3.GetColumns();
					Display_Player3_X = Player3.GetBishopX();
					Display_Player3_Y = Player3.GetBishopY();
				}
			}

			if (Player3.CheckingPosition(Pieces::Knight) || Player3.CheckingPosition(Pieces::Rook) || Player3.CheckingPosition(Pieces::Bishop))
			{
				if (Player1.GetPiece() == Pieces::Knight)
				{
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
				else if (Player1.GetPiece() == Pieces::Rook)
				{
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();
				}
				else if (Player1.GetPiece() == Pieces::Bishop)
				{
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}

				if (Player2.GetPiece() == Pieces::Knight)
				{
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
				else if (Player2.GetPiece() == Pieces::Rook)
				{
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
				else if (Player2.GetPiece() == Pieces::Bishop)
				{
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();
				}

				break;
			}
		}
		if (MaxPlayer == 4)
		{
			if (Player1.GetPiece() == Pieces::Knight)
			{
				Player1.Move_Knight();
				if (Player1.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
			}

			else if (Player1.GetPiece() == Pieces::Rook)
			{
				Player1.Move_Rook();
				if (Player1.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();
				}
			}

			else if (Player1.GetPiece() == Pieces::Bishop)
			{
				Player1.Move_Bishop();
				if (Player1.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player1.GetPlayerName();
					Rows = Player1.GetRows();
					Columns = Player1.GetColumns();
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}
			}

			if (Player1.CheckingPosition(Pieces::Knight) || Player1.CheckingPosition(Pieces::Rook) || Player1.CheckingPosition(Pieces::Bishop))
			{
				if (Player2.GetPiece() == Pieces::Knight)
				{
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
				else if (Player2.GetPiece() == Pieces::Rook)
				{
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
				else if (Player2.GetPiece() == Pieces::Bishop)
				{
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();
				}

				if (Player3.GetPiece() == Pieces::Knight)
				{
					Display_Player3_X = Player3.GetKnightX();
					Display_Player3_Y = Player3.GetKnightY();
				}
				else if (Player3.GetPiece() == Pieces::Rook)
				{
					Display_Player3_X = Player3.GetRookX();
					Display_Player3_Y = Player3.GetRookY();
				}
				else if (Player3.GetPiece() == Pieces::Bishop)
				{
					Display_Player3_X = Player3.GetBishopX();
					Display_Player3_Y = Player3.GetBishopY();
				}

				if (Player4.GetPiece() == Pieces::Knight)
				{
					Display_Player4_X = Player4.GetKnightX();
					Display_Player4_Y = Player4.GetKnightY();
				}
				else if (Player4.GetPiece() == Pieces::Rook)
				{
					Display_Player4_X = Player4.GetRookX();
					Display_Player4_Y = Player4.GetRookY();
				}
				else if (Player4.GetPiece() == Pieces::Bishop)
				{
					Display_Player4_X = Player4.GetBishopX();
					Display_Player4_Y = Player4.GetBishopY();
				}

				break;

			}

			if (Player2.GetPiece() == Pieces::Knight)
			{
				Player2.Move_Knight();
				if (Player2.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
			}

			else if (Player2.GetPiece() == Pieces::Rook)
			{
				Player2.Move_Rook();
				if (Player2.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
			}

			else if (Player2.GetPiece() == Pieces::Bishop)
			{
				Player2.Move_Bishop();
				if (Player2.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player2.GetPlayerName();
					Rows = Player2.GetRows();
					Columns = Player2.GetColumns();
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();

				}
			}

			if (Player2.CheckingPosition(Pieces::Knight) || Player2.CheckingPosition(Pieces::Rook) || Player2.CheckingPosition(Pieces::Bishop))
			{
				if (Player1.GetPiece() == Pieces::Knight)
				{
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
				else if (Player1.GetPiece() == Pieces::Rook)
				{
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();
				}
				else  if (Player1.GetPiece() == Pieces::Bishop)
				{
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}

				if (Player3.GetPiece() == Pieces::Knight)
				{
					Display_Player3_X = Player3.GetKnightX();
					Display_Player3_Y = Player3.GetKnightY();
				}
				else if (Player3.GetPiece() == Pieces::Rook)
				{
					Display_Player3_X = Player3.GetRookX();
					Display_Player3_Y = Player3.GetRookY();
				}
				else if (Player3.GetPiece() == Pieces::Bishop)
				{
					Display_Player3_X = Player3.GetBishopX();
					Display_Player3_Y = Player3.GetBishopY();
				}

				if (Player4.GetPiece() == Pieces::Knight)
				{
					Display_Player4_X = Player4.GetKnightX();
					Display_Player4_Y = Player4.GetKnightY();
				}
				else if (Player4.GetPiece() == Pieces::Rook)
				{
					Display_Player4_X = Player4.GetRookX();
					Display_Player4_Y = Player4.GetRookY();
				}
				else if (Player4.GetPiece() == Pieces::Bishop)
				{
					Display_Player4_X = Player4.GetBishopX();
					Display_Player4_Y = Player4.GetBishopY();
				}

				break;

			}

			if (Player3.GetPiece() == Pieces::Knight)
			{
				Player3.Move_Knight();
				if (Player3.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player3.GetPlayerName();
					Rows = Player3.GetRows();
					Columns = Player3.GetColumns();
					Display_Player3_X = Player3.GetKnightX();
					Display_Player3_Y = Player3.GetKnightY();
				}
			}

			else if (Player3.GetPiece() == Pieces::Rook)
			{
				Player3.Move_Rook();
				if (Player3.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player3.GetPlayerName();
					Rows = Player3.GetRows();
					Columns = Player3.GetColumns();
					Display_Player3_X = Player3.GetRookX();
					Display_Player3_Y = Player3.GetRookY();

				}
			}

			else if (Player3.GetPiece() == Pieces::Bishop)
			{
				Player3.Move_Bishop();
				if (Player3.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player3.GetPlayerName();
					Rows = Player3.GetRows();
					Columns = Player3.GetColumns();
					Display_Player3_X = Player3.GetBishopX();
					Display_Player3_Y = Player3.GetBishopY();
				}
			}

			if (Player3.CheckingPosition(Pieces::Knight) || Player3.CheckingPosition(Pieces::Rook) || Player3.CheckingPosition(Pieces::Bishop))
			{
				if (Player1.GetPiece() == Pieces::Knight)
				{
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
				else if (Player1.GetPiece() == Pieces::Rook)
				{
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();
				}
				else if (Player1.GetPiece() == Pieces::Bishop)
				{
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}

				if (Player2.GetPiece() == Pieces::Knight)
				{
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
				else if (Player2.GetPiece() == Pieces::Rook)
				{
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
				else if (Player2.GetPiece() == Pieces::Bishop)
				{
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();
				}

				if (Player4.GetPiece() == Pieces::Knight)
				{
					Display_Player4_X = Player4.GetKnightX();
					Display_Player4_Y = Player4.GetKnightY();
				}
				else if (Player4.GetPiece() == Pieces::Rook)
				{
					Display_Player4_X = Player4.GetRookX();
					Display_Player4_Y = Player4.GetRookY();
				}
				else if (Player4.GetPiece() == Pieces::Bishop)
				{
					Display_Player4_X = Player4.GetBishopX();
					Display_Player4_Y = Player4.GetBishopY();
				}

				break;
			}

			if (Player4.GetPiece() == Pieces::Knight)
			{
				Player4.Move_Knight();
				if (Player4.CheckingPosition(Pieces::Knight))
				{
					Display_PlayerName = Player4.GetPlayerName();
					Rows = Player4.GetRows();
					Columns = Player4.GetColumns();
					Display_Player4_X = Player4.GetKnightX();
					Display_Player4_Y = Player4.GetKnightY();
				}
			}

			else if (Player4.GetPiece() == Pieces::Rook)
			{
				Player4.Move_Rook();
				if (Player4.CheckingPosition(Pieces::Rook))
				{
					Display_PlayerName = Player4.GetPlayerName();
					Rows = Player4.GetRows();
					Columns = Player4.GetColumns();
					Display_Player4_X = Player4.GetRookX();
					Display_Player4_Y = Player4.GetRookY();
				}
			}

			else if (Player4.GetPiece() == Pieces::Bishop)
			{
				Player4.Move_Bishop();
				if (Player4.CheckingPosition(Pieces::Bishop))
				{
					Display_PlayerName = Player4.GetPlayerName();
					Rows = Player4.GetRows();
					Columns = Player4.GetColumns();
					Display_Player4_X = Player4.GetBishopX();
					Display_Player4_Y = Player4.GetBishopY();
				}
			}

			if (Player4.CheckingPosition(Pieces::Knight) || Player4.CheckingPosition(Pieces::Rook) || Player4.CheckingPosition(Pieces::Bishop))
			{
				if (Player1.GetPiece() == Pieces::Knight)
				{
					Display_Player1_X = Player1.GetKnightX();
					Display_Player1_Y = Player1.GetKnightY();
				}
				else if (Player1.GetPiece() == Pieces::Rook)
				{
					Display_Player1_X = Player1.GetRookX();
					Display_Player1_Y = Player1.GetRookY();
				}
				else if (Player1.GetPiece() == Pieces::Bishop)
				{
					Display_Player1_X = Player1.GetBishopX();
					Display_Player1_Y = Player1.GetBishopY();
				}

				if (Player2.GetPiece() == Pieces::Knight)
				{
					Display_Player2_X = Player2.GetKnightX();
					Display_Player2_Y = Player2.GetKnightY();
				}
				else if (Player2.GetPiece() == Pieces::Rook)
				{
					Display_Player2_X = Player2.GetRookX();
					Display_Player2_Y = Player2.GetRookY();
				}
				else if (Player2.GetPiece() == Pieces::Bishop)
				{
					Display_Player2_X = Player2.GetBishopX();
					Display_Player2_Y = Player2.GetBishopY();
				}

				if (Player3.GetPiece() == Pieces::Knight)
				{
					Display_Player3_X = Player3.GetKnightX();
					Display_Player3_Y = Player3.GetKnightY();
				}
				else if (Player3.GetPiece() == Pieces::Rook)
				{
					Display_Player3_X = Player3.GetRookX();
					Display_Player3_Y = Player3.GetRookY();
				}
				else if (Player3.GetPiece() == Pieces::Bishop)
				{
					Display_Player3_X = Player3.GetBishopX();
					Display_Player3_Y = Player3.GetBishopY();
				}
				break;
			}
		}
	}
	
	glutInit(&argc, argv);
	glutInitWindowSize(700, 150);
	glutInitWindowPosition(600, 600);
	GLint windowsID1 = glutCreateWindow("MassageBox");
	glutDisplayFunc(MassageBox);
	myInit();
	glutKeyboardFunc(processInput);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutInitWindowSize(240, 240);
	glutInitWindowPosition(1200, 300);
	GLint windowsID2 = glutCreateWindow("FindingGold");
	glutDisplayFunc(DisplayChessBoard);
	myInit();
	glutKeyboardFunc(processInput);
	glutMainLoop();

	return 0;
}