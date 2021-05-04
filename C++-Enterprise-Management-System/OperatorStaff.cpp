#include "OperatorStaff.h"

OperatorStaff::OperatorStaff() {
    this->staffDutyType = 4;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setStaffGrade();
    setResolveFailureRate();
    setWorkEfficiency();
    setProjectCompletion();
}

OperatorStaff::~OperatorStaff() {
}

void OperatorStaff::setResolveFailureRate() {
    cout << "���Ͻ����:";
    cin >> this->resolveFailureRate;
}

int OperatorStaff::getResolveFailureRate() const {
    return this->resolveFailureRate;
}

void OperatorStaff::setWorkEfficiency() {
    cout << "����Ч��:";
    cin >> this->workEfficiency;
}

int OperatorStaff::getWorkEfficiency() const {
    return this->workEfficiency;
}

void OperatorStaff::setProjectCompletion() {
    cout << "������Ŀ�����:";
    cin >> this->projectCompletion;
}

int OperatorStaff::getProjectCompletion() const {
    return this->projectCompletion;
}

void OperatorStaff::showInfos() {
    cout << "\n\"----------------��������Ա��Ϣ��------------------------" << endl;
    cout << "����:" << getStaffNumber() << endl;
    cout << "����:" << getStaffName() << endl;
    cout << "�Ա�:" << getStaffSex() << endl;
    cout << "����" << getWorkYears() << endl;
    cout << "����" << getStaffSalary() << endl;
    cout << "�ȼ�:" << getStaffGrade() << endl;
    cout << "���Ͻ����:" << getResolveFailureRate() << endl;
    cout << "����Ч��:" << getWorkEfficiency() << endl;
    cout << "������Ŀ�����:" << getProjectCompletion() << endl;
    cout << "--------------------------------------------------------\n" << endl;
}
