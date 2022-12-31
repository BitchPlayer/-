#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
#include <fstream>
#include "worker.h"
using namespace std;//使用标准命名空间
#define FILENAME "empFile.txt"

class workerManager
{
public:
	//构造函数
	workerManager();

	//展示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//添加职工
	void addEmp();

	//保存文件
	void save();

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void showEmp();

	//判断职工是否存在，如果存在，返回职工所在数组中的位置，不存在返回-1
	int isExist(int id);

	//删除职工
	void delEmp();

	//修改职工
	void modEmp();

	//查找职工
	void findEmp();

	//按照编号排序
	void sortEmp();

	//清空文件
	void cleanFile();

	//判断文件是否为空的标志
	bool m_FileIsEmpty;

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	worker** m_EmpArray;

	//析构函数
	~workerManager();
};

