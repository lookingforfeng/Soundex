#include "Soundex.h"

static const size_t MaxCodeLength{ 4 };
static const string NotANum{ "*" };

string Soundex::encode(const string& word) const
{
	auto _substr = Head(word) + Tail(ReplaceNums(word));
	return EndWithZero(_substr);
}

string Soundex::EndWithZero(const string& word) const
{
	int zero_needed = MaxCodeLength - word.length();
	return word + string(zero_needed, '0');
}

string Soundex::Head(const string& word) const
{
	return upperFront(word.substr(0, 1));
}

string Soundex::ReplaceNums(const string& word) const
{
	if (word.empty())
	{
		return "";
	}
	string encoding;
	encodeHead(encoding, word);
	encodeTail(encoding, word);
	return encoding;
}

string Soundex::ReplaceNum(const char& letter) const
{
	const std::map<char, string> encoding
	{
		{'b',"1"},{'f',"1"},{'p',"1"},{'v',"1"},
		{'c',"2"},{'g',"2"},{'j',"2"},{'k',"2"},{'q',"2"},{'s',"2"},{'x',"2"},{'z',"2"},
		{'d',"3"},{'t',"3"},
		{'l',"4"},
		{'m',"5"},{'n',"5"},
		{'r',"6"},
	};
	auto it = encoding.find(lower(letter));
	return it == encoding.end() ? NotANum : it->second;
}

string Soundex::Tail(const string& word) const
{
	return word.substr(1);
}

bool Soundex::isComplete(const string& encoding) const
{
	return encoding.length() >= MaxCodeLength;
}

string Soundex::LastChar(const string& word) const
{
	if (word.empty())
	{
		return NotANum;
	}
	return string(1, word.back());
}

string Soundex::upperFront(const string& word) const
{
	return string(1, toupper(static_cast<unsigned char>(word.front())));
}

char Soundex::lower(const char& _char) const
{
	return std::tolower(static_cast<unsigned char> (_char));
}

void Soundex::encodeHead(string& encoding, const string& word) const
{
	encoding += ReplaceNum(word.front());
}

void Soundex::encodeTail(string& encoding, const string& word) const
{
	for (auto i = 1u; i < word.length(); i++)
	{
		if (!isComplete(encoding))
		{
			encodeLetter(encoding, word[i], word[i - 1]);
		}
	}
}

void Soundex::encodeLetter(string& encoding, char cur_letter, char last_letter) const
{
	auto digit = ReplaceNum(cur_letter);
	if (digit!=NotANum && (digit!= LastChar(encoding)|| isVowel(last_letter)))
	{
		encoding += digit;
	}
}

bool Soundex::isVowel(char letter) const
{
	return string("aeiouy").find(lower(letter))!=string::npos;
}
