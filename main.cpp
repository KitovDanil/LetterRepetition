/*************************
* �����: ����� �.�. *
* ����: 01.11.2023 *
* ��������: ������� ���������� ���� � ������������� ��������� *
*************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
  // ������ ����� fin ��� ����� �� ����� input.txt
  ifstream fin("input.txt");

  // ������ ���� ����� �� �����
  string input, stringToken;
  while(fin >> stringToken) {
    input += stringToken;
  }

  // ������� ��� ������� - ���� ������ ��� ����� � ������������� ���������, � ������ - �� ���������� (�� ���� �� �������)
  vector<string> lettersList;
  vector<int> numbersList;

  // ������ ������� ������ ����� � ������, �������� �� � ������, ���� �� ��� �� ����, � �������� 1 � ����������, ���� ����
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

  // ������ ������� �������������� ��������� � ������� ���������� ����� ������� ��������� �����
  int lastLetterIndex = lettersList.size();
  // ������������ ������ ������������� ��������� ����������� ���������� �������� ����, ��� ������������ �����
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

  // ������� ��� �������
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
