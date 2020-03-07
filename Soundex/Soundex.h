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
private:
	string EndWithZero(const string& word) const;
	string Head(const string& word) const;
	string ReplaceNums(const string& word) const;
	string ReplaceNum(const char&) const;
	string Tail(const string & )const;
	bool isComplete(const string& encoding) const;
};

#endif

