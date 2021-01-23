#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include <list>
#include <wchar.h>

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




	for (auto c : pinyinOne) {
		if (c == ' ') {
			words.push_back(word);
			word = L"";
			//cout << "Added to list\n";
		}
		else {
			word.push_back(c);
			//cout << "Added to string\n";
		}
	}
	words.push_back(word);
	//cout << words.size() << endl;  //Debug List words size




	for (wstring s : words) {//string in the list of words




		if (Pinyin::countVowels(s) == 1) {

			for (char c : s) { //char in each of those words
				switch (c) {
				case 'a': {
					finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));
					/*wstring testOne = Pinyin::getPinyinChar(c, Pinyin::findToneFromStirng(s));
					finalWord += testOne;*/


					break;
				}

				case 'e': {
					finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));

					break;
				}

				case 'i': {
					finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));

					break;
				}
				case 'o': {
					finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));

					break;
				}
				case 'u': {
					finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));

					break;
				}
				default:

					switch (c) {
					case '1':

						break;
					case '2':

						break;
					case '3':

						break;
					case '4':

						break;
					default:
						finalWord.push_back(c);
						break;
					}

					break;
				}



			}
		}
		else if (Pinyin::countVowels(s) > 1) {

			bool medial = false;
			int nonMedial = 0;
			for (char c : s) { //char in each of those words

				if (medial == false) {
					if (nonMedial == 0) {
						switch (c) {
						case 'i':
						case 'u':
							finalWord.push_back(c);
							medial = true;
							break;
						default:
							switch (c) {
							case 'a':
							case 'e':
							case 'i':
							case 'o':
							case 'u':
								finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));
								nonMedial += 1;
								break;
							default:
								switch (c) {
								case '1':
								case '2':
								case '3':
								case '4':
									break;
								default:
									finalWord.push_back(c);
									break;
								}
								break;
							}
							break;
						}
					}
					else if (nonMedial > 0) {
						switch (c) {
						case '1':
						case '2':
						case '3':
						case '4':
							break;
						default:
							finalWord.push_back(c);
							break;
						}
					}
				}else if (medial == true) {
					if (nonMedial == 0) {
						switch (c) {
						case 'a':
						case 'e':
						case 'i':
						case 'o':
						case 'u':


							finalWord.append(Pinyin::getPinyinChar(c, Pinyin::findToneFromString(s)));
							nonMedial += 1;
							break;
						default:

							switch (c) {
							case '1':
							case '2':
							case '3':
							case '4':

								break;
							default:
								finalWord.push_back(c);
								break;
							}

							break;
						}
					}
					else if (nonMedial > 0) {
						switch (c) {
						case '1':
						case '2':
						case '3':
						case '4':

							break;
						default:
							finalWord.push_back(c);
							break;
						}
					}

				}


			
			}
			
		}

		finalWord.push_back(' ');
	}

	/*_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L"%s", finalWord);*/






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
	int vowels = 0;
	for (auto c : word) {
		switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vowels += 1;
			break;
		default:
			break;
		}
	}
	return vowels;
}

int Pinyin::findToneFromString(const std::wstring& wstr) {
	if (wstr.empty()) { return 0; }
	auto w = wstr.back();
	if (w > L'0' && w < L'5') { return w - L'0'; }
	else { return 0; }
}

Pinyin::~Pinyin() {

}