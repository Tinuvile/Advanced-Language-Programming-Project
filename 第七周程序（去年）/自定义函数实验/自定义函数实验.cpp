#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

void print_char(char start_ch, char end_ch, int choice)
{
	int s_ch = start_ch;
	int e_ch = end_ch;
	if (s_ch <= e_ch && choice == 1) {
		cout << char(s_ch);
		print_char(char(s_ch + 1), end_ch, choice);
	}
	else {
		if (s_ch >= 67) {
			cout << char(s_ch - 2);
			print_char(char(s_ch - 1), end_ch, choice - 1);
		}
		else {
			return;
		}
	}
}

void print_line(char start_ch, char end_ch, int line) {
	int Max_line = int(end_ch) - int(start_ch) + 1;
	if (line <= Max_line) {
		if ((Max_line - line) != 0) {
			cout << setw(Max_line - line) << ' ';
			print_char(start_ch, char(65 + line - 1), 1);
			cout << setw(Max_line - line) << ' ' << endl;
		}
		if (Max_line == line) {
			print_char(start_ch, char(65 + line - 1), 1);
			cout << endl;
		}
		else
			return;
	}
	else
		return;
}

void print_tower(char end_ch, int order, int line) {
	int Max_line = int(end_ch) - 65 + 1;
	if (order == 1) {
		if (line <= Max_line) {
			print_line('A', end_ch, line);
			print_tower(end_ch, order, line + 1);
		}
		else
			return;
	}
	if (order == 0) {
		if (line >= 1 && line <= Max_line) {
			print_line('A', end_ch, line);
			print_tower(end_ch, order, line - 1);
		}
		else
			return;
	}
	else
		return;
}

int main() {
	return 0;
}