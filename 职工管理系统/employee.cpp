#include "employee.h"

//���캯��
employee::employee(int id,string name,int dId) {
	m_Id = id; 
	m_Name = name; 
	m_DeptId = dId;
}

//��ʾ������Ϣ
void employee::showInfo() {
	cout << "ְ�����:" << this->m_Id << "\tְ������:" << this->m_Name << "\t��λ:" 
		<< this->getDeptName() << "\t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ����
string employee::getDeptName() {
	return string("Ա��");
}