#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class employee:public worker
{
public:
	//���캯��
	employee(int id, string name, int dId);
	
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};

