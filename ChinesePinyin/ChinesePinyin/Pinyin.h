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

private:

};

