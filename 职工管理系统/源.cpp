#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main()
{
	////测试代码
	//worker* wk = nullptr;
	//wk = new employee(1, "张三", 1);
	//wk->showInfo();
	//delete wk;
	//wk = new manager(2, "李四",2);
	//wk->showInfo();
	//delete wk;
	//wk = new boss(3, "王五",3);
	//wk->showInfo();
	//delete wk;



	workerManager wm;
	int choice = 0;//用于存储用户的选项
	while (true)
	{
		//调用展示菜单成员函数
		wm.showMenu();

		cout << "请输入您的选项：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工
			wm.addEmp();
			break;
		case 2://显示职工
			wm.showEmp();
			break;
		case 3://删除职工
			wm.delEmp();
			break;
		case 4://修改职工
			wm.modEmp();
			break;
		case 5://查找职工
			wm.findEmp();
			break;
		case 6://排序职工
			wm.sortEmp();
			break;
		case 7://清空文档
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}