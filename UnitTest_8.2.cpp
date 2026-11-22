// Юніт-тести до лабораторної роботи № 8.2 (стандартні функції С++ для string), варіант 8
// Знайти кількість слів, які починаються з букви "b".
// Запуск: відкрити цей файл у VS Code і натиснути F5 (або Ctrl+F5).

#define main lab_main          // беремо функції з лаби, але без її main()
#include "Lab_8.2.cpp"
#undef main

#include <string>

static int passed = 0, failed = 0;

#define CHECK_EQ(expected, actual)                                          \
    do {                                                                    \
        auto e_ = (expected);                                               \
        auto a_ = (actual);                                                 \
        if (e_ == a_) {                                                     \
            ++passed;                                                       \
        } else {                                                            \
            ++failed;                                                       \
            cout << "  FAIL line " << __LINE__ << ": " #actual              \
                 << " = " << a_ << ", expected " << e_ << endl;             \
        }                                                                   \
    } while (0)

#define CHECK(cond) CHECK_EQ(true, (bool)(cond))

static void RunTest(const char* name, void (*test)()) {
    int failedBefore = failed;
    test();
    cout << (failed == failedBefore ? "[ OK ] " : "[FAIL] ") << name << endl;
}

// ---------- CountWordsStartingWithB ----------

void Test_Simple() {
    CHECK_EQ(2, CountWordsStartingWithB("big blue sky"));
}

void Test_ManySpaces() {
    CHECK_EQ(3, CountWordsStartingWithB("  big   blue bird  sky "));
}

void Test_NoB() {
    CHECK_EQ(0, CountWordsStartingWithB("apple Banana cherry"));
}

void Test_BInside() {
    CHECK_EQ(1, CountWordsStartingWithB("abc cab bob"));
}

void Test_OneWord() {
    CHECK_EQ(1, CountWordsStartingWithB("b"));
}

void Test_OnlySpaces() {
    CHECK_EQ(0, CountWordsStartingWithB("     "));
}

void Test_Empty() {
    CHECK_EQ(0, CountWordsStartingWithB(""));
}


int main() {
    cout << "Lab 8.2 unit tests" << endl;
    RunTest("simple sentence", Test_Simple);
    RunTest("several spaces between and around words", Test_ManySpaces);
    RunTest("no words starting with 'b' (upper-case B does not count)", Test_NoB);
    RunTest("'b' inside a word does not count", Test_BInside);
    RunTest("single one-letter word", Test_OneWord);
    RunTest("only spaces", Test_OnlySpaces);
    RunTest("empty string", Test_Empty);
    cout << endl << "Checks passed: " << passed << ", failed: " << failed << endl;
    cout << (failed == 0 ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << endl;
    system("pause");    // щоб вікно не закривалося одразу
    return failed == 0 ? 0 : 1;
}
