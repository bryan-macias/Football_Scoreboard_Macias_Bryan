//Class for the teams. 

#ifndef TEAM_H
#define TEAM_H

#include "Input_Validation_Extended.h"

class Team
{
  private:
    string name; // team name
    string coachName;
    string homeCity;
    bool homeStatus;
    int score;
    int timeoutCount;
  public:
    Team()
    {
      name = "*************"; //default team name set to * then can change them to name when inputted.
      coachName = "Default Coach Name";
      homeCity = "***"; //default name for city abbreviation.
      homeStatus = true; // if true home, if false visitor.
      score = 0;
      timeoutCount = 3; // start with 3 time outs.
    }

  // setters
    void setName(string n)
    {
      name = n;
    }

    void setCoachName(string coachN)
    {
      coachName = coachN;
    }

    void setHomeCity(string homeC)
    {
      homeCity = homeC;
    }

    void setHomeStatus(bool homeS)
    {
      homeStatus = homeS;
    }

    void setScore(int s)
    {
      score = s;
    }

    void setTimeoutCount(int timeoutC)
    {
      timeoutCount = timeoutC;
    }
  //Getters
    string getName() const
    {
      return name;
    }
    string getCoachName() const
    {
      return coachName;
    }
    string getHomeCity() const
    {
      return homeCity;
    }
    bool getHomeStatus() const
    {
      return homeStatus;
    }
    int getScore() const
    {
      return score;
    }
    int getTimeoutCount() const
    {
      return timeoutCount;
    }
};
#endif