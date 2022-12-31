#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//�������������ͷ�ļ�
#include <fstream>
#include "worker.h"
using namespace std;//ʹ�ñ�׼�����ռ�
#define FILENAME "empFile.txt"

class workerManager
{
public:
	//���캯��
	workerManager();

	//չʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//���ְ��
	void addEmp();

	//�����ļ�
	void save();

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void showEmp();

	//�ж�ְ���Ƿ���ڣ�������ڣ�����ְ�����������е�λ�ã������ڷ���-1
	int isExist(int id);

	//ɾ��ְ��
	void delEmp();

	//�޸�ְ��
	void modEmp();

	//����ְ��
	void findEmp();

	//���ձ������
	void sortEmp();

	//����ļ�
	void cleanFile();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	worker** m_EmpArray;

	//��������
	~workerManager();
};

