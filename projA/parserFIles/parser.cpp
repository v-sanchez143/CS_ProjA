#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy functions in scanner.cpp here.
   but the old main() function in scanner.cpp should be removed.
*/
void scanner(tokentype& tt, string& w)
{
  cin >> w; //takes in the string
   if (w == "eofm"){return;} //if end of file, go back to main
   if (word(w) == false && period(w) == false){ //if the str is not a word or period, it is an error
  tt = ERROR;
  
   }
  (word(w)){
    //go through reserved list tokens and check
  }
  
}//the end of scanner


//=================================================
// File parser.cpp written by Group Number: ** group 7
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: syntax error: it's looking for defined token names 
// not the token themselves yet. This error occurs when a word
//is found before it's token type 
// Done by: Manya Sanchez
void syntaxerror1(token_type, saved_lexeme)
{
   cout << "SYNTAX ERROR: expected" << token_type << "but found" << saved_lexeme << endl;
   exit (1);
}

// Type of error: syntax error: invalid or unexpected token in a 
// the wrong token type
// Done by: ** Manya Sanchez
void syntaxerror2(saved_lexeme, parser_function)
{
   cout << "SYNTAX ERROR: unexpected " << saved_lexeme;
   cout << " found in " << parser_function << endl;
   exit (1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: **
// Done by: **
tokentype next_token(){}

// Purpose: **
// Done by: **
bool match(tokentype expected) {}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **

void story(){
   // **
}  // to be implemented as part of the assignment

//----------- Driver ---------------------------

// The new test driver to start the parser
// You don't need to change this part of the code.
int main()
{
  story();
  return 0;
}// end
//** require no other input files!
