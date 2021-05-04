#include "ManagementStaff.h"

ManagementStaff::ManagementStaff() {
    this->staffDutyType = 3;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setPlanningSuccessRate();
    setTargeAchievementRate();
    setStaffManagementRate();
}

ManagementStaff::~ManagementStaff() {
}

void ManagementStaff::setPlanningSuccessRate() {
    cout << "�߻��ɹ���:";
    cin >> this->planningSuccessRate;
}

int ManagementStaff::getPlanningSuccessRate() const {
    return this->planningSuccessRate;
}

void ManagementStaff::setTargeAchievementRate() {
    cout << "��Ŀ������:";
    cin >> this->targeAchievementRate;
}

int ManagementStaff::getTargeAchievementRate() const {
    return this->targeAchievementRate;
}

void ManagementStaff::setStaffManagementRate() {
    cout << "Ա��������:";
    cin >> this->staffManagementRate;
}

int ManagementStaff::getStaffManagementRate() const {
    return this->staffManagementRate;
}

void ManagementStaff::showInfos() {
    cout << "\n\"----------------��������Ա��Ϣ��------------------------" << endl;
    cout << "����:" << getStaffNumber() << endl;
    cout << "����:" << getStaffName() << endl;
    cout << "�Ա�:" << getStaffSex() << endl;
    cout << "����" << getWorkYears() << endl;
    cout << "����" << getStaffSalary() << endl;
    cout << "�ȼ�:" << getStaffGrade() << endl;
    cout << "�߻��ɹ���:" << getPlanningSuccessRate() << endl;
    cout << "��Ŀ������:" << getTargeAchievementRate() << endl;
    cout << "Ա��������:" << getStaffManagementRate() << endl;
    cout << "--------------------------------------------------------\n" << endl;
}
