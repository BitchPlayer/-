#include "manager.h"

//���캯��
manager::manager(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

//��ʾ������Ϣ
void manager::showInfo()
{
	cout << "ְ�����:" << this->m_Id << "\tְ������:" << this->m_Name << "\t��λ:"
		<< this->getDeptName() << "\t��λְ������ϰ彻�������񣬲����·������Ա��" << endl;
}

//��ȡ��λ����
string manager::getDeptName()
{
	return string("����");
}