#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

//������
class manager :
    public worker
{
public:
	//���캯��
	manager(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};

