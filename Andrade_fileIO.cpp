#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream gbaIn;
    ofstream capsOut, wordsInTextCount, upperCaseLetter;
    
    int countWords = 0, countWord1 = 0, countWord2 = 0, countWord3 = 0, countWord4 = 0, countLongWord = 0, countCharsForWords = 0;
    string word, letterUpperCase;
    string allUpperCase;
    
    gbaIn.open("gba.txt");
    
    wordsInTextCount.open("result.txt");
    capsOut.open("capitalize.txt");
    upperCaseLetter.open("uppercase.txt");
   
    if(gbaIn.fail())
    {
        cout << "Error opening the input file" << endl;
        exit(1);
    }
    while(gbaIn >> word)
    {   
   //---------------------------------------------------------
        letterUpperCase += toupper(word[0]);
        letterUpperCase += word.substr(1, word.length() - 1);
        letterUpperCase += " ";
  //----------------------------------------------------------     
        if(word != "--")
          {
            countWords++;
            if(word[word.length() -1] == ',' || word[word.length() -1] == '.')
            {
                word = word.substr(0, word.length() - 1);
            }
            countCharsForWords += word.length();
            
            switch(word.length())
            {
                case 1:
                countWord1++;
                break;
                case 2:
                countWord2++;
                break;
                case 3:
                countWord3++;
                break;
                case 4:
                countWord4 ++;
                break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                default:
                countLongWord ++;
                break;
            }
          }
  //-----------------------------------------------------------
             
  //--------------------------------------------------------------             
        for(int i = 0; i < word.length(); i++)
        {      
          allUpperCase += toupper(word[i]);
            
        }
        allUpperCase += " ";
 //----------------------------------------------------------------
    }
    
    upperCaseLetter << letterUpperCase;
    capsOut << allUpperCase;
    wordsInTextCount << "The total words in the gba.txt file is " << countWords << endl;
    wordsInTextCount << "Average characters per word: "<< countCharsForWords/countWords << endl;
    wordsInTextCount << countWord1 << " words of length 1" << endl;
    wordsInTextCount << countWord2 << " words of length 2" << endl;
    wordsInTextCount << countWord3 << " words of length 3" << endl;
    wordsInTextCount << countWord4 << " words of length 4" << endl;
    wordsInTextCount << countLongWord << " words of length 11 or longer" << endl;
    
    
       
    gbaIn.close();
    capsOut.close();
    wordsInTextCount.close();
    upperCaseLetter.close();
     
    return 0;
}
