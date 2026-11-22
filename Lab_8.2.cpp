// Lab_8.2.cpp
// Лабораторна робота № 8.2. Опрацювання літерних рядків.
// Варіант 8. Використання стандартних функцій мови С++ для рядків string.
// Виконала: Кучер Софія.
//
// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// Групи символів, відокремлені пробілами (одним або кількома) і які не містять
// пробілів, будемо називати словами.
// Знайти кількість слів, які починаються з букви "b".

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// повертає кількість слів рядка s, які починаються з букви "b"
int CountWordsStartingWithB(const string& s)
{
    int    k = 0;
    size_t start = 0,             // start  = позиція першого символу слова
           finish;                // finish = позиція пробілу після слова

    while ((start = s.find_first_not_of(' ', start)) != string::npos)
    {
        if (s[start] == 'b')
            k++;

        finish = s.find(' ', start);
        if (finish == string::npos)   // останнє слово рядка
            break;

        start = finish + 1;
    }

    return k;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "Number of words starting with 'b': " << CountWordsStartingWithB(str) << endl;

    system("pause");    // щоб вікно не закривалося одразу
    return 0;
}
