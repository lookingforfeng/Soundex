#include "gtest/gtest.h"
#include "Soundex.h"

//#define test

#ifndef test
int main()
{
	Soundex _soundex;
	cout << "this is test use for Soundex,the case is from wikipedia\n\n";

	cout << _soundex.encode("Knuth") << endl;
	cout << _soundex.encode("Kant") << endl;
	cout << _soundex.encode("Jarovski") << endl;
	cout << _soundex.encode("Resnik") << endl;
	cout << _soundex.encode("Reznick") << endl;
	cout << _soundex.encode("Euler") << endl;
	cout << _soundex.encode("Peterson") << endl;
	cout << _soundex.encode("Jefferson") << endl;

	return 0;
}
#endif // !test


#ifdef test

using namespace testing;

class SoundexEncoding :public Test
{
public:
	Soundex _soundex;
private:

};

TEST_F(SoundexEncoding, changeFisrtLetter)
{
	ASSERT_EQ(_soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, replaceLetterWihtNumber)
{
	ASSERT_EQ(_soundex.encode("Bk"), "B200");
}

TEST_F(SoundexEncoding, replaceNosenceWithZero)
{
	ASSERT_EQ(_soundex.encode("B#"), "B000");
}

TEST_F(SoundexEncoding, replaceMoreNum)
{
	ASSERT_EQ(_soundex.encode("Lxdf"), "L231");
}

TEST_F(SoundexEncoding, longWord)
{
	ASSERT_EQ(_soundex.encode("Lxdfasdfasdf"), "L231");
}

TEST_F(SoundexEncoding, yuanyin)
{
	ASSERT_EQ(_soundex.encode("Baeiouhycdl"), "B234");
}

TEST_F(SoundexEncoding, dealSameNumber)
{
	ASSERT_EQ(_soundex.ReplaceNum('b'), _soundex.ReplaceNum('f'));
	ASSERT_EQ(_soundex.ReplaceNum('c'), _soundex.ReplaceNum('g'));
	ASSERT_EQ(_soundex.ReplaceNum('d'), _soundex.ReplaceNum('t'));
	ASSERT_EQ(_soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, uperClassLetter)
{
	ASSERT_EQ(_soundex.encode("abcd").substr(0, 1), "A");
}

TEST_F(SoundexEncoding, more_uperClassLetter)
{
	ASSERT_EQ(_soundex.encode("BaAeEiIoOuUhHyYcdl"), "B234");
}

TEST_F(SoundexEncoding, ignoreCase)
{
	ASSERT_EQ(_soundex.encode("BCDL"), _soundex.encode("Bcdl"));
}

TEST_F(SoundexEncoding, combieDuplicateCodes)
{
	ASSERT_EQ(_soundex.encode("Bbcd"), "B230");
}

TEST_F(SoundexEncoding, slitBySome_yuanyin)
{
	ASSERT_EQ(_soundex.encode("Jbob"), "J110");
}
#endif // test


