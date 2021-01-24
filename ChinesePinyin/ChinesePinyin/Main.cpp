#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>

#include "Pinyin.h"

#ifdef UNICODE
#define CreateEvent  CreateEventW
#else
#define CreateEvent  CreateEventA
#endif // !UNICODE


using namespace std;

int main() {
	while (true) {
#if defined(WIN32)
		system("cls");
#endif // defined(WIN32)




		string pinyinInput;
		


		cout << "**jackmechem.github.io/Jefrie**\n" <<
			"**PINYIN -- GENORATOR**\n"
			"**Version - Betta 1.1**\n"
			<< endl << endl;


		cout << "Type or paste your pinyin here with spaces (ex: Ni3 Hao3):\n\n";

		


		getline(cin, pinyinInput); //Console Input that ACTUALLY uses spaces. Otherwize it will not have spaces :)

#if defined(WIN32)
		system("cls");
#endif // defined(WIN32)
		cout << "******MADE BY JACK MECHEM******\n" <<
			" *****PINYIN -- GENORATOR*****\n"
			<< endl << endl;
		Pinyin::convertToPinyin(pinyinInput);
		cout << endl;
#if defined(WIN32)
		system("pause");
#endif // defined(WIN32)

	}
	
	//delete pinyinInput;
	return 0;
}