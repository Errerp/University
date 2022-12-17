#include "func.h"

char* initString(const char* text)
{
    int stringSize = stringLength(text);
    char* string = malloc((stringSize + 1) * sizeof(char));

    for (int i = 0; i < stringSize; i++)
        string[i] = text[i];

    string[stringSize] = '\0';

    return string;
}

int stringLength(const char* text)
{
    int length = 0;

    while (text[length] != '\0')
        length++;

    return length;
}

int is_letter(char string) {
    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z'))
        return 1;
    return 0;
}

int len(char* string) {
    int i = 0;
    for (; string[i] != '\0'; i++);
    return i;
}

int count_chet_words(const char* string) {
    int words = 0, start = 0;
    for (int i = len(string); i != 0; i--) {
        if (is_letter(string[i - 1]) && !is_letter(string[i])) {
            start = i;
            continue;
        }
        if (!is_letter(string[i - 1]) && is_letter(string[i])) {
            words += ((start - i) % 2 == 0);
            start = 0;
        }
    }
    if (is_letter(string[0]) && start != 0)
        words += (start % 2 == 0);
    return words;
}

void swap(char** first, char** second)
{
    char* temp = *first;

    *first = *second;
    *second = temp;
}

int partition(char** strings, int left, int right, int(*compareFunc)(char*))
{
    int pivot = compareFunc(strings[right]);
    int pivotIndex = left;

    for (int i = left; i < right; i++)
    {
        if (compareFunc(strings[i]) <= pivot)
        {
            swap(&strings[i], &strings[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(&strings[pivotIndex], &strings[right]);

    return pivotIndex;
}

void quickSort(char** strings, int left, int right, int(*compareFunc)(char*))
{
    if (left >= right)
        return;

    int p = partition(strings, left, right, compareFunc);

    quickSort(strings, left, p - 1, compareFunc);
    quickSort(strings, p + 1, right, compareFunc);
}
void type(int argc, char** argv) {
    for (int i = 1; i < argc; i++)
        printf("������: %s � %d ������(���)\n", argv[i], count_chet_words(argv[i]));
}