#pragma once
#include <string>
using namespace std;
class Soundex
{
public:
	string encode(const string& word) const;
private:
	string EndWithZero(const string& word) const;
};

