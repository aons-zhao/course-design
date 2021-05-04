#include "SystemMenu.h"

SystemMenu::SystemMenu() {
    //���ļ��ж�ȡ����
    SM.readDatas();
}

SystemMenu::~SystemMenu() {
}

//������˵�
void SystemMenu::mainUI() {
    cout << "-----------------------------------" << endl;
    cout << "��ӭ��½,��ҵԱ����Ϣ����ϵͳ��" << endl;
    cout << "��1�������Ϣ" << endl;
    cout << "��2���޸���Ϣ" << endl;
    cout << "��3��ɾ����Ϣ" << endl;
    cout << "��4��������Ϣ" << endl;
    cout << "��5����ʾȫ����Ϣ" << endl;
    cout << "��0���˳�ϵͳ" << endl;
    cout << "---------------------------------" << endl;
}

void SystemMenu::run() {

    while (1) {
        mainUI();
        cout << "-->������:" << endl;
        int value;
        cin >> value;

        while (value != 1 && value != 2 && value != 3 && value != 4 && value != 5 && value != 0) {
            cout << "�����ʽ�������������룡" << endl;
            cin.clear();
            cin >> value;
        }

        switch (value) {
            case 1:
                SM.addStaffInfos();   //����
                break;
            case 2:
                SM.modifyStaffInfos(); //�޸�
                break;
            case 3:
                SM.deleteStaffInfos(); //ɾ��
                break;
            case 4:
                SM.searchStaffInfos();  //����
                break;
            case 5:
                SM.showAllStaffInfos(); //��ʾ������Ϣ
                break;
            case 0:
                // ���������е�����
                SM.writeDatas();
                cout << "�˳�ϵͳ�ɹ���" << endl;
                exit(0);
        }
    }
}
