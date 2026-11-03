#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 7
//=====================================================

// --------- Two DFAs ---------------------------------

// You may add other functions to help your implementation of the state transitions

// WORD DFA 
// Done by: ** Manya Sanchez &
bool word (string s)
{

  int state = 0;
  int charpos = 0;
  /* replace the following todo the word dfa  ** */
  while (s[charpos] != '\0') 
    {
      if (state == 0 && s[charpos] == 'v')
      state = q01f;
      
      else
      if (state == 0 && s[charpos] == 's')
      state = qs;
   
      else
      if (state == 0 && s[charpos] == 't')
      state = qt;
      
      else
      if (state == 0 && s[charpos] == 'c')
      state = qc;
      
      else
      if (state == 0 && s[charpos] == 'h')
      state = q3;
     
      else
      if (state == 0 && s[charpos] == 'y')
      state = q2;
      
      else
      if (state == 0 && s[charpos] == 'n')
      state = q3;
      
      else
      if (state == 0 && s[charpos] == 'd'||'w'||'z'||'j')
      state = q2;
     
      else
      if (state == 0 && s[charpos] == 'b'||'g'||'k'||'m'||'p'||'r')
      state = q3;
      
      else
      if (state == qs && s[charpos] == 'v')
      state = q01f;
      
      else
      if (state == qs && s[charpos] == 'h')
      state = q2;
   
      else
      if (state == qt && s[charpos] == 'v')
      state = q01f;
     
      else
      if (state == qt && s[charpos] == 's')
      state = q2;
     
      else
      if (state == qc && s[charpos] == 'h')
      state = q2;
    
      else
      if (state == q2 && s[charpos] == 'v')
      state = q01f;
      
      else
      if (state == q3 && s[charpos] == 'v')
      state = q01f;
      
      else
      if (state == q3 && s[charpos] == 'y')
      state = q2;
      
      else
      /*
      if (state == q01f && s[charpos] == 'v')
      state = q01f;
      charpos++;
      else
      if (state == q01f && s[charpos] == 's')
      state = qs;
      charpos++;
      else
      if (state == q01f && s[charpos] == 't')
      state = qt;
      charpos++;
      else
      if (state == q01f && s[charpos] == 'c')
      state = qc;
      charpos++;
      else
      if (state == q01f && s[charpos] == 'h')
      state = q3;
      charpos++;
      else
      if (state == q01f && s[charpos] == 'y')
      state = q2;
      charpos++;
      else
      if (state == q01f && s[charpos] == 'n')
      state = q03f;
      charpos++;
      else
      if (state == q01f && s[charpos] == 'd'||'w'||'z'||'j')
      state = q2;
      charpos++;
      else
      if (state == q01f && s[charpos] == 'b'||'g'||'k'||'m'||'p'||'r')
      state = q3;
      charpos++;
      else
      if (state == q03f && s[charpos] == 'v')
      state = q01f;
      charpos++;
      else
      if (state == q03f && s[charpos] == 's')
      state = qs;
      charpos++;
      else
      if (state == q03f && s[charpos] == 't')
      state = qt;
      charpos++;
      else
      if (state == q03f && s[charpos] == 't')
      state = qt;
      charpos++;
      else
      if (state == q03f && s[charpos] == 'c')
      state = qc;
      charpos++;
      else
      if (state == q03f && s[charpos] == 'h')
      state = qh;
      charpos++;
      else
      if (state == q03f && s[charpos] == 'y')
      state = qy;
      charpos++;
      else
      if (state == q03f && s[charpos] == 'n')
      state = qn;
      charpos++;
      else
      if (state == q03f && s[charpos] == 'd'||'w'||'z'||'j')
      state = q2;
      charpos++;
      else
      if (state == q03f && s[charpos] == 'b'||'g'||'k'||'m'||'p'||'r')
      state = q3;
      charpos++;
      else
      */
	  return(false);
      charpos++;
    }//end of while

  // where did I end up???? in one of the final states
  if (state == q01f || state == q03f) return(true);  // end in a final state
   else return(false);
  
}

// PERIOD DFA 
// Done by: ** 
bool period (string s)
{  // complete this **
if (s == "."){return true;}
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: ** Manya Sanchez &

// ** Update the tokentype to be ERROR, WORD1, WORD2, PERIOD, EOFM, etc.
enum tokentype {ERROR, WORD1,WORD2,PERIOD,EOFM,VERB,
  VERBNEG,VERBPAST,VERBPASTNEG,IS,WAS,OBJECT,SUBJECT,
  DESTINATION,PRONOUN,CONNECTOR };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"ERROR", "WORD1","WORD2","PERIOD",
  "EOFM","VERB","VERBNEG","VERBPAST","VERBPASTNEG","IS",
  "WAS","OBJECT","SUBJECT","DESTINATION","PRONOUN",
  "CONNECTOR" }; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** Your scanner should work without any additional files.
string reservedWords [2][18] = {
  {"masu",VERB}
  {"masen",VERBNEG}
  {"mashita",VERBPAST}
  {"masendeshita",VERBPASTNEG}
  {"desu",IS}
  {"deshita",WAS}
  {"o",OBJECT}
  {"wa",SUBJECT}
  {"ni", DESTINATION}
  {"watashi",PRONOUN}
  {"anata",PRONOUN}
  {"kare",PRONOUN}
  {"kanojo",PRONOUN}
  {"sore",PRONOUN}
  {"mata", CONNECTOR}
  {"soshite",CONNECTOR}
  {"shikashi",CONNECTOR}
  {"dakara",CONNECTOR}
};

// ------------ Scanner and Driver ----------------------- 


// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Manya Sanchez &
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
   if (w == "eofm"){return;}
   if (word(w) == false && period(w) == false){
  tt = ERROR;
   }
  (word(w)){
    //go through reserved list tokens and check
  }
  
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

