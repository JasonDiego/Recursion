// Jason Aguilera
#include <iostream>
#include <memory>
#include <math.h>
#include <windows.h> // used for console handle

using namespace std;

/*
* The printTree() function will print a full binary tree of a minimum depth of three levels.
* The console handle is required for printing the tree in order
*
* The printH() function is given (x,y) coordinates which tell it where to print a three-level tree,
* the structure of this sub-tree resembles the letter 'H'
*/

// print 3-level tree using (x,y) coordinates
void printH(int x, int y, HANDLE console_h) {

	char l1[] = { 'o', ' ', ' ', ' ', 'o', '\0' };
	char l2[] = { '|', ' ', ' ', ' ', '|', '\0' };
	char l3[] = { 'o', '-', 'o', '-', 'o', '\0' };
	COORD c; // coordinate data type for setting cursor position
	c.X = x; c.Y = y;

	for (int i = 0; i < 5; ++i) { // loop for printing 3-level tree
		if (!SetConsoleCursorPosition(console_h, c)) return; // re-adjust console cursor
		if (i == 0 || i == 4) cout << l1;
		else if (i == 1 || i == 3) cout << l2;
		else if (i == 2) cout << l3;
		c.Y++;
	}
}

void printTree(int n, int x, int y, HANDLE console_h) {

	if (n < 3) return; // base case
	else if (n % 2 != 0 && n != 3) { // odd
		printTree(n-1, x + (6 * ( pow(2, (n - 5) / 2) )), y, console_h); // x argument depends on current level (n)
		printTree(n - 1, x, y, console_h); // recursive call for current (x,y) coordinates
	}
	else { // even
		printTree(n-1, x, y + (6 * ( pow(2, (n - 4) / 2) )), console_h); // y argument depends on current level (n)
		printTree(n - 1, x, y, console_h); // recursive call for current (x,y) coordinates
	}
	printH(x, y, console_h);
}

int main() {

	// declare and initialize handle to current console
	HANDLE console_h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c; c.X = 0; c.Y = 0;
	int n = 0;

	cout << "How many levels are there in tree? " << endl;
	cin >> n;
	if (!SetConsoleCursorPosition(console_h, c)) return 0;
	cout << "                 ";
	printTree(n, 0, 0, console_h); // (x,y) starting coordinates: (-7,0)

	// close handle at end of program
	CloseHandle(console_h);
	getchar();
	getchar();
	return 0;
}
