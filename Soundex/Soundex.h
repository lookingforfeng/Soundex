#pragma once
#ifndef soundex_h
#define soundex_h

#include <string>
#include <map>
using namespace std;

class Soundex
{
public:
	string encode(const string& word) const;
	string ReplaceNum(const char&) const;

private:
	string EndWithZero(const string& word) const;
	string Head(const string& word) const;
	string ReplaceNums(const string& word) const;
	string Tail(const string & )const;
	bool isComplete(const string& encoding) const;
	string LastChar(const string& )const;
	string upperFront(const string& word) const;
	char lower(const char& _char) const;
	void encodeHead(string& encoding, const string& word) const;
	void encodeTail(string& encoding, const string& word) const;
	void encodeLetter(string& encoding, char cur_letter, char last_letter)const;
	bool isVowel(char letter) const;
};

#endif

