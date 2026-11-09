#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, ".65001");
    srand(12345);
    const int N = 12;
    int* arr = new int[N];
    for(int i = 0; i < N; ++i)
    {
        arr[i] = rand()%100;
    }
    int size = N;
    cout << "Исходный массив (" << size << " элементов):\n";
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    const int TO_REMOVE = 5;
    int removeCount;
    if(size >= TO_REMOVE)
    {
        removeCount = TO_REMOVE;
    }
    else
    {
        removeCount = size;
    }
    for(int i = 0; i < size - removeCount; ++i)
    {
        arr[i] = arr[i + removeCount];
    }
    size -= removeCount;
    cout << "После удаления " << removeCount << " первых элементов:\n";
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    const int TO_ADD = 3;
    int* newArr = new int[size + TO_ADD];
    for(int i = 0; i < size; ++i)
    {
        newArr[i] = arr[i];
    }
    for(int i = 0; i < TO_ADD; ++i)
    {
        newArr[size + i] = rand()%100;
    }
    delete[] arr;
    arr = newArr;
    size += TO_ADD;
    cout << "Итоговый массив (" << size << " элементов):\n";
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    delete[] arr;
    return 0;
}