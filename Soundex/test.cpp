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

TEST_F(SoundexEncoding, replaceLetterWihtNumber)
{
	EXPECT_EQ(_soundex.encode("Bk"), "B200");
}

TEST_F(SoundexEncoding, replaceNosenceWithZero)
{
	EXPECT_EQ(_soundex.encode("B#"), "B000");
}

TEST_F(SoundexEncoding, replaceMoreNum)
{
	EXPECT_EQ(_soundex.encode("Lxkf"), "L221");
}

TEST_F(SoundexEncoding, longWord)
{
	EXPECT_EQ(_soundex.encode("Lxkfasdfasdf"), "L221");
}

TEST_F(SoundexEncoding, yuanyin)
{
	EXPECT_EQ(_soundex.encode("Baeiouhycdl"), "B234");
}