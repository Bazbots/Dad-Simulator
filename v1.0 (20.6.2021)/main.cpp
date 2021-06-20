#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Dad {
public:
	string name;
	string job;
	int children = 1;
	int money = 1000;
	int beers = 3;
private:
	string getName() {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getJob() {
		return this->name;
	}
	void setJob(string job) {
		this->job = job;
	}
	int getChildren() {
		return this->children;
	}
	void newChild() {
		children++;
	}
	int getBalance() {
		return this->money;
	}
	void buy(string item, int price) {
		money = money - price;
	}
	int getBeers() {
		return this->beers;
	}
	void buyBeer() {
		cout << "You bought a beer!" << endl;
		beers++;
	}
	void drinkBeer() {
		beers--;
	}
};

void clear() {
	system("CLS");
}

void pause() {
	system("PAUSE");
	system("CLS");
}

void load(int amount) {
	int count = 0;
	while (count < amount) {
		system("CLS");
		cout << "| Loading...";
		Sleep(500);
		system("CLS");
		cout << "/ Loading...";
		Sleep(500);
		system("CLS");
		cout << "- Loading...";
		Sleep(500);
		system("CLS");
		cout << "\\ Loading...";
		Sleep(500);
		system("CLS");
		cout << "| Loading...";
		Sleep(500);
		system("CLS");
		cout << "/ Loading...";
		Sleep(500);
		system("CLS");
		cout << "- Loading...";
		Sleep(500);
		system("CLS");
		cout << "\\ Loading...";
		Sleep(500);
		system("CLS");
		count++;
	};
	system("CLS");
};

void maximizeWindow() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

int main() {
	maximizeWindow();
	SetConsoleTitle(TEXT("Dad Simulator 1.0 (20.6.2021)"));
	//SetConsoleFontSize(72);
	// Init
	fstream achievements;
	int winners = rand() % 11;
	int gold_beer = rand() % 101;
	bool win = false;
	string action = "";
	string rt = "";
	string dadname = "";
	MessageBox(NULL, TEXT("This game is still in version 1.0 (20.6.2021)\nMore updates still to come!"), TEXT("Dad Simulator"), MB_TOPMOST);
	load(3);
	cout << "Baz presents..." << endl;
	Sleep(5000);
	system("CLS");
	Sleep(2000);
	cout << "Dad Simulator!" << endl;
	Sleep(2000);
	system("PAUSE");
	system("CLS");
	cout << "Choose your name:\n";
	cin >> dadname;
	Sleep(3000);
	Dad setName(string dadname);
	cout << "Name set!" << endl;
	system("CLS");
	cout << "Read tutorial?\ny or n" << endl;
	cin >> rt;
	if (rt == "y") {
		Sleep(4000);
		system("CLS");
		cout << "Tutorial" << endl;
		MessageBox(NULL, TEXT("Welcome!\nThis is the tutorial for the Dad Simulator!"), TEXT("Tutorial"), MB_TOPMOST);
		Sleep(4000);
		MessageBox(NULL, TEXT("On initialisation\nWhen the app starts, you\n- Get 1000 money\n- 1 Child\n"), TEXT("Tutorial"), MB_TOPMOST);
		Sleep(2000);
		MessageBox(NULL, TEXT("Money System\nYou can use money to buy things such as\n- Beer\n- Watch Football At the Pub\n- Read the Newspaper\n- And play football games"), TEXT("Tutorial"), MB_TOPMOST);
		Sleep(2000);
		MessageBox(NULL, TEXT("Shop System\nAs shown before, those are some of the items you can buy!\nTo buy something, write buy <item> or shop to view the shop"), TEXT("Tutorial"), MB_TOPMOST);
	}
	else if (rt == "Y") {
		Sleep(4000);
		system("CLS");
		cout << "Tutorial" << endl;
		MessageBox(NULL, TEXT("Welcome!\nThis is the tutorial for the Dad Simulator!"), TEXT("Tutorial"), MB_TOPMOST);
		Sleep(4000);
		MessageBox(NULL, TEXT("On initialisation\nWhen the app starts, you\n- Get 1000 money\n- 1 Child\n- No job"), TEXT("Tutorial"), MB_TOPMOST);
		Sleep(2000);
		MessageBox(NULL, TEXT("Money System\nYou can use money to buy things such as\n- Beer\n- Watch Football At the Pub\n- Read the Newspaper\n- And bet on football games"), TEXT("Tutorial"), MB_TOPMOST);
		Sleep(2000);
		MessageBox(NULL, TEXT("Shop System\nAs shown before, those are some of the items you can buy!\nTo buy something, write buy <item> or shop to view the shop"), TEXT("Tutorial"), MB_TOPMOST);
	}
	else {
		MessageBox(NULL, TEXT("Skipping Tutorial!"), TEXT("Tutorial"), MB_TOPMOST);
	};
	system("CLS");
	while (true) {
		cout << "What do you want to do?\n- Drink\n- Shop\n- Buy <item>\n- Pub\n- Exit\n" << endl;
		cin >> action;
		pause();
		system("CLS");
		if (action == "drink" || action == "DRINK") {
			cout << "You drink some beer..." << endl;
			int beer = rand() % 101;
			if (beer == gold_beer) {
				MessageBox(NULL, TEXT("Congratulations!\nYou have found the golden beer, meaning that you have won an infinate supply of beer!"), TEXT("You win!"), MB_TOPMOST);
				achievements.open("achievements.txt", ios::app);
				achievements << "Found Golden Beer\n";
				achievements.close();
			}
			else {
				cout << "You did not find the golden beer :(";
			}
			Sleep(5000);
		}
		else if (action == "shop" || action == "SHOP") {
			string item = "";
			cout << "You can buy:\n- 1 Beer";
			pause();
		}
		else if (action == "buy" || action == "BUY") {
			string item = "";
			cout << "What do you want to buy?\nCheck the shop for the prices!\nType cancel to return" << endl;
			cin >> item;
			if (item == "cancel") {
				continue;
			}
			else if (item == "beer") {
				Dad buyBeer();
				cout << "You bought a beer!" << endl;
			}
			else if (item == "newspaper") {
				cout << "You read the news!" << endl;
			}
			else {
				cout << "This item does not exist!" << endl;
			}
			pause();
		}
		else if (win == true) {
			break;
		}
		else if (action == "pub") {
			int bet = 0;
			cout << "You go to the pub and watch the footy" << endl;
			Sleep(2000);
			cout << "What team do you bet for (1 - 11)" << endl;
			cin >> bet;
			Sleep(5000);
			cout << "You placed a bet for team " << bet << " to win and..." << endl;
			if (bet == winners) {
				cout << "You won the bet!";
				achievements.open("achievements.txt", ios::app);
				achievements << "Won bet\n";
				achievements.close();
				break;
			}
			else {
				cout << "Lost the bet :(" << endl;
			}
			pause();
		}
		else if (action == "exit") {
			cout << "Thanks for playing Dad Simulator" << endl;
			pause();
			Sleep(5000);
			abort();
		}
		else if (action == "work") {
			int earned = rand() % 100000;
			cout << "You start working" << endl;
			Sleep(rand() % 11);
			cout << "After working, you recieve " << earned << " money";
			pause();
		}
		else {
			cout << "That item does not exist!" << endl;
		}
		system("CLS");
		}
	cout << "\n" << dadname << " has beaten Dad Simulator!" << endl;
	Sleep(2000);
	cout << "Thanks for playing ~ Baz" << endl;
	pause();
}
