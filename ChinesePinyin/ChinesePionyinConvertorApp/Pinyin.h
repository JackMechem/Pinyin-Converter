#pragma once
#include <fstream>
#include <string>



#ifdef UNICODE
#define CreateEvent  CreateEventW
#else
#define CreateEvent  CreateEventA
#endif // !UNICODE


using namespace std;

class Pinyin
{
public:

	Pinyin();
	~Pinyin();//deconstructor





	static int countVowels(wstring word);

	static wstring getPinyinChar(char vowel, int tone);

	static wstring convertToPinyin(string pinyinOne);

	static int findToneFromString(const std::wstring& wstr);

	static void toClipboard(const std::wstring& s);

private:
	const char vouwls[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O','U' };
	const char tones[4] = { '1', '2', '3', '4' };
	const char medials[4] = { 'i', 'u', 'I', 'U' };
};

