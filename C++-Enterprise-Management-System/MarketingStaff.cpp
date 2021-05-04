#include "MarketingStaff.h"

MarketingStaff::~MarketingStaff() {
}

MarketingStaff::MarketingStaff() {
    this->staffDutyType = 2;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setStaffGrade();
    setTotalAnnualSales();
    setCustomerReception();
}

void MarketingStaff::setTotalAnnualSales() {
    cout << "�������ܶ�:";
    cin >> this->totalAnnualSales;
}

int MarketingStaff::getTotalAnnualSales() const {
    return this->totalAnnualSales;
}

void MarketingStaff::setCustomerReception() {
    cout << "�ͻ��Ӵ���:";
    cin >> this->customerReception;
}

int MarketingStaff::getCustomerReception() const {
    return this->customerReception;
}


void MarketingStaff::showInfos() {
    cout << "\n\"----------------Ӫ������Ա��Ϣ��------------------------" << endl;
    cout << "����:" << getStaffNumber() << endl;
    cout << "����:" << getStaffName() << endl;
    cout << "�Ա�:" << getStaffSex() << endl;
    cout << "����:" << getWorkYears() << endl;
    cout << "����:" << getStaffSalary() << endl;
    cout << "�ȼ�:" << getStaffGrade() << endl;
    cout << "�������ܶ�:" << getTotalAnnualSales() << endl;
    cout << "�ͻ��Ӵ���:" << getCustomerReception() << endl;
    cout << "--------------------------------------------------------\n" << endl;
}
