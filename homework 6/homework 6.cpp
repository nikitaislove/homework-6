#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;


ofstream fout;
ifstream fin;


/* ЗАДАНИЕ 1*/

int* ptrArrTask1;

void InitArrTask1(int* ptrArrTask1, int SizeTask1)
{
    for (int i = 0; i < SizeTask1; i++)
    {
        ptrArrTask1[i] = (i == 0) ? 1 : ptrArrTask1[i - 1] * 2;
        cout << ptrArrTask1[i] << " ";
    }
    cout << endl;

    return;
}

void Task1(int* ptrArrTask1, int SizeTask1)
{
    ptrArrTask1 = new (std::nothrow) int[SizeTask1];

    if (ptrArrTask1 != nullptr)
    {
        InitArrTask1(ptrArrTask1, SizeTask1);
        delete[] ptrArrTask1;
        ptrArrTask1 = nullptr;
    }

    return;
}

/* ЗАДАНИЕ 2*/



int** AllocateMemory(size_t SizeT2_m, size_t SizeT2_n)
{
    int** ptrArrTask2 = new int* [SizeT2_m];
    for (size_t i = 0; i < SizeT2_m; i++)
    {
        ptrArrTask2[i] = new int[SizeT2_n];
    }

    return ptrArrTask2;
}

void DeleteMemory(int** ptrArrTask2, size_t SizeT2_m)
{
    for (size_t i = 0; i < SizeT2_m; i++) {
        delete[] ptrArrTask2[i];
    }
    delete[] ptrArrTask2;
    ptrArrTask2 = nullptr;

    return;
}

void Task2(int** ArrayTask2, size_t SizeT2_m, size_t SizeT2_n)
{

    for (size_t i = 0; i < SizeT2_m; i++)
    {
        for (size_t j = 0; j < SizeT2_n; j++)
        {
            ArrayTask2[i][j] = rand() % 100;
            if (ArrayTask2[i][j] < 10)
            {
                cout << " " << ArrayTask2[i][j] << " ";
            }
            else
            {
                cout << ArrayTask2[i][j] << " ";
            }
        }
        cout << endl;
    }

    return;
}


/* ЗАДАНИЕ 3*/

void CreateFileTXT(string FileName)
{
    FileName = FileName + ".txt";
    ofstream fout(FileName);
    return;
}

void FillFileTXT(string FileName, int NumberOfLines)
{
    char temp;
    FileName = FileName + ".txt";
    fout.open(FileName, std::ofstream::binary);
    fout << "File: ";
    if (fout.is_open())
    {
        for (int i = 0; i < (NumberOfLines - 5); i++)
        {
            temp = 'a' + rand() % ('z' - 'a');
            fout << temp << " ";
        }
    }
    else
    {
        cout << "Error. Can not open file.";
    }
    fout.close();
    return;
}


int main()
{
    // Задание 1

    int SizeTask1;

    do
    {
        cout << "Please, enter size of your Array: ";
        cin >> SizeTask1;
    } while (SizeTask1 <= 0);


    Task1(ptrArrTask1, SizeTask1);


    // Задание 2

    int SizeT2_m, SizeT2_n;

    cout << "VVEDITE RAZMER MASSIVA" << endl;
    do
    {
        cout << "STROKI: ";
        cin >> SizeT2_m;
    } while (SizeT2_m <= 0);
    do
    {
        cout << "STOLBEC: ";
        cin >> SizeT2_n;
    } while (SizeT2_n <= 0);

    AllocateMemory(SizeT2_m, SizeT2_n);



    int** ArrayTask2 = AllocateMemory(SizeT2_m, SizeT2_n);
    Task2(ArrayTask2, SizeT2_m, SizeT2_n);
    DeleteMemory(ArrayTask2, SizeT2_m);
    cout << endl;


    // Задание 3


    string FileName1, FileName2;
    int NumberOfLines;

    cout << "Input File 1 name: ";
    cin >> FileName1;
    cout << "Input File 2 name: ";
    cin >> FileName2;

    CreateFileTXT(FileName1);
    CreateFileTXT(FileName2);

    do
    {
        cout << "Input NumberOfLines (50-100 symbols): ";
        cin >> NumberOfLines;
    } while ((NumberOfLines < 50) || (NumberOfLines > 100));

    FillFileTXT(FileName1, NumberOfLines);
    FillFileTXT(FileName2, NumberOfLines);

    cout << endl;


    return 0;
}
