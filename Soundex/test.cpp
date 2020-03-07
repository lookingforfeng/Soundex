#include "gtest/gtest.h"
using namespace std;

class Soundex
{
public:
	Soundex();
	~Soundex();
	string encode(const string& word);

private:

};

Soundex::Soundex()
{
}

Soundex::~Soundex()
{
}

string Soundex::encode(const string& word)
{
	return "A";
}

TEST(SoundexEncoding, changeFisrtLetter) {
	Soundex my_soundex;
	auto encoded = my_soundex.encode("A");
	EXPECT_EQ(encoded, "A");
}

