#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 
//=====================================================

// --------- Two DFAs ---------------------------------

// You may add other functions to help your implementation of the state transitions

// WORD DFA 
// Done by: **
bool word (string s)
{

  int state = 0;
  int charpos = 0;
  /* replace the following todo the word dfa  **
  while (s[charpos] != '\0') 
    {
      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	  return(false);
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
  */
}

// PERIOD DFA 
// Done by: **
bool period (string s)
{  // complete this **
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be ERROR, WORD1, WORD2, PERIOD, EOFM, etc.
enum tokentype {ERROR, };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"ERROR", }; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** Your scanner should work without any additional files.


// ------------ Scanner and Driver ----------------------- 


// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: 
void scanner(tokentype& tt, string& w)
{
  cin >> w;
  // 1. If it is eofm, return right now.   

  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.

  4. Return the token type & string  (pass by reference)
  */
  tt = ERROR;
}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
int main()
{
  tokentype thetype;
  string theword; 

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

      cout << "Word: " << theword << " Type: " << tokenName[thetype]  << endl;
    }

}// end

