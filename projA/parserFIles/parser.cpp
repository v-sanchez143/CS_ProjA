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

// ------------ Scanner.cpp fuctions----------------------- 
bool isVowel(char c); //true if c is a vowel(a e i o u I E)
bool isDWZJ(char c); //true if c is d/w/z/j ** note y not included because it have its own special rule (check notes) **
bool isBGKMPR(char c); //true if c is b/g/k/m/p/r ** note h & n not included because they have their own special rule (check notes) **
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
bool period (string s)
{  // complete this **
    if (s == ".") //if token is a period('.') -> return true
        return true;
    else //otherwise return false
        return false;
}
enum tokentype {ERROR, WORD1,WORD2,PERIOD,EOFM,VERB,
  VERBNEG,VERBPAST,VERBPASTNEG,IS,WAS,OBJECT,SUBJECT,
  DESTINATION,PRONOUN,CONNECTOR };
string tokenName[30] = {"ERROR", "WORD1","WORD2","PERIOD",
  "EOFM","VERB","VERBNEG","VERBPAST","VERBPASTNEG","IS",
  "WAS","OBJECT","SUBJECT","DESTINATION","PRONOUN",
  "CONNECTOR" }; 
struct reservedWord
{
    string word; //the reserved word
    tokentype type; //its token type
};
const int NUMRESERVED = 18; //amt of words in the table
reservedWord reservedWords[NUMRESERVED] = {
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


//=================================================
// File parser.cpp written by Group Number: 7
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: match fail, incorrect token type found
// Done by: Manya Sanchez
void syntaxerror1(saved_lexeme, token_type)
{
   cout << "SYNTAX ERROR: expected" << token_type << "but found" << saved_lexeme << endl;
   exit (1); //halt
}

// Type of error: default case in switch stmt picked meaning invalid or unexpected token inputed
// Done by: Manya Sanchez
void syntaxerror2(saved_lexeme, parser_function)
{
   cout << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << parser_function << endl;
   exit (1); //halt
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

// Grammar: <story> -> <story> <prime>
// Done by: manya sanchez
void story () {
cout << ("processing <story>\n");
story(); //recursivly call story to read multiple stories
story_prime(); //call story_prime to begin taking apart 
//the expression and read the next expression or end bc no more sentences
match(END); // if find eofm then end the cycle 
}

// Grammar: <story_prime> -> <sentence> <story_prime> | epsilon
// Done by: manya sanchez
void story_prime() {
   cout << "Processing <story_prime>\n";
   switch(next_token()){
      case read:
         sentence(); //begin reading current sentence
         story_prime(); //read the next sentence 
         break;
      default: //the nxt token does not belong to a stmt
         //use epsilon n return
         return;
      }
   }
  
}
// Grammar: <sentence> -> <connector> <noun> SUBJECT <after_noun>
// Done by: manya sanchez
void sentence(){
   cout << "processing <sentence>\n";
   connector();
   noun();
   match (SUBJECT);
   after_noun();
}

// Grammar: <after_subject> -> <verb> <tense> PERIOD
//             | <noun> <after_noun>
// Done by: manya sanchez
void after_subject(){
   cout << "processing <after_subject>\n";
   switch (next_token()){
      case verb:
         verb();
         tense();
         match(PERIOD);
         break;
      case noun:
         noun();
         after_noun();
         break;
      default: //syntax error bc it should be a noun or verb token type
         syntaxerror1( saved_lexeme, "verb or noun");
   }  
}

// Grammar: <after_noun> -> <be> PERIOD | DESTINATION <verb> <tense> 
//                PERIOD | OBJECT <after_object>
// Done by: Manya Sanchez
void after_noun(){
   cout << "processing <after_noun>\n";
   switch (next_token()){
      case be:
         be();
         match(PERIOD);
         break;
      case dest:
         match(DESTINATION);
         verb();
         tense();
         match(PERIOD);
         break;
      case object:
         match(OBJECT);
         after_object();
      default:
         syntaxerror2(saved_lexeme, "after_noun")
   }
}

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:

// Grammar: 
// Done by:
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
