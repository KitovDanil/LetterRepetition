/*************************
* Author: Kitov D.A. *
* Date: 01.11.2023 *
* Name: Letters and two-letter combination frequency *
*************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
  // Set the 'fin' stream for input from the 'input.txt' file
  ifstream fin("input.txt");

  // Enter all the text from the file
  string input, stringToken;
  while(fin >> stringToken) {
    input += stringToken;
  }

  // We create two vectors - one stores all letters and two-letter combinations, and the second - their number (it has the same size)
  vector<string> lettersList;
  vector<int> numbersList;

  // We count each letter in the text, adding it to the vector if it was not already exist, and adding 1 to the number if it was
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

  // The index of the first two-letter combination in the vector begins after the index of the last letter
  int lastLetterIndex = lettersList.size();
  // We count each two-letter combination in an almost identical way to how we counted letters
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

  // Output both vectors
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
