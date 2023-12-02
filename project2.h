#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Population;

class Employment
{
private:
    int year = 0;
    string SUNY_inst = "";
    string sector = "";
    int total_empl = 0;
    int scoreEmployment = 0;
    int employmentChange = 0;

public:
    Employment(int Year, string SUNY_I, string Sector, int Total_empl);
    void display_Employment();
    int getYear();
    string getInst();
    string getSector();
    int getEmpNum();
    int getScore();
    void setScoreEmployment(int Ss);
    void setEmploymentChange(int v);
    int getEmploymentChange();
};

class Population
{
private:
    int yearP = 0;
    int ageG = 0;
    string ageD = "";
    int genCode = 0;
    string genD = "";
    int raceCode = 0;
    string raceD = "";
    int countyCode = 0;
    string countyName = "";
    int popuNum = 0;
    int scorePopulation = 0;
    int popuChange = 0;

public:
    Population(int yearp, int ageg, string aged, int gencode, string gend, int racecode, string raced, int countcode, string countyname, int popunum);
    void displayPopulation();
    int getYearP();
    void setScorePopulation(int Sp);
    int getAge();
    int getGenCode();
    int getRaceCode();
    int getPopuNum();
    int getScore();
    int getCountyCode();
    void setPopuChange(int val);
    int getPopuChange();
};
