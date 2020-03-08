#include "gtest/gtest.h"
#include "Soundex.h"

#define test

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

TEST_F(SoundexEncoding, set_only_the_first_character)
{
	ASSERT_EQ(_soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, replace_letters_other_than_the_first_character_with_numbers)
{
	ASSERT_EQ(_soundex.encode("Bk"), "B200");
}

TEST_F(SoundexEncoding, mask_unexpected_characters)
{
	ASSERT_EQ(_soundex.encode("B#"), "B000");
}

TEST_F(SoundexEncoding, replace_multiple_characters)
{
	ASSERT_EQ(_soundex.encode("Lxdf"), "L231");
}

TEST_F(SoundexEncoding, when_the_number_of_characters_is_more_than_4)
{
	ASSERT_EQ(_soundex.encode("Lxdfasdfasdf"), "L231");
}

TEST_F(SoundexEncoding, shield_middle_vowel)
{
	ASSERT_EQ(_soundex.encode("Baeiouhycdl"), "B234");
}

TEST_F(SoundexEncoding, the_same_encoding_is_not_repeated)
{
	ASSERT_EQ(_soundex.ReplaceNum('b'), _soundex.ReplaceNum('f'));
	ASSERT_EQ(_soundex.ReplaceNum('c'), _soundex.ReplaceNum('g'));
	ASSERT_EQ(_soundex.ReplaceNum('d'), _soundex.ReplaceNum('t'));
	ASSERT_EQ(_soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, uppercase_the_first_letter)
{
	ASSERT_EQ(_soundex.encode("abcd").substr(0, 1), "A");
}

TEST_F(SoundexEncoding, allow_uppercase_letters_in_the_middle)
{
	ASSERT_EQ(_soundex.encode("BaAeEiIoOuUhHyYcdl"), "B234");
}

TEST_F(SoundexEncoding, same_case_encoding)
{
	ASSERT_EQ(_soundex.encode("BCDL"), _soundex.encode("Bcdl"));
}

TEST_F(SoundexEncoding, same_code_merge)
{
	ASSERT_EQ(_soundex.encode("Bbcd"), "B230");
}

TEST_F(SoundexEncoding, vowel_isolation_does_not_count)
{
	ASSERT_EQ(_soundex.encode("Jbob"), "J110");
}
#endif // test


