/*************************
* Автор: Китов Д.А. *
* Дата: 01.11.2023 *
* Название: Частота повторения букв и двухбуквенных сочетаний *
*************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
  // Задаем поток fin для ввода из файла input.txt
  ifstream fin("input.txt");

  // Вводим весь текст из файла
  string input, stringToken;
  while(fin >> stringToken) {
    input += stringToken;
  }

  // Создаем два вектора - один хранит все буквы и двухбуквенные сочетания, а второй - их количество (он того же размера)
  vector<string> lettersList;
  vector<int> numbersList;

  // Делаем подсчет каждой буквы в тексте, добавляя ее в вектор, если ее еще не было, и добавляя 1 к количеству, если была
  for (int inputIndex = 0; inputIndex < input.size(); ++inputIndex) {
    bool letterInList = false;
    int letterIndexInList;
    for (int letterIndex = 0; letterIndex < lettersList.size(); ++letterIndex) {
      if (input[inputIndex] == lettersList[letterIndex][0]) {
        letterInList = true;
        letterIndexInList = letterIndex;
        break;
      }
    }
    if (letterInList) {
            ++numbersList[letterIndexInList];
    } else {
      lettersList.push_back(string(1, input[inputIndex]));
      numbersList.push_back(1);
    }

  }

  // Индекс первого двухбуквенного сочетания в векторе начинается после индекса последней буквы
  int lastLetterIndex = lettersList.size();
  // Подсчитываем каждое двухбуквенное сочетание практически идентичным способом тому, как подсчитывали буквы
  for (int inputIndex = 0; inputIndex < input.size() - 1; ++inputIndex) {
    bool doubleLetterInList = false;
    int doubleLetterIndex;
    for (int letterIndex = lastLetterIndex; letterIndex < lettersList.size(); ++letterIndex) {
      if (input.substr(inputIndex, 2) == lettersList[letterIndex]) {
        doubleLetterInList = true;
        doubleLetterIndex = letterIndex;
        break;
      }
    }
    if (doubleLetterInList) {
      ++numbersList[doubleLetterIndex];
    } else {
      lettersList.push_back( input.substr(inputIndex, 2) );
      numbersList.push_back(1);
    }
  }

  // Выводим оба вектора
  cout.setf(ios::left);
  for (int letterIndex = 0; letterIndex < lettersList.size(); ++letterIndex) {
    cout << setw(3) << lettersList[letterIndex] << " ";
  }
  cout << endl;
  for (int numberIndex = 0; numberIndex < numbersList.size(); ++numberIndex) {
    cout << setw(3) << numbersList[numberIndex] << " ";
  }
  return 0;
}
