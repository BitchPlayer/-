#include "boss.h"

//���캯��
boss::boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}

//��ʾ������Ϣ
void boss::showInfo()
{
	cout << "ְ�����:" << this->m_Id << "\tְ������:" << this->m_Name << "\t��λ:"
		<< this->getDeptName() << "\t��λְ�𣺹���˾��������" << endl;
}

//��ȡ��λ����
string boss::getDeptName()
{
	return string("�ܲ�");
}