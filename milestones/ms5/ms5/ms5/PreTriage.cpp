/* Citation and Sources...
 Final Project Milestone 5
 Module: PreTriage
 Filename: PreTriage.cpp
 Version 1.0
 Author    Dhruv Bipinbhai Patel
 Revision History
 -----------------------------------------------------------
 Date        Reason
 2020/11/11  Preliminary release
 2020/11/11  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------*/

#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
#include <iostream>
#include <cstring>
#include<fstream>
using namespace std;
namespace sdds{

PreTriage::PreTriage(const char* dataFilename):m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
    m_dataFilename = new char[strlen(dataFilename) + 1];
    strcpy(m_dataFilename, dataFilename);
    load();
}

PreTriage::~PreTriage(){
    ofstream dfile;
    int i;
    dfile.open(m_dataFilename);
    if(dfile.is_open()){
        for(i = 0; i < m_lineupSize; i++){
            m_lineup[i] -> fileIO(true);
            if(i == 0){
                dfile << m_averCovidWait << "," << m_averTriageWait << endl;
            }
            dfile << *m_lineup[i] << endl;
        }
        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: " << m_averCovidWait << endl;
        cout << "   Triage: " << m_averTriageWait << endl;
        cout << "Saving m_lineup..." << endl;
        for(i = 0; i < m_lineupSize; i++){
            cout << i + 1 << "- " << *m_lineup[i] << endl;
        }
        for(i = 0; i < m_lineupSize; i++){
            delete m_lineup[i];
        }
        delete [] m_dataFilename;
        cout << "done!" << endl;
    }
}

const Time PreTriage::getWaitTime(const Patient& p) const{
    int count = 0;
    for(int i = 0; i < m_lineupSize; i++){
        if(m_lineup[i]->type() == p.type()) count++;
    }
    return Time(p) *= count;
}

void PreTriage::setAverageWaitTime(const Patient& p){
    Time ct;
    ct.reset();
    if(p.type() == 'C') {
        m_averCovidWait = ((ct - p.operator Time()) + (m_averCovidWait * (p.number() - 1))) / p.number();
    }
    else if(p == 'T') {
        m_averTriageWait = ((ct - p.operator Time()) + (m_averTriageWait * (p.number() - 1))) / p.number();
    }
}

void PreTriage::removePatientFromLineup(int index){
    removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
}

int PreTriage::indexOfFirstInLine(char type) const{
    int i;
    for(i = 0; i < maxNoOfPatients; i++){
        if(m_lineup[i]->type() == type) return i;
    }
    return -1;
}

void PreTriage::load(){
    char ch;
    int count = 0;
    ifstream dfile(m_dataFilename);
    cout << "Loading data..." << endl;
    if(dfile){
        dfile >> m_averCovidWait;
        dfile.ignore(200, ',');
        dfile >> m_averTriageWait;
        dfile.ignore(200, '\n');
        while(dfile && m_lineupSize != maxNoOfPatients){
            Patient *p = nullptr;
            ch = dfile.get();
            dfile.ignore(200, ',');
            if (ch == 'C'){
                p = new CovidPatient();
                p -> fileIO(true);
                p->csvRead(dfile);
                dfile.ignore(200,'\n');
                p -> fileIO(false);
                m_lineup[count] = p;
                m_lineupSize++;
                count++;
            }
            else if (ch == 'T')
            {
                p = new TriagePatient();
                p -> fileIO(true);
                p->csvRead(dfile);
                dfile.ignore(200,'\n');
                p -> fileIO(false);
                m_lineup[count] = p;
                m_lineupSize++;
                count++;
            }
        }
    }
        if (count - maxNoOfPatients == 0)
        {
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        }
        if (count == 0)
        {
            cout << "No data or bad data file!" << endl;
        }
        else cout << count << " Records imported..." << endl;
        cout << endl;
    }
    
    void PreTriage::reg(){
        
        if(m_lineupSize == maxNoOfPatients){
            cout << "Line up full!" << endl;
        }
        else{
            int choice;
            m_pMenu >> choice;
            switch(choice){
                case 0:
                    break;
                case 1:
                    m_lineup[m_lineupSize] = new CovidPatient();
                    m_lineup[m_lineupSize]->setArrivalTime();
                    m_lineup[m_lineupSize]->fileIO(false);
                    cout << "Please enter patient information: " << endl;
                    cin >> *m_lineup[m_lineupSize];
                    cout << endl;
                    cout << "******************************************" << endl;
                    cout << *m_lineup[m_lineupSize];
                    cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                    cout << "******************************************" << endl << endl;
                    m_lineupSize++;
                    break;
                case 2:
                    m_lineup[m_lineupSize] = new TriagePatient();
                    m_lineup[m_lineupSize]->setArrivalTime();
                    m_lineup[m_lineupSize]->fileIO(false);
                    cout << "Please enter patient information: " << endl;
                    cin >> *m_lineup[m_lineupSize];
                    cout << endl;
                    cout << "******************************************" << endl;
                    cout << *m_lineup[m_lineupSize];
                    cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                    cout << "******************************************" << endl << endl;
                    m_lineupSize++;
                    break;
            }
        }
    }
    
    void PreTriage::admit(){
        int choice,index = 0;
        char ptype = '\0';
        m_pMenu >> choice;
        switch(choice){
            case 1:
                ptype = 'C';
                if(indexOfFirstInLine(ptype) == -1) return;
                else{
                    index = indexOfFirstInLine(ptype);
                    cout << endl;
                    cout << "******************************************" << endl;
                    m_lineup[index]->fileIO(false);
                    cout << "Calling for ";
                    cout << *m_lineup[indexOfFirstInLine(ptype)];
                    cout << "******************************************" << endl << endl;
                    setAverageWaitTime(*m_lineup[index]);
                    removePatientFromLineup(index);
                }
                break;
            case 2:
                ptype = 'T';
                if(indexOfFirstInLine(ptype) == -1) return;
                else{
                    index = indexOfFirstInLine(ptype);
                    cout << endl;
                    cout << "******************************************" << endl;
                    m_lineup[index]->fileIO(false);
                    cout << "Calling for ";
                    cout << *m_lineup[indexOfFirstInLine(ptype)];
                    cout << "******************************************" << endl << endl;
                    setAverageWaitTime(*m_lineup[index]);
                    removePatientFromLineup(index);
                }
                break;
            case 0:
                break;
        }
    }
    
    void PreTriage::run(){
        int selection, flag;
        do{
            flag = 1;
            m_appMenu.display();
            cin >> selection;
            switch(selection){
                case 0:
                    flag = 0;
                    break;
                case 1:
                    reg();
                    break;
                case 2:
                    admit();
                    break;
            }
        }while(flag==1);
    }
    
}
