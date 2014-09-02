#include "../../testing/testing.hpp"

#include "../preferred_languages.hpp"

#include "../../std/string.hpp"


UNIT_TEST(LangNormalize_Smoke)
{
  char const * arr1[] = { "en", "en-GB", "zh", "es-SP", "zh-penyn", "en-US", "ru_RU", "es" };
  char const * arr2[] = { "en", "en", "zh", "es", "zh", "en", "ru", "es" };
  STATIC_ASSERT(ARRAY_SIZE(arr1) == ARRAY_SIZE(arr2));

  for (size_t i = 0; i < ARRAY_SIZE(arr1); ++i)
    TEST_EQUAL(arr2[i], languages::Normalize(arr1[i]), ());
}

UNIT_TEST(PrefLanguages_Smoke)
{
  string s = languages::GetPreferred();
  TEST(!s.empty(), ());
  cout << "Preferred langs: " << s << endl;

  s = languages::GetCurrentOrig();
  TEST(!s.empty(), ());
  cout << "Current original lang: " << s << endl;

  s = languages::GetCurrentNorm();
  TEST(!s.empty(), ());
  cout << "Current normalized lang: " << s << endl;
}
