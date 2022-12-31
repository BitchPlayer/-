#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

workerManager::workerManager() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	//1、文件不存在

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = nullptr;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在，但数据为空

	char ch;
	ifs >> ch;
	if (ifs.eof())//文件为空
	{
		cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = nullptr;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在，并且内有数据
	int num = this->get_EmpNum();
	cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();

	////测试代码
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "职工号： " << this->m_EmpArray[i]->m_Id
	//		<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
	//		<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void workerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

void workerManager::addEmp() {

	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;// 新空间人数 = 原来记录人数 + 新增人数
		//开辟新空间
		worker** newSpace = new worker * [newSize];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位:" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
	
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//成功添加后，应该保存到文件中
		this->save();

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名职工" << endl;

	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");
}

void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件 -- 写文件

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker* wk = nullptr;
		switch (dId)
		{
		case 1:
			wk = new employee(id, name, dId);
			break;
		case 2:
			wk = new manager(id, name, dId);
			break;
		case 3:
			wk = new boss(id, name, dId);
			break;
		}
		this->m_EmpArray[index++] = wk;
	}

	ifs.close();
}

void workerManager::showEmp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}

int workerManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}

void workerManager::delEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		//按照职工号删除
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)//说明职工存在，并且要删除掉index位置上的职工
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			//更新数组中记录的人员个数
			this->m_EmpNum--;

			//数据同步更新到文件中
			this->save();

			cout << "删除成功！" << endl;
		}
		else
			cout << "删除失败，未找到该职工" << endl;
	}

	system("pause");
	system("cls");
}

void workerManager::modEmp() {
	if (this->m_FileIsEmpty)
		cout << "文件不存在或记录为空！" << endl;
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//查找到编号的职工
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查找到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请选择该职工岗位:" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, 1);
				break;
			case 2:
				worker = new manager(newId, newName, 2);
				break;
			case 3:
				worker = new boss(newId, newName, 3);
				break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else
			cout << "修改失败，查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void workerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式:" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按编号查找
			cout << "请输入修改职工的编号：" << endl;
			int id;
			cin >> id;

			int ret = this->isExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			//按姓名查找
			cout << "请输入修改职工的姓名：" << endl;
			string name;
			cin >> name;

			//加入判断是否查到的标志
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为" << this->m_EmpArray[i]->m_Id << "号，该职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if(flag==false)
				cout << "查找失败，查无此人！" << endl;
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workerManager::sortEmp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入排序的方式:" << endl;
		cout << "1、按职工编号升序" << endl;
		cout << "2、按职工编号降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//声明最小值 或 最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->showEmp();
	}
	system("pause");
	system("cls");
}

void workerManager::cleanFile() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}


workerManager::~workerManager() {
	if (this->m_EmpArray != nullptr)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = nullptr;
	}
}

