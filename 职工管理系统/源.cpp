#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main()
{
	////���Դ���
	//worker* wk = nullptr;
	//wk = new employee(1, "����", 1);
	//wk->showInfo();
	//delete wk;
	//wk = new manager(2, "����",2);
	//wk->showInfo();
	//delete wk;
	//wk = new boss(3, "����",3);
	//wk->showInfo();
	//delete wk;



	workerManager wm;
	int choice = 0;//���ڴ洢�û���ѡ��
	while (true)
	{
		//����չʾ�˵���Ա����
		wm.showMenu();

		cout << "����������ѡ�" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://����ְ��
			wm.addEmp();
			break;
		case 2://��ʾְ��
			wm.showEmp();
			break;
		case 3://ɾ��ְ��
			wm.delEmp();
			break;
		case 4://�޸�ְ��
			wm.modEmp();
			break;
		case 5://����ְ��
			wm.findEmp();
			break;
		case 6://����ְ��
			wm.sortEmp();
			break;
		case 7://����ĵ�
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}