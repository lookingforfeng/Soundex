#include "Soundex.h"

static const size_t MaxCodeLength{ 4 };

string Soundex::encode(const string& word) const
{
	auto _substr = Head(word) + ReplaceNums(Tail(word));
	return EndWithZero(_substr);
}

string Soundex::EndWithZero(const string& word) const
{
	int zero_needed = MaxCodeLength - word.length();
	return word + string(zero_needed, '0');
}

string Soundex::Head(const string& word) const
{
	return word.substr(0, 1);
}

string Soundex::ReplaceNums(const string& word) const
{
	if (word.empty())
	{
		return "";
	}
	string encoding;
	for (auto letter : word)
	{
		encoding += ReplaceNum(letter);
	}
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
	auto it=encoding.find(letter);
	return it == encoding.end() ? "" : it->second;
}

string Soundex::Tail(const string& word) const
{
	return word.substr(1);
}
