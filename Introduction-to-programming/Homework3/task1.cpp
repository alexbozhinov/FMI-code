/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Aleks Bozhinov
* @idnumber 62457
* @task 1
* @compiler GCC
*
*/

#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<limits>

const int ROW_SIZE = 500;
const int NUMBER_OF_ROWS = 10;
const int ANSWER_SIZE = 100;
const int CORRECT_INCORRECT_SIZE = 40;

using namespace std;



char questions[NUMBER_OF_ROWS][ROW_SIZE] = {
       {"Who invented C++?"},
       {"Who was not a member of Beatles?"},
       {"Which state has cities named San Francisco and Hollywood?"},
       {"What gas makes voices sound higher when inhaled?"},
       {"Which one of the following is not an Ivy League University?"},
       {"Which U.S. city is home to the Liberty Bell and Independence Hall?"},
       {"Which biblical figure built an ark?"},
       {"Which organ produces a liquid known as bile?"},
       {"In medieval times, which of these professionals was responsible for entertaining the royal courts?"},
       {"A parasol is a lightweight form of what accessory?"}
     };
char answers[NUMBER_OF_ROWS][ROW_SIZE] = {
       {"A. James Gosling       B. Brendan Eich      C. Bjarne Stroustrup     D. Guido van Rossum"},
       {"A. John Lennon      B. Paul McCarthey      C. Ringo Star      D. Justin Timberlake"},
       {"A. California      B. Utah      C. Hawaii      D. Montana"},
       {"A. Oxygen      B. Nitrogen      C. Sulfur Hexafluoride      D. Helium"},
       {"A. Harvard      B. Princeton      C. Columbia      D. Hogwarts"},
       {"A. Vancouver      B. Mexico City      C. Beijing      D. Philadelphia"},
       {"A. Noah      B. Jesus Christ      C. Moses      D. Eve"},
       {"A. Heart      B. Liver      C. Kidney      D. Skin"},
       {"A. Barber     B. Knight      C. Jester      D. Blacksmith"},
       {"A. Umbrella      B. Hat      C. Cane      D. Bracelet"}
     };

char answerA[NUMBER_OF_ROWS][ANSWER_SIZE] = {
  {"A) James Gosling "},  {"A) John Lennon "},   {"A) California "},   {"A) Oxygen  "},   {"A) Harvard"},
  {"A) Vancouver "},  {"A) Noah "},   {"A) Heart "},   {"A) Barber"},   {"A) Umbrella "}
};

char answerB[NUMBER_OF_ROWS][ANSWER_SIZE] = {
  {"B) Brendan Eich "},  {"B) Paul McCarthey  "},   {"B) Utah "},   {" B) Nitrogen "},   {"B) Princeton "},
  {"B) Mexico City "},  {"B) Jesus Christ "},   {"B) Liver "},   {"B) Knight "},   {"B) Hat  "}
};

char answerC[NUMBER_OF_ROWS][ANSWER_SIZE] = {
  {"C) Bjarne Stroustrup "},  {"C) Ringo Star "},   {"C) Hawaii "},   {"C) Sulfur Hexafluoride "},   {"C) Columbia "},
  {"C) Beijing "},  {"C) Moses "},   {"C) Kidney "},   {"C) Jester "},   {"C) Cane "}
};

char answerD[NUMBER_OF_ROWS][ANSWER_SIZE] = {
  {"D) Guido van Rossum "},  {"D) Justin Timberlake "},   {"D) Montana "},   {"D) Helium "},   {"D) Hogwarts "},
  {"D) Philadelphia "},  {"D) Eve "},   {"D) Skin "},   {"D) Blacksmith "},   {"D) Bracelet "}
};
char correctAnswer[ANSWER_SIZE] = {'C','D','A','D','D','D','A','B','C','A'};
char incorrectAnswers[NUMBER_OF_ROWS][NUMBER_OF_ROWS] = {
       {'A','B','D'},
       {'A','B','C'},
       {'B','C','D'},
       {'A','B','C'},
       {'A','B','C'},
       {'A','B','C'},
       {'B','C','D'},
       {'A','C','D'},
       {'A','B','D'},
       {'B','C','D'}
     };

char choice;

  int randomNumber(){
     srand(time(0));
     int randomNum;
     randomNum = rand()%10;
     return randomNum;
  }
  //I copied function random from Internet!
  int random(int minimum, int maximum) //range : [min, max)
  {
    bool first = true;
    if (first)
      {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
      }
   return minimum + rand() % (( maximum + 1 ) - minimum);
  }

  int randIncorrect = random(0,2);

  void jokerFifthyFifthy(int randNum){
    char incorrect[CORRECT_INCORRECT_SIZE], correct[CORRECT_INCORRECT_SIZE];
       cout<<"You used a joker 50:50 now the possible answers are:" <<endl;
    for(int i=0;i<1;i++){
       for(int j=0;j<CORRECT_INCORRECT_SIZE;j++){
            if(incorrectAnswers[randNum][randIncorrect] == 'A')  incorrect[j] = answerA[randNum][j];
            else if(incorrectAnswers[randNum][randIncorrect] == 'B')  incorrect[j] = answerB[randNum][j];
            else if(incorrectAnswers[randNum][randIncorrect] == 'C')  incorrect[j] = answerC[randNum][j];
            else if(incorrectAnswers[randNum][randIncorrect] == 'D')  incorrect[j] = answerD[randNum][j];
       }
    }
    for(int i=0;i<1;i++){
       for(int j=0;j<CORRECT_INCORRECT_SIZE;j++){
           if(correctAnswer[randNum] == 'A') correct[j] = answerA[randNum][j];
           else if(correctAnswer[randNum] == 'B') correct[j] = answerB[randNum][j];
           else if(correctAnswer[randNum] == 'C') correct[j] = answerC[randNum][j];
           else if(correctAnswer[randNum] == 'D') correct[j] = answerD[randNum][j];
       }
    }

    if(correctAnswer[randNum]<incorrectAnswers[randNum][randIncorrect]){
      cout<<endl;
        for(int i=0;i<CORRECT_INCORRECT_SIZE;i++){
            cout<<correct[i];
        }

     for(int i=0;i<CORRECT_INCORRECT_SIZE;i++){
           cout<<incorrect[i];
     }
    } else {
    cout<<endl;
      for(int i=0;i<CORRECT_INCORRECT_SIZE;i++){
          cout<<incorrect[i];
      }
      for(int i=0;i<CORRECT_INCORRECT_SIZE;i++){
           cout<<correct[i];
      }
     }
  }

  char questionAnswerPrint( char questions [][ROW_SIZE], char answers [][ROW_SIZE], int randNum){
     for(int i = 0;i<1;i++){
        for(int j=0; j<ANSWER_SIZE; j++){
            cout<<questions[randNum][j];
        }
        cout<<endl;
    }
     cout<<endl;
      for(int i=0;i<1;i++){
          for(int j=0;j<ROW_SIZE;j++){
              cout<<answers[randNum][j];
          }
       cout<<endl;
      }
  }

  void ifIsCorrect(int randNum){
     cout<<"Input your answer: ";
     cin>>choice;

   while(1){
              if( cin.fail() ){
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                 continue;
                 }
   if(choice!='J'&&choice!='A'&&choice!='B'&&choice!='C'&&choice!='D') {
    cout<<"Your input is incorrect! Try with another letter: ";
    cin>>choice;
    continue;
   }

   else if(choice == 'J'){
     jokerFifthyFifthy(randNum);cout<<endl;
      cout<<"Input your answer: ";
      cin>>choice;
      if(choice!='A'&&choice!='B'&&choice!='C'&&choice!='D') {
      cout<<"Your input is incorrect! Try with another letter: "; cin>>choice; continue;}

    if(choice == correctAnswer[randNum]) cout<<"Congratulations! You won 1 000 000 dollars!"<<endl;
    else if(choice != correctAnswer[randNum]) cout<<"You lost the game!"<<endl;
   }

    else if(choice == correctAnswer[randNum]) cout<<"Congratulations! You won 1 000 000 dollars!"<<endl;
    else cout<<"You lost the game!"<<endl;

    if( !cin.fail() )
        break;
    }
  }


  int main(){
  char YesNo;
  int randNum = randomNumber();

  cout<<"W H O  W A N T S   T O  B E  A  M I L L I O N A I R E ?"<<endl;
  cout<<endl;
  cout<<"Question number 15 for 1 000 000 million dollars"<<endl;
  cout<<endl;
  questionAnswerPrint(questions, answers, randNum);
  cout<<endl;
  cout<<"If you want to use 50:50 joker input J as an answer or input A, B, C or D for an answer"<<endl;
  ifIsCorrect(randNum);

  while(1){
    cout<<"Do you want another question? If you want input Y, or if you don't want input N: ";
    cin>>YesNo;

    if(YesNo!='Y'&&YesNo!='N') {cout<<"Your input is incorrect! try again!"; continue;}
    else if(YesNo == 'Y') {randNum = randomNumber();
        cout<<"Question number 15 for 1 000 000 million dollars"<<endl;
        cout<<endl;
        questionAnswerPrint(questions, answers , randNum);
        cout<<endl;
        cout<<"If you want to use 50:50 joker input J as an answer or input A, B, C or D for an answer"<<endl;
        ifIsCorrect(randNum);
    }
     else {
            cout<<"You end the game"<<endl;
           break;
     }
  }
  return 0;
  }

