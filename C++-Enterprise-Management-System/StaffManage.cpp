#include "StaffManage.h"

//����ȫ�ֱ���
StaffManage SM;

StaffManage::StaffManage() {
    count = 0;
}


StaffManage::~StaffManage() {
    if (count == 0) {
        delete (head);
        delete (current);
    } else {
        while (head->next != nullptr) {
            BaseStaff *headPtr = head;
            head = head->next;
            delete (headPtr);
        }
    }
}

//����ָ���Ĺ��Ż������Ƿ���ڣ�������ڣ��򷵻ض����������е�ָ�룻��������ڣ�����NULL;
BaseStaff *StaffManage::search(string searchKey) {
    //���ݴ����ֵ���ж�������ṹ�У��Ƿ���ڱ�Ż�����ΪsearchKey��Ա������
    BaseStaff *tmp = head;

    //ѭ�����������е�ÿ������
    while (tmp != nullptr) {
        //�ж����빤�Ż������Ƿ���ƥ��
        if (tmp->getStaffNumber() == searchKey || tmp->getStaffNumber() == searchKey) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

//����Ա����Ϣ(����1)
void StaffManage::addStaffInfos() {
    //ÿ���һ��Ա����Ϣ�����ͼ�1
    count++;
    // Ա�����ͷ���
    cout << "------------Ա������-------------" << endl;
    cout << "��1����������Ա" << endl;
    cout << "��2��Ӫ������Ա" << endl;
    cout << "��3����������Ա" << endl;
    cout << "��4����������Ա" << endl;
    cout << "-------------------------------" << endl;
    cout << "-->������:";
    int inputType;
    cin >> inputType;
    //�ж��û������Ƿ���ȷ
    while ((inputType != 1) && (inputType != 2) && (inputType != 3) && (inputType != 4)) {
        cout << "-->�����ʽ�������������룡" << endl;
        cin.clear();
        cin >> inputType;
    }

    if (inputType == 1)  // ����Ǽ�������Ա
    {
        if (count == 1)  // ������ṹ�����ڣ��򴴽�һ���¼�����Ա���󣬲���ֵ��head
        {
            head = new TechnicalStaff();
            head->next = nullptr;
            current = head;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
            return;
        } else {
            //�����µĶ���
            BaseStaff *newTechnicalPtr = new TechnicalStaff();

            BaseStaff *tmp = head;
            //��������鿴�Ƿ��б����ͬ�Ķ���
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newTechnicalPtr->getStaffNumber()) {
                    cout << "���:" << newTechnicalPtr->getStaffNumber() << "�Ѵ���!" << endl;
                    //���ն���
                    delete (newTechnicalPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newTechnicalPtr;
            current = newTechnicalPtr;  // ����ָ�����ֵ��current
            current->next = nullptr;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
            return;
        }
    }

    if (inputType == 2) // Ӫ������Ա
    {
        if (count == 1) //�������ṹ�����ڣ��򴴽�һ����Ӫ����Ա����
        {
            head = new MarketingStaff();
            current = head;
            current->next = nullptr;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
        } else {
            BaseStaff *newMarketingPtr = new MarketingStaff();
            BaseStaff *tmp = head;
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newMarketingPtr->getStaffNumber()) {
                    cout << "���" << newMarketingPtr->getStaffNumber() << "�Ѵ���!" << endl;
                    delete (newMarketingPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newMarketingPtr;
            current = newMarketingPtr;
            current->next = nullptr;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
            return;
        }
    }


    if (inputType == 3) //��������Ա
    {
        if (count == 1) {  //�������ṹ�����ڣ��򴴽�һ���¹�������Ա����
            head = new ManagementStaff();
            current = head;
            current->next = nullptr;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
        } else {
            BaseStaff *newManagementPtr = new ManagementStaff();
            BaseStaff *tmp = head;
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newManagementPtr->getStaffNumber()) {
                    cout << "���" << newManagementPtr->getStaffNumber() << "�Ѵ���" << endl;
                    delete (newManagementPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newManagementPtr;
            current = newManagementPtr;
            current = nullptr;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
            return;
        }
    }

    if (inputType == 4) // ��������Ա
    {
        if (count == 1) { //�������ṹ�����ڣ��򴴽�һ���²�������Ա����
            head = new OperatorStaff();
            current = head;
            current->next = nullptr;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
        } else {
            BaseStaff *newOperatorPtr = new OperatorStaff();
            BaseStaff *tmp = head;
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newOperatorPtr->getStaffNumber()) {
                    cout << "���" << newOperatorPtr->getStaffNumber() << "�Ѵ���" << endl;
                    delete (newOperatorPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newOperatorPtr;
            current = newOperatorPtr;
            current = nullptr;
            cout << "���Ա����Ϣ�ɹ�!" << endl;
            return;
        }
    }
}


//�޸���ҵԱ����Ϣ(����2)
void StaffManage::modifyStaffInfos() {
    cout << "-->�����빤��:";
    string searchKey;
    cin >> searchKey;
    //����search����
    BaseStaff *staffInfoPtr = search(searchKey);

    if (staffInfoPtr == nullptr) {
        cout << "-->����Ϊ:" << searchKey << "��Ա��������!" << endl;
        return;
    } else {
        //�������Ǹ�ָ�����
        BaseStaff *tmp = head;
        while (tmp != staffInfoPtr) {
            tmp = tmp->next;
        }
        cout << "ԭ����:" << tmp->getStaffNumber() << "\n�¹���:";
        tmp->setStaffNumber();
        cout << "ԭ����:" << tmp->getStaffName() << "\n������:";
        tmp->setStaffName();
        cout << "ԭ�Ա�:" << tmp->getStaffSex() << "\n���Ա�:";
        tmp->setStaffSex();
        cout << "ԭ����:" << tmp->getWorkYears() << "\n�¹���:";
        tmp->setWorkYears();
        cout << "ԭ����:" << tmp->getStaffSalary() << "\n�¹���:";
        tmp->setStaffSalary();
        cout << "ԭ�ȼ�:" << tmp->getStaffGrade() << "\n�µȼ�:";
        tmp->setStaffGrade();
        cout << searchKey << "Ա����Ϣ�޸ĳɹ�!" << endl;
    }
}

//ɾ��Ա����Ϣ(����3)
void StaffManage::deleteStaffInfos() {
    cout << "-->�����빤��:";
    string searchKey;
    cin >> searchKey;
    //����search����
    BaseStaff *staffInfoPtr = search(searchKey);

    if (staffInfoPtr == nullptr) {
        cout << searchKey << "Ա����Ϣ������!" << endl;
        return;
    } else {
        //�������Ǹ�ָ�����
        BaseStaff *tmp = head;
        while (tmp != staffInfoPtr) {
            tmp = tmp->next;
        }

        tmp = staffInfoPtr->next;
        // �����ڴ�ռ�
        delete (staffInfoPtr);
        cout << searchKey << "Ա����Ϣɾ���ɹ�!" << endl;
    }
}

//��ѯ����Ա����Ϣ(����4)
void StaffManage::searchStaffInfos() {
    cout << "-->��������Ҫ��ѯ�Ĺ���:";
    string searchKey;
    cin >> searchKey;
    //����search����
    BaseStaff *staffInfoPtr = search(searchKey);

    if (staffInfoPtr == nullptr) {
        cout << "����Ϊ" << searchKey << "��Ա��������!" << endl;
        return;
    } else {
        cout << staffInfoPtr;
    }
}

//��ʾ����Ա����Ϣ(����5)
void StaffManage::showAllStaffInfos() {
    //�ж�head�Ƿ�ΪNULL
    if (head == nullptr) {
        cout << "\n-->����ְ����Ϣ��\n" << endl;
        return;
    }

    //��headָ��ֵ��ֵ����ʱ�����ָ�����
    BaseStaff *tmp = head;

    while (tmp != nullptr) {
        cout << tmp;
        tmp = tmp->next;
    }
}


//��������ʱ�����ļ��е����ݼ��ص�������
void StaffManage::readDatas() {
    fstream inFile;
    inFile.open("..\\staffdatas.dat", ios::in);
    if (!inFile) {
        cout << "���ļ�ʧ��!" << endl;
        exit(1);
    } else {
        cout << "���ݶ�ȡ�ɹ���" << endl;
    }

    while (!inFile.eof())  // �ж��ļ��Ƿ��ȡ����
    {
        if (inFile.peek() == EOF) {
            inFile.close();
            break;
        } else {
            int i;  //i����staffDutyType
            inFile >> i;//��ȡ�ļ��е�ǰ�е�һ�е�ֵ����" "�ָ��
            count++;
            if (count == 1) // �ж��������Ƿ��Ѿ���ָ�����
            {
                switch (i) {
                    case 1: {
                        TechnicalStaff *TechnicalPtr = new TechnicalStaff();
                        head = TechnicalPtr;
                        current = TechnicalPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        //��ȡΪ����ֵ��˳����д���˳�򱣳�һ��
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->technology
                               >> current->devote;
                        break;
                    }
                    case 2: {
                        MarketingStaff *MarketingPtr = new MarketingStaff();
                        head = MarketingPtr;
                        current = MarketingPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->totalAnnualSales
                               >> current->customerReception;
                        break;
                    }
                    case 3: {
                        ManagementStaff *ManagementPtr = new ManagementStaff();
                        head = ManagementPtr;
                        current = ManagementPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->planningSuccessRate
                               >> current->targeAchievementRate
                               >> current->staffManagementRate;
                        break;
                    }
                    case 4: {
                        OperatorStaff *OperatorPtr = new OperatorStaff();
                        head = OperatorPtr;
                        current = OperatorPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->resolveFailureRate
                               >> current->workEfficiency
                               >> current->projectCompletion;
                        break;
                    }
                }
            } else { //��������а���ָ�����
                switch (i) {
                    case 1: {
                        TechnicalStaff *TechnicalPtr = new TechnicalStaff();
                        TechnicalPtr->staffDutyType = i;
                        inFile >> TechnicalPtr->staffNumber
                               >> TechnicalPtr->staffName
                               >> TechnicalPtr->staffSex
                               >> TechnicalPtr->staffWorkYears
                               >> TechnicalPtr->staffSalary
                               >> TechnicalPtr->staffGrade
                               >> TechnicalPtr->technology
                               >> TechnicalPtr->devote;
                        current->next = TechnicalPtr;
                        current = TechnicalPtr;
                        current->next = nullptr;
                        break;
                    }
                    case 2: {
                        MarketingStaff *MarketingPtr = new MarketingStaff();
                        MarketingPtr->staffDutyType = i;
                        inFile >> MarketingPtr->staffNumber
                               >> MarketingPtr->staffName
                               >> MarketingPtr->staffSex
                               >> MarketingPtr->staffWorkYears
                               >> MarketingPtr->staffSalary
                               >> MarketingPtr->staffGrade
                               >> MarketingPtr->totalAnnualSales
                               >> MarketingPtr->customerReception;
                        current->next = MarketingPtr;
                        current = MarketingPtr;
                        current->next = nullptr;
                        break;
                    }
                    case 3: {
                        ManagementStaff *ManagementPtr = new ManagementStaff();
                        ManagementPtr->staffDutyType = i;
                        inFile >> ManagementPtr->staffNumber
                               >> ManagementPtr->staffName
                               >> ManagementPtr->staffSex
                               >> ManagementPtr->staffWorkYears
                               >> ManagementPtr->staffSalary
                               >> ManagementPtr->staffGrade
                               >> ManagementPtr->planningSuccessRate
                               >> ManagementPtr->targeAchievementRate
                               >> ManagementPtr->staffManagementRate;
                        current->next = ManagementPtr;
                        current = ManagementPtr;
                        current->next = nullptr;
                        break;
                    }
                    case 4: {
                        OperatorStaff *OperatorPtr = new OperatorStaff();
                        OperatorPtr->staffDutyType = i;
                        inFile >> OperatorPtr->staffNumber
                               >> OperatorPtr->staffName
                               >> OperatorPtr->staffSex
                               >> OperatorPtr->staffWorkYears
                               >> OperatorPtr->staffSalary
                               >> OperatorPtr->staffGrade
                               >> OperatorPtr->resolveFailureRate
                               >> OperatorPtr->workEfficiency
                               >> OperatorPtr->projectCompletion;
                        current->next = OperatorPtr;
                        current = OperatorPtr;
                        current->next = nullptr;
                        break;
                    }
                }
            }
        }
    }
}


//�ڳ����˳�����ӣ��޸ģ�ɾ��ʱ�������ݱ��浽�ļ���
void StaffManage::writeDatas() {
    fstream outFile;
    outFile.open("..\\staffdatas.dat", ios::out | ios::app);

    if (!outFile) {
        cout << "���ļ�ʧ��!" << endl;
        exit(1);
    }

    BaseStaff *headPtr = head;

    //�ж��Ƿ�ͷָ�����ֵ
    if (headPtr == nullptr) {
        cout << "��������Ҫ���棡" << endl;
        return;
    }

    //�����ж��ָ��,��Ҫ�����ͷָ�뿪ʼ��һֱ������ָ�����
    while (headPtr->next != nullptr) {
        if (headPtr->staffDutyType == 1)//�ж�ָ������Ƿ��Ǽ�������Ա
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->technology << " "
                    << headPtr->devote << endl;
        }

        if (headPtr->staffDutyType == 2) //Ӫ������Ա
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->totalAnnualSales << " "
                    << headPtr->customerReception << endl;
        }

        if (headPtr->staffDutyType == 3) //��������Ա
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->planningSuccessRate << " "
                    << headPtr->targeAchievementRate << " "
                    << headPtr->staffManagementRate << endl;
        }

        if (headPtr->staffDutyType == 4) //��������Ա
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->resolveFailureRate << " "
                    << headPtr->workEfficiency << " "
                    << headPtr->projectCompletion << endl;
        }

        headPtr = headPtr->next;
    }

    //�������һ��ָ��Ԫ�ص�����
    if (headPtr->staffDutyType == 1)//�ж�ָ������Ƿ��Ǽ�������Ա
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->technology << " "
                << headPtr->devote << endl;
    }

    if (headPtr->staffDutyType == 2) //Ӫ������Ա
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->totalAnnualSales << " "
                << headPtr->customerReception << endl;
    }

    if (headPtr->staffDutyType == 3) //��������Ա
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->planningSuccessRate << " "
                << headPtr->targeAchievementRate << " "
                << headPtr->staffManagementRate << endl;
    }

    if (headPtr->staffDutyType == 4) //��������Ա
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->resolveFailureRate << " "
                << headPtr->workEfficiency << " "
                << headPtr->projectCompletion << endl;
    }
    cout << "���ݱ���ɹ�!" << endl;
    outFile.close(); //�ر��ļ���
}