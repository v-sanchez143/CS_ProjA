#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: 7
//=====================================================

// --------- Two DFAs ---------------------------------

// You may add other functions to help your implementation of the state transitions
//helper prototypes:
bool isVowel(char c); //true if c is a vowel(a e i o u I E)
bool isDWZJ(char c); //true if c is d/w/z/j ** note y not included because it have its own special rule (check notes) **
bool isBGKMPR(char c); //true if c is b/g/k/m/p/r ** note h & n not included because they have their own special rule (check notes) **

// WORD DFA 
// Done by: Manya Sanchez & R-Gee Capili
//RE: (vowel | vowel n | cons vowel | cons vowel n | cons pair vowel | cons pair vowel n)^+

//q0q1qf == q01f , q0q3qf == q03f
const int q0 = 0, qs = 1, qt = 2, qc = 3, q2 = 4, q3 = 5, q01f = 6, q03f = 7; //state names for easier reading (each num just distinct)

bool word (string s)
{

  int state = q0; //every word starts in start state (q0)
  int charpos = 0;
  /* replace the following todo the word dfa  ** */
  
  while (s[charpos] != '\0') //'\0' == end of string
    {
      char c = s[charpos]; //c == s[charpos] == the current letter (for easier read)

      //each if is one trs line: Trs(state, letter) = next state 
      //** only one can match b/c each letter is in exactly one group **

      // ** from q0 (start state) **
      if (state == q0 && isVowel(c)) //Trs(q0, V) = q01f
          state = q01f;

      else if (state == q0 && c == 's') //Trs(q0, s) = qs
          state = qs;

      else if (state == q0 && c == 't') //Trs(q0, t) = qt
          state = qt;

      else if (state == q0 && c == 'c') //Trs(q0, c) = qc
          state = qc;

      //HELPER FUNC bgkmpr and h and n 
      else if (state == q0 && (c == 'h' || c == 'n' || isBGKMPR(c))) //Trs(q0, bghkmpnr) = q3
          state = q3;

      //HELPER FUNC dwzj and y
      else if (state == q0 && (c == 'y' || isDWZJ(c))) //Trs(q0, dwzyj) = q2
          state = q2;


      // ** from single states **
      else if (state == qs && isVowel(c)) //Trs(qs, V) = q01f
          state = q01f;

      else if (state == qs && c == 'h') //Trs(qs, h) = q2  ** note h's "special rule" **
          state = q2;

      else if (state == qt && isVowel(c)) //Trs(qt, V) = q01f
          state = q01f;

      else if (state == qt && c == 's') //Trs(qt, s) = q2
          state = q2;

      else if (state == qc && c == 'h') //Trs(qc, h) = q2  ** note h's "special rule" **
          state = q2;

      else if (state == q2 && isVowel(c)) //Trs(q2, V) = q01f
          state = q01f;

      else if (state == q3 && isVowel(c)) //Trs(q3, V) = q01f
          state = q01f;

      else if (state == q3 && c == 'y') //Trs(q3, y) = q2 ** note y's "spcial rule" **
          state = q2;

      // ** from q01f FINAL **
      else if (state == q01f && isVowel(c)) //Trs(q01f, V) = q01f [loop back]
          state = q01f;

      else if (state == q01f && c == 'n') //Trs(q01f, n) = q03f ** note n's "special rule" **
          state = q03f;

      else if (state == q01f && c == 's') //Trs(q01f, s) = qs
          state = qs;

      else if (state == q01f && c == 't') //Trs(q01f, t) = qt
          state = qt;

      else if (state == q01f && c == 'c') //Trs(q01f, c) = qc
          state = qc;

      //HELPER FUNC dwzyj and y
      else if (state == q01f && (c == 'y' || isDWZJ(c))) //Trs(q01f, dwzyj) = q2
          state = q2;

      //HELPER FUNC bgkmpr and h
      else if (state == q01f && (c == 'h' || isBGKMPR(c))) //Trs(q01f, bghkmpr) = q3
          state = q3;


      // ** from q03f FINAL **
      else if (state == q03f && isVowel(c)) //Trs(q03f, V) = q01f 
          state = q01f;

      else if (state == q03f && c == 's') //Trs(q03f, s) = qs
          state = qs;

      else if (state == q03f && c == 't') //Trs(q03f, t) = qt
          state = qt;

      else if (state == q03f && c == 'c') //Trs(q03f, c) = qc
          state = qc;

      //HELPER FUNC dwzyj and y
      else if (state == q03f && (c == 'y' || isDWZJ(c)) ) //Trs(q03f, dwzyj) = q2
          state = q2;

      //HELPER FUNC bgkmpr and h and n 
      else if (state == q03f && (c == 'h' || c == 'n' || isBGKMPR(c)) ) //Trs(q03f, bghkmnpr) = q3
          state = q3;

      else
          return(false); //no trs matched -> not valid word

      charpos++; //move on to next letter
  
  }//end of while


  // where did I end up???? in one of the final states
  if (state == q01f || state == q03f) return(true);  // end in a final state
   
  else return(false); 
  
}

// PERIOD DFA 
// Done by: R-Gee Capili
bool period (string s)
{  // complete this **
    if (s == ".") //if token is a period('.') -> return true
        return true;
    else //otherwise return false
        return false;
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: Manya Sanchez & R-Gee Capili

// ** Update the tokentype to be ERROR, WORD1, WORD2, PERIOD, EOFM, etc.
//table 1: the token types [each name is a number]
enum tokentype {ERROR, WORD1,WORD2,PERIOD,EOFM,VERB,
  VERBNEG,VERBPAST,VERBPASTNEG,IS,WAS,OBJECT,SUBJECT,
  DESTINATION,PRONOUN,CONNECTOR };

// ** For the display names of tokens - must be in the same order as the tokentype.
//table 2: the text for each token type
string tokenName[30] = {"ERROR", "WORD1","WORD2","PERIOD",
  "EOFM","VERB","VERBNEG","VERBPAST","VERBPASTNEG","IS",
  "WAS","OBJECT","SUBJECT","DESTINATION","PRONOUN",
  "CONNECTOR" }; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** Your scanner should work without any additional files.
struct reservedWord
{
    string word; //the reserved word
    tokentype type; //its token type
};

const int NUMRESERVED = 18; //amt of words in the table

//table 3: the reserved words from reservedwords.txt file [each entry pairs word w its token type]
reservedWord reservedWords[NUMRESERVED] =
{
    //verb markers
    {"masu",VERB},
    {"masen",VERBNEG},
    {"mashita",VERBPAST},
    {"masendeshita",VERBPASTNEG},
    { "desu",IS},
    { "deshita",WAS},

    //obj/subj/dest
    {"o",OBJECT},
    {"wa",SUBJECT},
    {"ni", DESTINATION},

    //pronouns
    {"watashi",PRONOUN},
    {"anata",PRONOUN},
    {"kare",PRONOUN},
    {"kanojo",PRONOUN},
    {"sore",PRONOUN},

    //connectors
    {"mata", CONNECTOR},
    {"soshite",CONNECTOR},
    {"shikashi",CONNECTOR},
    {"dakara",CONNECTOR}
};


// ------------ Scanner and Driver ----------------------- 


// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Manya Sanchez & Rgee Capili
void scanner(tokentype& tt, string& w) //tt & w are pbr(&) so the values set here are seen by main after function returns
{
  cin >> w; //read next word (skips blanks between words)

  // 1. If it is eofm, return right now.   
  if (w == "eofm")
  {
      tt = EOFM;
      return;
  }
  
  // 2. Call the token functions (word and period) one after another (if-then-else).
  // Generate a lexical error message if both DFAs failed.
  // Let the tokentype be ERROR in that case.
  if (word(w)) //the word DFA accepted it
  {
      // 3. If it was a word, check against the reservedwords list.
      // If not reserved, tokentype is WORD1 or WORD2 decided based on the last character.

      for (int i = 0; i < NUMRESERVED; i++) //look at each reserved word
          if (w == reservedWords[i].word) //found a match
          {
              tt = reservedWords[i].type; //use its token type
              return; //done w this word
          }

      //not reserved: WORD2 if it ends w I or E 
      char last = w[w.length() - 1]; //last letter of word
      if (last == 'I' || last == 'E')
          tt = WORD2;

      else //othherwise WORD1
          tt = WORD1;
  }

  else if (period(w)) //the period DFA accepted it
      tt = PERIOD;

  else
  {
      //both DFAs failed -> lexical error
      cerr << "Lexical error: " << w << " isn't a valid token\n";
      tt = ERROR;
  }

  // 4. Return the token type & string  (pass by reference)
  
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

}// end of main


// ** HELPER FUNCTIONS **

//true if c is a vowel(a e i o u I E)
bool isVowel(char c) //replaces the V in the DFA trs
{
    return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'I' || c == 'E');
}

//true if c is d/w/z/j ** note y not included because it have its own special rule (check notes) **
bool isDWZJ(char c)
{
    return(c == 'd' || c == 'w' || c == 'z' || c == 'j');
}

//true if c is b/g/k/m/p/r ** note h & n not included because they have their own special rule (check notes) **
bool isBGKMPR(char c)
{
    return(c == 'b' || c == 'g' || c == 'k' || c == 'm' || c == 'p' || c == 'r');
}
