#include "BaseStaff.h"

BaseStaff::BaseStaff() {}

BaseStaff::~BaseStaff() {}

// ���ù���
void BaseStaff::setStaffNumber() {
    cout << "-->����:";
    cin >> this->staffNumber;
}

// ��ȡ����
string BaseStaff::getStaffNumber() const {
    return this->staffNumber;
}

// ��������
void BaseStaff::setStaffName() {
    cout << "-->����:";
    cin >> this->staffName;
}

// ��ȡ����
string BaseStaff::getStaffName() const {
    return this->staffName;
}

// �����Ա�
void BaseStaff::setStaffSex() {
    cout << "-->�Ա�:";
    cin >> this->staffSex;
    while (staffSex != "��" && staffSex != "Ů") {
        cout << "�����ʽ�������������룡" << endl;
        cin.clear();
        cin >> this->staffSex;
    }
}

// ��ȡ�Ա�
string BaseStaff::getStaffSex() const {
    return this->staffSex;
}

// ���ù���
void BaseStaff::setWorkYears() {
    cout << "-->����:";
    cin >> this->staffWorkYears;
    while (staffWorkYears < 0 || staffWorkYears > 40) {
        cout << "�����ʽ�������������룡" << endl;
        cin.clear();
        cin >> this->staffWorkYears;
    }
}

// ��ȡ����
int BaseStaff::getWorkYears() const {
    return this->staffWorkYears;
}

// ���ù���
void BaseStaff::setStaffSalary() {
    cout << "-->����:";
    cin >> this->staffSalary;
}

// ��ȡ����
int BaseStaff::getStaffSalary() const {
    return this->staffSalary;
}

// ���õȼ�
void BaseStaff::setStaffGrade() {
    cout << "-->�ȼ�:";
    cin >> this->staffGrade;
}

// ��ȡ�ȼ���Ϣ
int BaseStaff::getStaffGrade() const {
    return this->staffGrade;
}

//����BaseStaff������ <<
void operator<<(ostream &out, BaseStaff *baseStaffPtr) {
    baseStaffPtr->showInfos();
}
