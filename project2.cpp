#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "project2.h"

using namespace std;

void initialize_Employment();
void initialize_Population();
void createUnion(Population *po);
void employmentScore(Employment *em);
void populationScore(Population *pp);
void createUnion(Population *po);

// creating a vector to stor each row
vector<Employment *> employmentVec;
vector<Employment *> employmentUnion;
vector<Population *> populations;
vector<Population *> populationUnion;

vector<int> popuNums;

Employment::Employment(int Year, string SUNY_I, string Sector, int Total_empl)
{
    year = Year;
    SUNY_inst = SUNY_I;
    sector = Sector;
    total_empl = Total_empl;
}
void Employment::display_Employment()
{
    cout << "Year : " << year << endl;
    cout << "SUNY_inst : " << SUNY_inst << endl;
    cout << "sector : " << sector << endl;
    cout << "total_empl : " << total_empl << endl;
    cout << "Score : " << scoreEmployment << endl
         << endl;
}
int Employment::getYear() { return year; }
string Employment::getSector() { return sector; }
string Employment::getInst() { return SUNY_inst; }
int Employment::getEmpNum() { return total_empl; }
int Employment::getScore() { return scoreEmployment; }
void Employment::setScoreEmployment(int Ss) { scoreEmployment = Ss; }
void Employment::setEmploymentChange(int v) { employmentChange = v; }
int Employment::getEmploymentChange() { return employmentChange; }

Population::Population(int yearp, int ageg, string aged, int gencode, string gend, int racecode, string raced, int countycode, string countyname, int popunum)
{
    yearP = yearp;
    ageG = ageg;
    ageD = aged;
    genCode = gencode;
    genD = gend;
    raceCode = racecode;
    raceD = raced;
    countyCode = countycode;
    countyName = countyname;
    popuNum = popunum;
}
void Population::displayPopulation()
{
    cout << "Year : " << yearP << endl;
    cout << "race discription : " << raceD << endl;
    cout << "gender discription: " << genD << endl;
    cout << "countyName : " << countyName << endl;
    cout << "popuNum : " << popuNum << endl;
    cout << "Score : " << scorePopulation << endl
         << endl;
}
int Population::getYearP() { return yearP; }
void Population::setScorePopulation(int Sp) { scorePopulation = Sp; }
int Population::getAge() { return ageG; }
int Population::getGenCode() { return genCode; }
int Population::getRaceCode() { return raceCode; }
int Population::getPopuNum() { return popuNum; }
int Population::getScore() { return scorePopulation; }
int Population::getCountyCode() { return countyCode; }
void Population::setPopuChange(int val) { popuChange = val; }
int Population::getPopuChange() { return popuChange; }

void initialize_Employment()
{

    ifstream infile; // infile.open("input.txt")
    infile.open("State_University_of_New_York__SUNY__Employees_By_Employment_Status__Beginning_Fall_2011.csv");
    if (infile.fail())
        cout << "The file dosn't exist." << endl;
    else
    {
        string line = "";
        getline(infile, line); // to get raid of the first line
        line = "";

        // Stating each column
        int year = 0;
        string SUNY_inst = "";
        string sector = "";
        int total_empl = 0;
        string temp_string = "";
        string last = "";

        while (getline(infile, line))
        {
            stringstream inputS(line);
            getline(inputS, temp_string, ',');
            year = atoi(temp_string.c_str());
            temp_string = "";

            getline(inputS, SUNY_inst, ',');
            getline(inputS, sector, ',');

            getline(inputS, temp_string, ',');

            if (temp_string.length() == 2)
            {
                getline(inputS, last, ',');
                temp_string = (temp_string + last).substr(1, 4);
            }
            total_empl = atoi(temp_string.c_str());
            // cout << total_empl << endl;
            temp_string = "";

            // creating a class with the date from each row
            Employment e(year, SUNY_inst, sector, total_empl);
            // and pushing its pointer to a vector
            employmentVec.push_back(&e);
            employmentScore(&e);
            // cout << e.getSector() << endl;
            // employmentVec.clear();
            line = "";
        }
        vector<Employment *>::iterator it = employmentVec.begin();
        while (it != employmentVec.end())
        {
            (*it)->display_Employment();
            break;
        }
    }
    infile.close();
}

void initialize_Population()
{
    ifstream infile; // infile.open("input.txt")
    infile.open("New_York_State_Population_Data__Beginning_2003.csv");
    if (infile.fail())
        cout << "The file dosn't exist." << endl;
    else
    {
        string lineP = "";
        getline(infile, lineP); // to get raid of the first line
        lineP = "";

        // stating each column
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
        string tempString = "";
        string end = "";

        int i = 2;
        while (getline(infile, lineP))
        {
            tempString = "";
            stringstream inputString(lineP);
            getline(inputString, tempString, ',');
            yearP = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, tempString, ',');
            ageG = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, ageD, ',');

            getline(inputString, tempString, ',');
            genCode = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, genD, ',');

            getline(inputString, tempString, ',');
            raceCode = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, raceD, ',');

            getline(inputString, tempString, ',');
            countyCode = atoi(tempString.c_str());
            tempString = "";

            getline(inputString, countyName, ',');

            getline(inputString, tempString, ' ');
            popuNum = atoi(tempString.c_str());

            Population p(yearP, ageG, ageD, genCode, genD, raceCode, raceD, countyCode, countyName, popuNum);

            populations.push_back(&p);
            populationScore(&p);
            i++;

            lineP = "";
        }

        vector<Population *>::iterator it = populations.begin();
        while (it != populations.end())
        {
            (*it)->displayPopulation();
            break;
        }
    }
    infile.close();
    // cout << j << endl;
}

int yearScore = 0;
int prevNum = 0;
int maxE = 0;
Employment *ME;
void employmentScore(Employment *em)
{
    // recency of the data - out of 100
    yearScore = 100 - (2022 - (*em).getYear());
    (*em).setScoreEmployment(yearScore);

    /*Sector - out of 10
    SUNY system = 4
    Doctrial Institution = 10
    Comprehensive colleges = 8
    Technology colleges = 2
    Community colleges = 6
    */
    //
    if (((*em).getSector()).compare("Community Colleges") == 0)
        (*em).setScoreEmployment(6 + (*em).getScore());
    else if (((*em).getSector()).compare("Technology Colleges") == 0)
        (*em).setScoreEmployment(2 + (*em).getScore());
    else if (((*em).getSector()).compare("Comprehensive Colleges") == 0)
        (*em).setScoreEmployment(8 + (*em).getScore());
    else if (((*em).getSector()).compare("Doctoral Institutions") == 0)
        (*em).setScoreEmployment(10 + (*em).getScore());
    else
        (*em).setScoreEmployment(4 + (*em).getScore());

    //% of change
    if ((*em).getYear() != 2000)
    {
        (*em).setEmploymentChange((((*em).getEmpNum() - prevNum) % 10) * (-1));
        // cout << (*em).getYear() << " --- " << (*em).getSector() << " --- " << (*em).getEmploymentChange() << endl;
        (*em).setScoreEmployment((*em).getScore() + (*em).getEmploymentChange()); // between 0 and 10
        prevNum = (*em).getEmpNum();
    }
    else
    {
        // cout << (*em).getYear() << " " << (*em).getSector() << endl;
        prevNum = (*em).getEmpNum();
    }
    if (maxE < (*em).getScore())
    {
        maxE = (*em).getScore();
        ME = em;
    }
}

int yearScoreP = 0;
int prevYear = 2003;
// variabble for the Scoring algorithms
float total = 0;
float whitePopu = 0;
float blackPopu = 0;
float othersPopu = 0;
float hispanicPopu = 0;

float totalMale = 0;
float whiteMale = 0;
float blackmale = 0;
float othersMale = 0;
float hispanicMale = 0;

float totalFemale = 0;
float whiteFemale = 0;
float blackFemale = 0;
float othersFemale = 0;
float hispanicFemale = 0;

int maxP = 0;
int j = 0;
Population *PP;
void populationScore(Population *pp)
{
    // recency of the data
    yearScoreP = 90 - (2022 - (*pp).getYearP());
    (*pp).setScorePopulation(yearScoreP);

    //% of change = out of 10
    if ((*pp).getYearP() != 2003)
    {
        if (((*pp).getAge() == 0) && ((*pp).getGenCode() == 0) && ((*pp).getRaceCode() == 0))
        {
            // createUnion(pp);

            (*pp).setPopuChange(((*pp).getPopuNum() - popuNums.at((*pp).getCountyCode() - 1)) % 10);
            // cout << "here " << (*pp).getYearP() << " ^^^^ " << (*pp).getPopuChange() << endl;
            (*pp).setScorePopulation((*pp).getScore() + ((*pp).getPopuChange())); // between 0 and 10
            popuNums[((*pp).getCountyCode() - 1)] = (*pp).getPopuNum();
        }
    }
    else
    {
        popuNums.push_back((*pp).getPopuNum());
    }

    // Score based on Female/total, Male/total; white/total, black/total, others/total, hispanic/total; and their combinations.
    if (((*pp).getYearP() == prevYear))
    {
        if (((*pp).getAge() == 0))
        {
            if (((*pp).getGenCode() == 0) && ((*pp).getRaceCode() == 0))
            {
                total = (*pp).getPopuNum();
                // cout << "Total" << endl;
            }
            else if (((*pp).getGenCode() == 0) && ((*pp).getRaceCode() == 1))
            {
                whitePopu = (*pp).getPopuNum() / total;
                // cout << "White : " << whitePopu << endl;
            }
            else if (((*pp).getGenCode() == 0) && ((*pp).getRaceCode() == 2))
            {
                blackPopu = (*pp).getPopuNum() / total;
                // cout << "Black" << endl;
            }
            else if (((*pp).getGenCode() == 0) && ((*pp).getRaceCode() == 3))
            {
                othersPopu = (*pp).getPopuNum() / total;
                // cout << "Others" << endl;
            }
            else if (((*pp).getGenCode() == 0) && ((*pp).getRaceCode() == 5))
            {
                hispanicPopu = (*pp).getPopuNum() / total;
                // cout << "Hispanic" << endl;
            }
            else if (((*pp).getGenCode() == 1) && ((*pp).getRaceCode() == 0))
            {
                totalMale = (*pp).getPopuNum();
                // cout << "Total Male" << endl;
            }
            else if (((*pp).getGenCode() == 1) && ((*pp).getRaceCode() == 1))
            {
                whiteMale = (*pp).getPopuNum() / totalMale;
                if ((whiteMale / whitePopu) >= 0.99)
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                // cout << "White Male : " << whiteMale << " " << whitePopu << endl;
            }
            else if (((*pp).getGenCode() == 1) && ((*pp).getRaceCode() == 2))
            {
                blackmale = (*pp).getPopuNum() / totalMale;
                if ((blackmale / blackPopu) >= 0.99)
                {
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                    // cout << "Black Male : " << blackmale << " " << blackPopu << endl;
                }
            }
            else if (((*pp).getGenCode() == 1) && ((*pp).getRaceCode() == 3))
            {
                othersMale = (*pp).getPopuNum() / totalMale;
                if ((othersMale / othersPopu) >= 0.99)
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                // cout << "Other Male" << endl;
            }
            else if (((*pp).getGenCode() == 1) && ((*pp).getRaceCode() == 5))
            {
                hispanicMale = (*pp).getPopuNum() / totalMale;
                if ((hispanicMale / hispanicPopu) > 0.99)
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                // cout << "Hispanic Male" << endl;
            }
            else if (((*pp).getGenCode() == 2) && ((*pp).getRaceCode() == 0))
            {
                totalFemale = (*pp).getPopuNum();
                // cout << "Total Female" << endl;
            }
            else if (((*pp).getGenCode() == 2) && ((*pp).getRaceCode() == 1))
            {
                whiteFemale = (*pp).getPopuNum() / totalFemale;
                if ((whiteFemale / whitePopu) > 0.99)
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                // cout << "White Female" << endl;
            }
            else if (((*pp).getGenCode() == 2) && ((*pp).getRaceCode() == 2))
            {
                blackFemale = (*pp).getPopuNum() / totalFemale;
                if ((blackFemale / blackPopu) > 0.99)
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                // cout << "Black Female" << endl;
            }
            else if (((*pp).getGenCode() == 2) && ((*pp).getRaceCode() == 3))
            {
                othersFemale = (*pp).getPopuNum() / totalFemale;
                if ((othersFemale / othersPopu) >= 0.99)
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                // cout << "Other Female" << endl;
            }
            else if (((*pp).getGenCode() == 2) && ((*pp).getRaceCode() == 5))
            {
                hispanicFemale = (*pp).getPopuNum() / totalFemale;
                if ((hispanicFemale / hispanicPopu) >= 0.99)
                    (*pp).setScorePopulation((*pp).getScore() + 10);
                // cout << "Hispanic Female" << endl;
            }
        }
        else
            prevYear = (*pp).getYearP();

        if (maxP < (*pp).getScore())
        {
            maxP = (*pp).getScore();
            PP = pp;
        }
    }
}
void createUnion(Population *po)
{
    vector<Employment *>::iterator it = employmentVec.begin();
    while (it != employmentVec.end())
    {
        if ((*it)->getYear() == (*po).getYearP())
        {
            employmentUnion.push_back(*it);
            populationUnion.push_back(po);
            if ((*it)->getEmploymentChange() > (*po).getPopuChange())
            {
                (*it)->setScoreEmployment((*it)->getScore() + 10);
            }
            break;
        }
    }
}
bool diffE(Employment *a, Employment *b)
{
    return ((*a).getScore() > (*b).getScore());
}

bool diffP(Population *a, Population *b)
{
    return ((*a).getScore() > (*b).getScore());
}
void sortClass()
{
    sort(employmentVec.begin(), employmentVec.end(), diffE);
    sort(employmentUnion.begin(), employmentUnion.end(), diffE);
    sort(populations.begin(), populations.end(), diffP);
    sort(populationUnion.begin(), populationUnion.end(), diffP);
}

void writeResult()
{
    ofstream result, hold;
    result.open("Result.txt");

    string intro = "The main objective of our project is to determine whether the rate of employe employment in SUNY Colleges is directly/indirectly proportional to the rate of population in New York County.\n\nUsing different scoring algorithms, we will be able deduce if the increased/decreased rate of population in New York County is increasing/decreasing the rate of employment in SUNY schools.\n\nTherefore, our project tries to see if there is a correlation between New York\'s population to all SUNY colleges employe enrolment. \n\nDoes the increase in No.of population increase or decrease the No.of employment? is our project question.";
    string data = "\n\nThe two data sets we are using for the project: \nState University of New York (SUNY) Employees By Employment Status: Beginning Fall 2011 | State of New York , this is the database we are using for employees in SUNY schools.\n\nNew York State Population Data: Beginning 2003 | State of New York (ny.gov), this the database we are using for population in New York county particular of race.";
    string link = "If you would like to know more about our project folllow this link: \n\nhttps://docs.google.com/presentation/d/1sgJ1jRHt-9a6Slc9bzmawhpeD_wKOqngP-XmOZimdP0/edit#slide=id.g1a656a221a6_0_5";
    result << intro;
    result << data;
    result << link;
}
int main()
{

    initialize_Employment();
    initialize_Population();
    writeResult();

    return 0;
}
