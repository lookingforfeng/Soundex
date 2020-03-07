#include "gtest/gtest.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding:public Test
{
public:
	Soundex _soundex;
private:

};

TEST_F(SoundexEncoding, changeFisrtLetter) 
{
	EXPECT_EQ(_soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, theEndLaw)
{
	EXPECT_EQ(_soundex.encode("I"), "I000");
}

