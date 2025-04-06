#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;
	return randNum;

}
enum enumchoise { Stoen = 1, Paper = 2, Scissor = 3 };
enum enumwinner { plyer = 1, compouter = 2, drow = 3 };
struct stgamerslt
{
	short gameround = 0;
	short play1wintimes = 0;
	short computerwintimes = 0;
	short drawtimes = 0;
	enumwinner gamewinner;
	string winnername;

};
struct stroundinfo
{
	short roundnumber = 0;
	enumchoise playerchoise;
	enumchoise compiterchoise;
	enumwinner winner;
	string winnername;

};
enumchoise readplaychois()
{
	short choise = 1;
	do
	{
		cout << "\nyour choise : [1]:stone , [2]:paper , [3]:scissors ? ";
		cin >> choise;


	} while (choise < 1 || choise > 3);

	return enumchoise(choise);
}
enumchoise getcomputerchoie()
{

	return enumchoise(RandomNumber(1, 3));

}
string choise(enumchoise chois)
{
	string arrchoisess[3] = { "stone","paper","scissors" };
	return arrchoisess[chois - 1];

}
void setwinnerscreencolor(enumwinner winner)
{
	switch (winner)
	{
	case enumwinner::plyer:
		system("color 2f");
		break;
	case enumwinner::compouter:
		system("color 4f");
		cout << "\a";
		break;
	default:
		system("color 6f");
		break;
	}

}
/* or cilor function*********
void colorfunction(stroundinfo roundinfo)
{

	if (roundinfo.playerchoise == roundinfo.winner)
	{
		system("color 2f");
		cout << "\a";
	}
	if (roundinfo.compiterchoise == roundinfo.winner)
	{
		system("color 4f");
		cout << "\a";
	}
	if (roundinfo.compiterchoise == roundinfo.playerchoise)
	{
		system("color 6f");
	}
}
*/
void preintroundreslt(stroundinfo roundinfo)
{

	cout << "\n__roud [" << roundinfo.roundnumber << "]--------------\n\n";
	cout << "player choise " << choise(roundinfo.playerchoise) << endl;
	cout << "player choise " << choise(roundinfo.compiterchoise) << endl;
	cout << "round winner : [ " << roundinfo.winnername << "]" << endl;
	cout << "------------------------------------------\n " << endl;

	setwinnerscreencolor(roundinfo.winner);

}
string  winnername(enumwinner winner)
{
	string winnernamearray[3] = { "player" ," computer " , "no wwiner" };

	return winnernamearray[winner - 1];


}
enumwinner whowonthegame(short playerwintiem, short computer)
{
	if (playerwintiem > computer)
		return enumwinner::plyer;
	else if (computer < playerwintiem)
		return enumwinner::compouter;
	else
		return enumwinner::drow;
}
enumwinner whowontheround(stroundinfo roundinfo)
{
	if (roundinfo.playerchoise == roundinfo.compiterchoise)
	{
		return enumwinner::drow;
	}

	switch (roundinfo.playerchoise)
	{
	case enumchoise::Stoen:
		if (roundinfo.compiterchoise == enumchoise::Paper)
		{
			return  enumwinner::compouter;
		}
		break;
	case enumchoise::Paper:
		if (roundinfo.compiterchoise == enumchoise::Scissor)
		{
			return  enumwinner::compouter;
		}
		break;

	case enumchoise::Scissor:
		if (roundinfo.compiterchoise == enumchoise::Stoen)
		{
			return  enumwinner::compouter;
		}
		break;
	}

	return enumwinner::plyer;
}
stgamerslt fillgamereslt(int Gameround, short playerwintimes, short compute, short drawtimes)
{
	stgamerslt gameReaslt;

	gameReaslt.gameround = Gameround;
	gameReaslt.play1wintimes = playerwintimes;
	gameReaslt.computerwintimes = compute;
	gameReaslt.drawtimes = drawtimes;
	gameReaslt.gamewinner = whowonthegame(playerwintimes, compute);
	gameReaslt.winnername = winnername(gameReaslt.gamewinner);
	return gameReaslt;
}
stgamerslt palygame(short howMonyrouds)
{
	stroundinfo roundinfo;
	short play1wintimes = 0, computerwintimes = 0, drawtimes = 0;

	for (short gameround = 1; gameround <= howMonyrouds; gameround++)
	{
		cout << "\nround [" << gameround << "] begins:\n";

		roundinfo.roundnumber = gameround;
		roundinfo.playerchoise = readplaychois();
		roundinfo.compiterchoise = getcomputerchoie();
		roundinfo.winner = whowontheround(roundinfo);
		roundinfo.winnername = winnername(roundinfo.winner);


		if (roundinfo.winner == enumwinner::plyer)
			play1wintimes++;
		else if (roundinfo.winner == enumwinner::compouter)
			computerwintimes++;
		else
			drawtimes++;

		preintroundreslt(roundinfo);

	}

	return fillgamereslt(howMonyrouds, play1wintimes, computerwintimes, drawtimes);
}
string tape(short num)
{
	string t = "";
	for (int i = 1;i < num; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;

}
void showgameoverscreen()
{
	cout << tape(2) << "---------------------------------------------------------\n\n";
	cout << tape(2) << "                ++++++Game Over+++++                      \n\n";
	cout << tape(2) << "---------------------------------------------------------\n\n";



}
void showfinalgamereslt(stgamerslt Gamereslt)
{
	cout << tape(2) << "-------------------------[Game reslt]-----------------------\n\n";
	cout << tape(2) << "round                : " << Gamereslt.gameround << endl;
	cout << tape(2) << "player won times     : " << Gamereslt.play1wintimes << endl;
	cout << tape(2) << "computer won times   : " << Gamereslt.computerwintimes << endl;
	cout << tape(2) << "draw times           : " << Gamereslt.drawtimes << endl;
	cout << tape(2) << "final winner         : " << Gamereslt.winnername << endl;
	cout << tape(2) << "round         : " << Gamereslt.gameround << endl;



}
void restscreen()
{

	system("cls");
	system("color 0F");
}
short readhowmonyround()
{
	short gameround = 1;
	do
	{
		cout << "how mony rounds 1 to 10 ? \n";
		cin >> gameround;

	} while (gameround < 1 || gameround > 10);

	return gameround;

}
void startsgame()
{

	char playagain = 'Y';

	do
	{
		restscreen();
		stgamerslt gamereslt = palygame(readhowmonyround());
		showgameoverscreen();
		showfinalgamereslt(gamereslt);
		cout << endl << tape(3) << "do you want play again ? Y/N ";
		cin >> playagain;
	} while (playagain == 'Y' || playagain == 'y');

}
int main()
{

	startsgame();

	return 0;


}