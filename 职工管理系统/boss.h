#pragma once
#include "worker.h"
class boss :
    public worker
{
public:
	//���캯��
	boss(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};

