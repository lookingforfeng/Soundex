#include "Soundex.h"

string Soundex::encode(const string& word) const
{
	return EndWithZero(word);
}

string Soundex::EndWithZero(const string& word) const
{
	return word+"000";
}
