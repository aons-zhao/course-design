#include "TechnicalStaff.h"


TechnicalStaff::TechnicalStaff() {
    this->staffDutyType = 1;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setStaffGrade();
    setTechnicalField();
    setTechnicaDevote();
}

void TechnicalStaff::setTechnicalField() {
    cout << "��������:";
    cin >> this->technology;
}

string TechnicalStaff::getTechnicalField() const {
    return this->technology;
}

void TechnicalStaff::setTechnicaDevote() {
    cout << "��������:";
    cin >> this->devote;
}

string TechnicalStaff::gettechnicaDevote() const {
    return this->devote;
}

TechnicalStaff::~TechnicalStaff() {
}

void TechnicalStaff::showInfos() {
    cout << "\n\"----------------��������Ա��Ϣ��------------------------" << endl;
    cout << "����:" << getStaffNumber() << endl;
    cout << "����:" << getStaffName() << endl;
    cout << "�Ա�:" << getStaffSex() << endl;
    cout << "����:" << getWorkYears() << endl;
    cout << "����:" << getStaffSalary() << endl;
    cout << "�ȼ�:" << getStaffGrade() << endl;
    cout << "��������:" << getTechnicalField() << endl;
    cout << "��������:" << gettechnicaDevote() << endl;
    cout << "-------------------------------------------------------\n" << endl;
}
