//This includes the class and methods for the scoreboard.
//Also includes the custom layouts for each menu.

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Team.h"
#include <iomanip> 
#include <unistd.h> //for sleep command

class Scoreboard
{
  private:
    Team t1;
    Team t2;
    bool poss;
    int quarter; // period/ quarter the teams are on.
    int down;
    int toGo;
  public:
    Scoreboard()
    {
      poss = true; // if true then home, false is visitor.
      quarter = 1; // start at the first quarter.
      down = 1; // start at the first down
      toGo = 10; // starts by teams needing 10 yards for 1st down.
    }

    //setters
    void setTeam1(Team tm1)
    {
      t1 = tm1;
    }

    void setTeam2(Team tm2)
    {
      t2 = tm2;
    }

    void setPoss(bool p)
    {
      poss = p;
    }

    void setQuartet(int q)
    {
      quarter = q;
    }

    void setDown(int d)
    {
      down = d;
    }

    void setToGO(int tg)
    {
      toGo = tg;
    }
    //getters
    Team getTeam1() const
    {
      return t1;
    }
    
    Team getTeam2() const
    {
      return t2;
    }

    bool getPoss() const
    {
      return poss;
    }

    int getQuarter() const
    {
      return quarter;
    }

    int getDown() const
    {
      return down;
    }
    
    int getToGo() const
    {
      return toGo;
    }
// DONE WITH SETTERS AND GETTERS THESE METHODS ARE THE LOOKS

void scoreboardGUI() // main interface. The main scoreboard interface.
{
  //top underline
  cout << " ____________________________________________________" << endl; 
  //2nd line of scoreboard
  cout << "|HOME " << t1.getHomeCity() << "\t\t\t\t | \t\t\t\tVISITORS " << t2.getHomeCity() << " |" << endl; 
  //third line
  cout << "|" << t1.getName() << setw(39) << t2.getName() << "|" <<endl;
  //fourth line
  cout << "|____________________________________________________|" << endl;
  //fifth line score
  cout << "|" << setw(10) << "SCORE" << setw(35) << "SCORE" << setw(8) << "|" << endl;
  //sixth line score
  cout << "|" << setw(5) << t1.getScore() << setw(44) << t2.getScore() << "   |" << endl;
  //seventh line possesion
  cout << "|" <<setw(31) << "POSSESION " << setw(22) << "|" << endl;
  //line 8 ball shape to show possesion.
  if(poss == true)
      {
        cout << "| Ball: <(--)>" << setw(40) << "|" << endl;
      }
      else
      {
        cout << "|" << setw(52) << "Ball: <(--)>" << "|" << endl;
      }
  //line 9
  cout << "|____________________________________________________|" << endl;
  //line 10 QTR line
  cout << "|" << setw(25) << "QTR: " << getQuarter() << setw(27) << "|" << endl;
  //line 11 down and toGo and timeouts
  //line 12
  cout << "|" << setw(53) << "|" << endl;
  //line 13
  cout << "| TOL: " << t1.getTimeoutCount() << setw(14) << "DOWN: " << getDown() << setw(14) << "TO GO: " << getToGo() << setw(13) << "TOL: " << t2.getTimeoutCount() << "|" << endl;
  //line 14
  cout << "|____________________________________________________|" << endl;


}//end of the scoreboardGUI method

void sbEditMenu()
{
  cout << "\n|" << "SCOREBOARD OPTIONS";
  cout << "\n|\t\t\t\t\t\t   |";
  cout << "\n|" << " 1.A - Down              " << " |";
  cout << "\n|" << " 1.B - To Go             " << " |";
  cout << "\n|" << " 1.C - Possession        " << " |";
  cout << "\n|" << " 1.D - Quarter           " << " |";
  cout << "\n|" << " 1.X - Exit Program      " << " |";
  cout << "\n|__________________________|";

  cout << "\n|" << "HOME TEAM OPTIONS";
  cout << "\n|\t\t\t\t\t\t   |";
  cout << "\n|" << " 2.A - Team Name         " << " |";
  cout << "\n|" << " 2.B - Home City         " << " |";
  cout << "\n|" << " 2.C - Score             " << " |";
  cout << "\n|" << " 2.D - Timeout Count     " << " |";
  cout << "\n|" << " 2.E - Coach Name        " << " |";
  cout << "\n|__________________________|";

  cout << "\n|" << "VISITING TEAM OPTIONS";
  cout << "\n|\t\t\t\t\t\t   |";
  cout << "\n|" << " 3.A - Team Name         " << " |";
  cout << "\n|" << " 3.B - Home City         " << " |";
  cout << "\n|" << " 3.C - Score             " << " |";
  cout << "\n|" << " 3.D - Timeout Count     " << " |";
  cout << "\n|" << " 3.E - Coach Name        " << " |";
  cout << "\n|__________________________|" << endl;
}// end of sbEditMenu method

void scoreboardOption()
{
  string decision = "";
  int downC = -1;// ended up using this as a generic variable for all else if
  //dont mind the naming being downC... got lazy to change it to an actual generic name.
  sbEditMenu();
  //do all of this unless exit program
  do
  {
      system("clear");
      scoreboardGUI();
      sbEditMenu();
      cout << "Choose an option to change >";
      validateString(decision);
    
    //to exit program
    if(decision == "1.x" || decision == "1.X" || decision == "1x" || decision == "1X")
    {
      system("clear");
      scoreboardGUI();
      sbEditMenu();
    }
    //this is for updating DOWN
      else if(decision == "1.a" || decision == "1.A" || decision == "1a" || decision == "1A")
        {//start of if for what is down
          do
          {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          
          cout << "What is the Down? >";
          validateInt(downC);
            if(downC > 0 && downC < 5)
            {
              setDown(downC);
            }
            else
            {
              system("clear"); //clear the screen
              scoreboardGUI();
              sbEditMenu();

              cout << "Down must be an integer between 1-4.";
              cin.ignore(10000, '\n');
            }
          }while(downC >=5 || downC <= 0); // end of dowhile for entering a down
        }//end of if for what is down.
    
    //this is for updating TOGO
      else if(decision == "1.b" || decision == "1.B" || decision == "1b" || decision == "1B")
        {//start of end if for toGO
          do 
          {
            //making sure screen looks good
            system("clear");
            scoreboardGUI();
            sbEditMenu();
            //code for updating toGo
            downC = 0;
            cout << "What is the number of yards TOGO? >";
            validateInt(downC);
            
              if(downC < 100 && downC >= 0)
              {
                setToGO(downC);
              }
              else
              {
                system("clear");
                scoreboardGUI();
                sbEditMenu();
                cout << "Invalid input, enter number of yards between 0-99: ";
                cin.ignore(1000, '\n');
              }
          }while(downC >= 100 || downC <= 0);
        }//end of end if for toGo

      //else if for Possession  
        else if(decision == "1c" || decision == "1C" || decision == "1.c" || decision == "1.C")
        {//start of else if for possesion
           //making sure screen looks good
          do 
          {
            system("clear");
            scoreboardGUI();
            sbEditMenu();
            //code for updating poss
            downC = 0;
            cout << "Who has ball possesion?(1 for Home, 0 for Away) >";
            validateInt(downC);

         
            if(downC == 1)
            {
              setPoss(downC);
            }
            else if(downC == 0)
            {
              setPoss(downC);
            }
            else
            {
              system("clear");
              scoreboardGUI();
              sbEditMenu();
              cout << "Invalid input, only two teams for who has possesion,";
              cin.ignore(1000, '\n');
            }
          }while(downC != 1 && downC != 0);
        }//end of else if for poss

      //else if for Quarter
      else if(decision == "1d" || decision == "1D" || decision == "1.d" || decision == "1.D")
      {
        do
        {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          //code for updating poss
          downC = 0;
          cout << "What Quarter is it? >";
          validateInt(downC);

          if(downC == 1)
          {
            setQuartet(downC);
          }
          else if(downC == 2)
          {
            setQuartet(downC);
          }
          else if(downC == 3)
          {
            setQuartet(downC);
          }
          else if(downC == 4)
          {
            setQuartet(downC);
          }
          else
          {
            system("clear");
            scoreboardGUI();
            sbEditMenu();
            cout << "Invalid input, only 4 Quarters. Enter integer from 1-4";
            cin.ignore(1000, '\n');
          }
        }while(downC <= 0 || downC >= 5);//end of while for quarter
      }//end of else if for quarter

      //else if for the Home Team Name
      else if(decision == "2a" || decision == "2A" || decision == "2.a" || decision == "2.A")
      {
        system("clear");
        scoreboardGUI();
        sbEditMenu();
        string userTeam = "";
        
        cout << "Please enter the updated Home Team Name: ";
        validateString(userTeam);
        t1.setName(userTeam);
      }//end else if for Team name

      //else if for the Home City Name
      //fix to only allow users to put in 3 letters and no more.
      else if(decision == "2b" || decision == "2B" || decision == "2.b" || decision == "2.B")
      {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          string homeCityName = "";
          
          cout << "Please enter the updated Home City Abreviation(Only 3 letters) : ";
          validateString(homeCityName);
          t1.setHomeCity(homeCityName);
      }//end else if for Home City name

      //else if for score
      else if(decision == "2c" || decision == "2C" || decision == "2.c" || decision == "2.C")
      {
        do
        {
        system("clear");  
        scoreboardGUI();
        sbEditMenu();
        
        cout << "Please enter the score for team 1: ";
        validateInt(downC);
        if(downC >= 0 && downC < 100)
        {
          t1.setScore(downC);
        }
        else
        {
          system("clear");  
          scoreboardGUI();
          sbEditMenu();   

          cout << "Invalid input, enter points from 0-99";
          cin.ignore(1000, '\n');
        }
        }while(downC >= 100 || downC < 0 );
      }//end else if for score

      //this is for updating Timeout Count
      else if(decision == "2.d" || decision == "2.D" || decision == "2d" || decision == "2D")
        {//start of if for what is TimeoutCount
          do
          {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          
          cout << "How many timeouts does the home team have? >";
          validateInt(downC);

            if(downC >= 0 && downC < 4)
            {
              t1.setTimeoutCount(downC);
            }
            else
            {
              system("clear"); //clear the screen
              scoreboardGUI();
              sbEditMenu();

              cout << "TOL must be an integer between 1-3.";
              cin.ignore(10000, '\n');
            }
          }while(downC >=3 || downC <= 0); // end of dowhile for entering a down
        }//end of else if for timeout count

        //else if for coach name
        else if(decision == "2.e" || decision == "2.E" || decision == "2e" || decision == "2E")
        {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          string userCoach = "";

          cout << "Enter the home team coach name: ";
          userCoach = validateString(userCoach);
          t1.setCoachName(userCoach);
        }//end of else if for coach name

  //VISITING TEAM *********************************** SAME BUT NOW GOTTA DO t2. 
    
      //else if for the Home Team Name
      else if(decision == "3a" || decision == "3A" || decision == "3.a" || decision == "3.A")
      {
        system("clear");
        scoreboardGUI();
        sbEditMenu();
        string userTeam = "";
        
        cout << "Please enter the updated Visiting Team Name: ";
        validateString(userTeam);
        t2.setName(userTeam);
      }//end else if for Team name

      //else if for the Home City Name
      //fix to only allow users to put in 3 letters and no more.
      else if(decision == "3b" || decision == "3B" || decision == "3.b" || decision == "3.B")
      {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          string homeCityName = "";
          
          cout << "Please enter the updated Visiting City Abreviation(Only 3 letters) : ";
          validateString(homeCityName);
          t2.setHomeCity(homeCityName);
      }//end else if for Home City name

      //else if for score
      else if(decision == "3c" || decision == "3C" || decision == "3.c" || decision == "3.C")
      {
        do
        {
        system("clear");  
        scoreboardGUI();
        sbEditMenu();
        
        cout << "Please enter the score for team 2: ";
        validateInt(downC);
        if(downC >= 0 && downC < 100)
        {
          t2.setScore(downC);
        }
        else
        {
          system("clear");  
          scoreboardGUI();
          sbEditMenu();   

          cout << "Invalid input, enter points from 0-99";
          cin.ignore(1000, '\n');
        }
        }while(downC >= 100 || downC < 0 );
      }//end else if for score

      //this is for updating Timeout Count
      else if(decision == "3.d" || decision == "3.D" || decision == "3d" || decision == "3D")
        {//start of if for what is TimeoutCount
          do
          {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          
          cout << "How many timeouts does the Away team have? >";
          validateInt(downC);

            if(downC >= 0 && downC < 4)
            {
              t2.setTimeoutCount(downC);
            }
            else
            {
              system("clear"); //clear the screen
              scoreboardGUI();
              sbEditMenu();

              cout << "TOL must be an integer between 1-3.";
              cin.ignore(10000, '\n');
            }
          }while(downC >=3 || downC <= 0); // end of dowhile for entering a down
        }//end of else if for timeout count

        //else if for coach name
        else if(decision == "3.e" || decision == "3.E" || decision == "3e" || decision == "3E")
        {
          system("clear");
          scoreboardGUI();
          sbEditMenu();
          string userCoach = "";

          cout << "Enter the visting team coach name: ";
          userCoach = validateString(userCoach);
          t2.setCoachName(userCoach);
        }//end of else if for coach name
  }while(decision != "x" || decision != "x"); // end of program
}// end of scoreboardOption method





};
#endif
