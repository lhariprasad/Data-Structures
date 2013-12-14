#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <cstring>
using namespace std;
int choice;
string lvl, gamer_name;
time_t start, end, diff, total_time;
void level(){
    cout<< setw(45) << "Please Select a Difficulty level: " <<endl;
    cout<< setw(40) << "1 - Beginner"<<endl;
    cout<< setw(40) << "2 - Average"<<endl;
    cout<< setw(40) << "3 - Advanced"<<endl;
    cout << "\n Your Choice: ";
    cin>>choice;
}
void highscore(){
     ifstream score_ifile;
     if(choice == 1){
               lvl = "Beginner ";
               score_ifile.open("beg-score.txt");
     }else if(choice == 2){
            lvl = "Average ";
            score_ifile.open("ave-score.txt");
     }else{
            lvl = "Advanced ";
            score_ifile.open("adv-score.txt");
     }
     string s;
     int s1, s2;
     cout<< lvl << "Level High Scores: \r\n" << endl;
     cout<< "Name" <<setw(25)<<"Score"<<setw(25)<<"Total Time Taken"<<endl;
     cout<< "_________________________________________________________"<<endl;
     while ( score_ifile >> s ){
           s1 = s.find(':');
           s2 = s.rfind(':');
     cout<< s.substr(0,s1) <<setw(20)<<s.substr(s1+1,(s2-s1)-1)<<setw(20)<<s.substr(s2+1)<<endl; 
     }   
}
string upperCase(string txt){
       int ln = txt.length();
       for(int i = 0; i < ln; i++){
             txt[i] = toupper(txt[i]);              
       }
      return txt;
}
string twistWord(string txt){
       int as, ln = txt.length();
       if(ln<=4){
               txt[rand()% ln] = '-';
               txt[rand()% ln] = '-';
       }else if (ln<=6){
                txt[rand()%ln] = '-';
               txt[rand() % ln] = '-';
               txt[rand() % ln] = '-';
       }else{
             txt[rand() % ln] = '-';
             txt[rand() % ln] = '-';
             txt[rand() % ln] = '-';
             txt[rand() % ln] = '-';
             txt[rand() % ln] = '-';
       }
      return txt;
}

void gameon(){
    try{int lives=3;
     int time_allowed = 20;
     int marks = 0;
     int chances = 0;
     int num_chars, word_count = 0;
     int num_q;     
     
     string guess, word, twisted_word, txtfile, ain, wordlist[100];
     
      ifstream word_file;
     if(choice == 1){
          num_q = 10;
           word_file.open("beg.txt");
     }else if(choice == 2){
           num_q = 15;
            word_file.open("ave.txt");
     }else{
           num_q = 20;
            word_file.open("adv.txt");
     }
       while( word_file >> ain ){
               
             wordlist[word_count] = ain;
                word_count++;
       }
     if(word_count > 0){
    
		 for(int i = 0; i < num_q; i++){
if(lives>=1){      
	        word = wordlist[rand() % word_count];
                 twisted_word = twistWord(word);
                 num_chars = word.length();
                 cout << "Chances: " << chances << setw(30)  << "Marks Obatained: " << marks << setw(15) << "Time allowed: " << time_allowed <<" Seconds"<<endl;
                 cout << setw(40) << twisted_word << endl;
                 cout << "Total Characters: " << num_chars;
                 start = time(0);
                 cout << "Your Guess : ";
                 cin >> guess;
                 end = time(0);
                 diff = end - start;
                 total_time = total_time + diff;
                 if (diff <= time_allowed){
                     if (upperCase(guess).compare(upperCase(word)) == 0){
                           cout <<"Good! You spent "<< diff <<" seconds"<<endl;
                           marks++;
                     }else{
                           cout << "Wrong! You spent "<< diff << " seconds"<<endl;
                    lives--;
					cout<<"LIVES:"<<lives; }
                 }else if(diff>20||lives==0){
                       	   	   	   	   	   	   break;
				 }
         }}
         if(diff>20||lives==0){
         cout<< setw(20) << "time exceed\n"<<endl;
         cout<< setw(15) << "You spent a total of "<<total_time<< " seconds and you scored "<<marks<<" points."<<endl;
         }
         else
		 {
         cout<< setw(20) << "you have spent alloted time to play the game\n"<<endl;
         cout<< setw(15) << "You spent a total of "<<total_time<< " seconds and you scored "<<marks<<" points."<<endl;
         }
         
         
         ofstream score_file;
         if(choice == 1){
             
               score_file.open("beg-score.txt",ios::app);
         }else if(choice == 2){
              
                score_file.open("ave-score.txt",ios::app);
         }else{
              
                score_file.open("adv-score.txt",ios::app);
         }
         
         score_file << gamer_name << ":"<< marks << ":"<< total_time <<endl;
     }else{  
             cout<<" **** Unable to load game data, please verify they exist and populate with data"<<endl;
      }
     
}     } 



int main(int argc, char *argv[])
{
   bool again = true;
   char ans;
    cout<<"What is your name? ";
    cin>>gamer_name;
    while(again != false){
        level();
           highscore();
        gameon();
        cout<<"\r\n\r\n  Do you want to try again ? [y or n] : ";
        cin>>ans;
        if(ans == 'n')
               again = false;
               
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}



