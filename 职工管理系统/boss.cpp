#include "boss.h"

//构造函数
boss::boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

//显示个人信息
void boss::showInfo()
{
	cout << "职工编号:" << this->m_Id << "\t职工姓名:" << this->m_Name << "\t岗位:"
		<< this->getDeptName() << "\t岗位职责：管理公司所有事务" << endl;
}

//获取岗位名称
string boss::getDeptName()
{
	return string("总裁");
}