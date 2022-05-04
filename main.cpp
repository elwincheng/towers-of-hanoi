/*
This program is a command-line version of the game Towers of Hanoi.
By: Elwin Cheng
May 4, 2022
*/
#include<string>
#include<math.h>
#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

string toLowerCase(string word)
{
	for (int i = 0; i < word.size(); i++)
	{
		word[i] = tolower(word[i]);
	}
	return word;
}

int main()
{
	//vector<string> colors = {"Blue", "Purple", "Green", "Red"};
	vector<string> colors = {"-   ", "---  ", "----- ", "-------"};
	vector<vector<int>> towers = {{3, 2, 1, 0}, {}, {}};
	while(true)
	{
		// Display the current game state
		for (int i = 3; i >= 0; i--)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << setw(10);
				if (i < towers[j].size())
					cout << colors[towers[j][i]];
				else
					cout << "";
			}
			cout << '\n';
		}
		for (int i = 0; i < 3; i++)
		{
			string letter(1, 'A' + i);
			cout << setw(10) << "(" + letter +  ")  ";
		}

		// Game win condition
		if (towers[2].size() == 4)
		{
			cout << "\n/****** GAME SOLVED ******/";
			break;
		}

		// Ask user for input
		// e.g. move a to c<ENTER>
		cout << "\n\n";
		string command;
		cout << "Enter a command: ";
		cin >> command;

		string color;
		char start, end;
		string to;
		cin >> start >> to >> end;

		// Clear terminal with linebreaks
		for (int i = 0; i < 100; i++)
			cout << '\n';

		if (towers[tolower(start) - 'a'].size() == 0 || start == end)
		{
			cout << "/****** INVALID MOVE *******/\n";
			continue;
		}

		int diskValue = towers[tolower(start) - 'a'].back();

		if (towers[tolower(end) - 'a'].size() && diskValue > towers[tolower(end) -'a'].back())
		{
			cout << "/****** INVALID MOVE *******/\n";
			continue;
		}
		
		// Move disk
		towers[tolower(end) -'a'].push_back(diskValue);
		towers[tolower(start) - 'a'].pop_back();
		cout << "/****** SUCCESSFULLY MOVED ******/\n";



	}
}