#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 6; 
    int m[n] = { 256, -563, -689, 75, -86, 938 }; 
    int sum = 0; // переменная для хранения суммы отрицательных элементов
    int sum2 = 0; // переменная для хранения суммы положительных элементов
   // int mask = 63;
    cout << "Исходный массив " << endl;
    // выводим значения исходного массива 
    for (int i = 0; i < n; i++)
        cout << "m[" << i << "] = " << m[i] << endl;
    cout << "Размер массива в байтах = "<< sizeof(m) << ' ' << endl;
    //cout << "Количество элементов в массиве = " <<size(m) << '\n';
    // находим сумму отрицательных элементов массива
    for (int i = 0; i < n; i++)
    {
        if (m[i] < 0)
        {
            sum += m[i];
        }
        /*int res = mask ^ m[i] & mask;
        if (res == mask)
        {
            cout << "Седьмой бит содержит 1" << endl;
        }*/
         //cout << (1 & m[i] >> 7) << endl;
    }
        cout << "Cумма отрицательных элементов = " << sum << endl;
        bool bit7 = (sum >> 7) & 1;
        if (bit7 == 1)
        {
            cout << "Седьмой бит числа  "<< sum << "  содержит 1" << endl;
        }

    // находим сумму положительных элементов массива
    for (int i = 0; i < n; i++)
    {
        if (m[i] >= 0)
        {
            sum2 += m[i];
        } 
    }
    cout << "Cумма положительных элементов = " << sum2 << endl;
    return (0);
}
