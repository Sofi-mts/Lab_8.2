// Юніт-тест до лабораторної роботи № 8.2 (стандартні функції С++ для string), варіант 8
// Запуск: відкрити цей файл у VS Code і натиснути F5.

#define main lab_main          // беремо функції з лаби, але без її main()
#include "Lab_8.2.cpp"
#undef main

#include <string>

int passed = 0, failed = 0;

// перевірка: чи збігається отримане значення з очікуваним
#define CHECK_EQ(expected, actual)                                   \
    if ((expected) == (actual)) passed++;                            \
    else { failed++; cout << "FAIL line " << __LINE__ << endl; }

void TestCountWordsStartingWithB() {
    CHECK_EQ(3, CountWordsStartingWithB("  big   blue bird  sky "));
    CHECK_EQ(0, CountWordsStartingWithB("apple cab"));
}

int main() {
    TestCountWordsStartingWithB();

    cout << "Checks passed: " << passed << ", failed: " << failed << endl;
    cout << (failed == 0 ? "ALL TESTS PASSED" : "SOME TESTS FAILED") << endl;
    system("pause");
    return failed == 0 ? 0 : 1;
}
