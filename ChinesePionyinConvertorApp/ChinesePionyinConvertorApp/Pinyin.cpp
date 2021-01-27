#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include <list>




#include "Pinyin.h"

#ifdef UNICODE
#define CreateEvent  CreateEventW
#else
#define CreateEvent  CreateEventA
#endif // !UNICODE


using namespace std;


/*Syllables with two or three vowel letters :

			(i)If the first vowel letter is a medial, namely, "i", "u", or "ü", the tone mark is on the vowel letter immediately following the medial.

			Examples :

				jiāo(教; teach)
				lüè(略; strategy)
				jiǔ(九; nine)
				guì(貴; expensive)

				(ii)If the first vowel letter is not a medial, the tone mark is always on the first vowel letter.


				Examples:

			hǎi(海; sea)
			zhǎo(找; look for)
			shǒu(手; hand)
			gěi(給; give)

			(iii)If the tone mark is on "i", the dot is omitted.*/

Pinyin::Pinyin() {


}



wstring Pinyin::convertToPinyin(string pinyinOne) {

	list<wstring> words;
	wstring word;
	wstring finalWord;
	Pinyin pinyin;


	for (auto c : pinyinOne) {
		if (c == ' ') {
			words.push_back(word);
			word = L"";

		}
		else {
			word.push_back(c);

		}
	}
	words.push_back(word);


	for (wstring s : words) {//string in the list of words

		if (Pinyin::countVowels(s) == 1) {

			for (char c : s) { //char in each of those words



				if (find(begin(pinyin.vouwls), end(pinyin.vouwls), c) != end(pinyin.vouwls)) {
					finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));
				}
				else if (find(begin(pinyin.tones), end(pinyin.tones), c) == end(pinyin.tones)) {
					finalWord.push_back(c);
				}

			}
		}
		else if (Pinyin::countVowels(s) > 1) {

			bool medial = false;
			int nonMedial = 0;
			for (char c : s) { //char in each of those words

				if (medial == false) {
					if (nonMedial == 0) {
						if (find(begin(pinyin.medials), end(pinyin.medials), c) != end(pinyin.medials)) {
							finalWord.push_back(c);
							medial = true;
						}
						else if (find(begin(pinyin.vouwls), end(pinyin.vouwls), c) != end(pinyin.vouwls)) {
							finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));
							nonMedial += 1;
						}
						else if (find(begin(pinyin.tones), end(pinyin.tones), c) == end(pinyin.tones)) {
							finalWord.push_back(c);
						}
					}
					else if (nonMedial > 0) {
						if (find(begin(pinyin.tones), end(pinyin.tones), c) == end(pinyin.tones)) {
							finalWord.push_back(c);
						}
					}
				}
				else if (medial == true) {
					if (nonMedial == 0) {
						if (find(begin(pinyin.vouwls), end(pinyin.vouwls), c) != end(pinyin.vouwls)) {
							finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));
							nonMedial += 1;
						}
						else if (find(begin(pinyin.tones), end(pinyin.tones), c) == end(pinyin.tones)) {
							finalWord.push_back(c);
						}

					}
					else if (nonMedial > 0) {
						if (find(begin(pinyin.tones), end(pinyin.tones), c) == end(pinyin.tones)) {
							finalWord.push_back(c);
						}
					}
				}
			}
		}
		finalWord.push_back(' ');
	}

	const wchar_t* result = finalWord.c_str();

	cout << "Final Awnser: ";
#if defined(WIN32)
	auto copyright = const_cast<wchar_t*>(result);
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteConsoleW(handle, copyright, static_cast<DWORD>(wcslen(copyright)), nullptr, nullptr);
#else
	printf(L"%s", finalWord);
#endif

	return finalWord;
}



//People might think this is bad code
//but I don't think so seeing it is not
//really hard coding, I am using every
//possibility therefor it is not bad. (i think) 
wstring Pinyin::getPinyinChar(char vowel, int tone) {
	switch (vowel) {
	case 'A':
		switch (tone) {
		case 1:
			return L"Ā";
			break;
		case 2:
			return L"Á";
			break;
		case 3:
			return L"Ǎ";
			break;
		case 4:
			return L"À";
			break;
		default:
			break;
			return L"";
		}
		break;
	case 'E':
		switch (tone) {
		case 1:
			return L"Ē";
			break;
		case 2:
			return L"É";
			break;
		case 3:
			return L"Ě";
			break;
		case 4:
			return L"È";
			break;
		default:
			break;
		}
		break;
	case 'I':
		switch (tone) {
		case 1:
			return L"Ī";
			break;
		case 2:
			return L"Í";
			break;
		case 3:
			return L"Ǐ";
			break;
		case 4:
			return L"Ì";
			break;
		default:
			break;
		}
		break;
	case 'O':
		switch (tone) {
		case 1:
			return L"Ō";
			break;
		case 2:
			return L"Ó";
			break;
		case 3:
			return L"Ǒ";
			break;
		case 4:
			return L"Ò";
			break;
		default:
			break;
		}
		break;
	case 'U':
		switch (tone) {
		case 1:
			return L"Ū";
			break;
		case 2:
			return L"Ú";
			break;
		case 3:
			return L"Ǔ";
			break;
		case 4:
			return L"Ù";
			break;
		default:
			break;
		}
		break;
	default:

		break;
	}
	switch (vowel) {
	case 'a':
		switch (tone) {
		case 1:
			return L"ā";
			break;
		case 2:
			return L"á";
			break;
		case 3:
			return L"ă";
			break;
		case 4:
			return L"à";
			break;
		default:
			break;
			return L"";
		}
		break;
	case 'e':
		switch (tone) {
		case 1:
			return L"ē";
			break;
		case 2:
			return L"é";
			break;
		case 3:
			return L"ě";
			break;
		case 4:
			return L"è";
			break;
		default:
			break;
		}
		break;
	case 'i':
		switch (tone) {
		case 1:
			return L"ī";
			break;
		case 2:
			return L"í";
			break;
		case 3:
			return L"ǐ";
			break;
		case 4:
			return L"ì";
			break;
		default:
			break;
		}
		break;
	case 'o':
		switch (tone) {
		case 1:
			return L"ō";
			break;
		case 2:
			return L"ó";
			break;
		case 3:
			return L"ǒ";
			break;
		case 4:
			return L"ò";
			break;
		default:
			break;
		}
		break;
	case 'u':
		switch (tone) {
		case 1:
			return L"ū";
			break;
		case 2:
			return L"ú";
			break;
		case 3:
			return L"ǔ";
			break;
		case 4:
			return L"ù";
			break;
		default:
			break;
		}
		break;
	default:
		return L"";
		break;
	}
	return L"";


}

int Pinyin::countVowels(wstring word) {
	int _vowels = 0;
	Pinyin pinyin;
	for (auto c : word) {
		if (find(begin(pinyin.vouwls), end(pinyin.vouwls), c) != end(pinyin.vouwls)) {
			_vowels += 1;
		}


	}
	return _vowels;
}

int Pinyin::findToneFromString(const std::wstring& wstr) {
	if (wstr.empty()) { return 0; }
	auto w = wstr.back();
	if (w > L'0' && w < L'5') { return w - L'0'; }
	else { return 0; }
}

void Pinyin::toClipboard(const std::wstring& s)
{
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}



Pinyin::~Pinyin() {

}