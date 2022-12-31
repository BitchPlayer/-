#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

workerManager::workerManager() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	//1���ļ�������

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = nullptr;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����ڣ�������Ϊ��

	char ch;
	ifs >> ch;
	if (ifs.eof())//�ļ�Ϊ��
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = nullptr;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ����ڣ�������������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();

	////���Դ���
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
	//		<< " ְ�������� " << this->m_EmpArray[i]->m_Name
	//		<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void workerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

void workerManager::addEmp() {

	cout << "���������ְ��������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;// �¿ռ����� = ԭ����¼���� + ��������
		//�����¿ռ�
		worker** newSpace = new worker * [newSize];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
	
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//�ɹ���Ӻ�Ӧ�ñ��浽�ļ���
		this->save();

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "��ְ��" << endl;

	}
	else
	{
		cout << "������������" << endl;
	}
	//��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� -- д�ļ�

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	//�������������
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
			//�ҵ�ְ��
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
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ����ɾ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)//˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			//���������м�¼����Ա����
			this->m_EmpNum--;

			//����ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ���" << endl;
		}
		else
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
	}

	system("pause");
	system("cls");
}

void workerManager::modEmp() {
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "���ҵ���" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			//�������ݵ�������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void workerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ:" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//����Ų���
			cout << "�������޸�ְ���ı�ţ�" << endl;
			int id;
			cin >> id;

			int ret = this->isExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			//����������
			cout << "�������޸�ְ����������" << endl;
			string name;
			cin >> name;

			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ" << this->m_EmpArray[i]->m_Id << "�ţ���ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if(flag==false)
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workerManager::sortEmp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "����������ķ�ʽ:" << endl;
		cout << "1����ְ���������" << endl;
		cout << "2����ְ����Ž���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//������Сֵ �� ���ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
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
		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->showEmp();
	}
	system("pause");
	system("cls");
}

void workerManager::cleanFile() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
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

