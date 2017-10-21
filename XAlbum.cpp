//
//	����������
//	�����
//
//	Created by ZhangHua @ 2015-10
//  2017-10 ����ShowAllPhotos��AddPhoto�����ĳ�ʼ�հ׶��塣
//
//  �밴��ҵҪ���������ĳ�Ա������

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "XAlbum.h"
#include "XUtility.h"

void XAlbum::ShowAllPhotos()
{
	// ��ӡ���ʾȫ����Ƭ���Ĵ���

	system("cls");

	if(m_photo_list.IsEmpty())
	{
		cout << "����ǿյ�";
		return;
	}

	cout << "=======================================================================================================" << endl;
	cout << "||" << setw(3)  << "���" << "|"<< setw(10) << "����" << "|"<< setw(20) << "˵��" << "|"<< setw(20) << "���ʱ��"<< "|" << setw(20) << "����ʱ��"<< "|" << setw(20) << "����ص�"<< "||" << endl;

	for(int i = 0;i != m_photo_list.ItemCount();++i)
	{
		Item tempItem;
		m_photo_list.GetItem(i,tempItem);
		cout << "-------------------------------------------------------------------------------------------------------" << endl;
		cout << "||"<< setw(4) << tempItem.m_id << "|"<< setw(10) << tempItem.m_title << "|"<< setw(20) << tempItem.m_descr << "|"<< setw(20) << tempItem.m_add_datetime << "|"<< setw(20) << tempItem.m_create_datetime<< "|" << setw(20) << tempItem.m_create_place << "||" << endl; 
	}
	cout << "=======================================================================================================" << endl;
}

bool XAlbum::AddPhoto()
{
	// ��ӡ�������Ƭ���Ĵ���

	XPhoto tempItem;

	string tempString = "";


	cout << "��������Ƭ���⣺" << endl;
	cin >> tempString;

	strcpy(tempItem.m_title,tempString.c_str());

	cout << "��������Ƭ˵����" << endl;
	cin >> tempString;

	strcpy(tempItem.m_descr,tempString.c_str());

	cout << "��������Ƭ�������ڣ���ʽ���� �� �� ʱ �� �룩��" << endl;

	int year,month,day,hour,minute,second;
	cin >> year >> month >> day >> hour >> minute >> second;
	sprintf(tempItem.m_create_datetime,"%d-%d-%d %d:%d:%d",year,month,day,hour,minute,second);

	cout << "����������ص㣺" << endl;
	cin >> tempString;

	strcpy(tempItem.m_create_place,tempString.c_str());

	// ������γ�������ʾ��ô��ȡ��ǰϵͳʱ�䣬�������Ҫ�˹���
	/*char t[20];
	XUtility util;
	util.GetCurDateTime(t);*/

	XUtility util;
	util.GetCurDateTime(tempItem.m_add_datetime);

	tempItem.show();

	m_photo_list.AppendItem(tempItem);

	// ��ʱ���� true��������޸�
	return true;
}


int SearchMenu()
{
	system("cls");
	cout << "=====================" << endl;
	cout << "��ѡ�����ѡ�" << endl;
	cout << "---------------------" << endl;
	cout << "[1] ͨ����Ų���" << endl;
	cout << "[2] ͨ���������" << endl;
	cout << "[3] ͨ��˵������" << endl;
	cout << "[4] ͨ���������ڲ���" << endl;
	cout << "[5] ͨ������ص����" << endl;
	cout << "[6] ͨ�����ʱ�����" << endl;
	cout << "[0] ����" << endl;
	cout << "=====================" << endl;
	int choice = 0;
	cin >> choice;
	return choice;
}

bool XAlbum::SearchPhoto()
{
	int choice = SearchMenu();
	switch(choice)
	{
	case 0:
		{
			return false;
		}
	case 1:
		{
			cout << "���������:";
			int id = 0;
			cin >> id;

			Item result;

			bool found = false;

			for(int i = 0;i != m_photo_list.ItemCount();++i)
			{
				Item tempItem;
				m_photo_list.GetItem(i,tempItem);
				if(tempItem.m_id == id)
				{
					m_photo_list.GetItem(i,result);
					found = true;
					break;
				}
			}
			if(!found)
			{
				cout << "û���ҵ���"<< endl;
				return false;
			}
			cout << "���ҽ��:" << endl;

			cout << setw(3) << "���" << setw(10) << "����" << setw(20) << "˵��" << setw(20) << "���ʱ��" << setw(20) << "����ʱ��" << setw(20) << "����ص�" << endl;

			cout << setw(4) << result.m_id << setw(10) << result.m_title << setw(20) << result.m_descr << setw(20) << result.m_add_datetime << setw(20) << result.m_create_datetime << setw(20) << result.m_create_place << endl;
			break;
		}
	case 3:
		{
			cout << "��������Ҫ���ҵ�˵��:";
			string descri;
			cin >> descri;

			bool found = false;

			cout << "���ҽ��:" << endl;

			for(int i = 0;i != m_photo_list.ItemCount();++i)
			{
				Item tempItem;
				m_photo_list.GetItem(i,tempItem);
				char* p = strstr(tempItem.m_descr,descri.c_str());
				if(p != NULL)
				{
					if(!found)
					{
						found = true;
						cout << setw(3) << "���" << setw(10) << "����" << setw(20) << "˵��" << setw(20) << "���ʱ��" << setw(20) << "����ʱ��" << setw(20) << "����ص�" << endl;
					}
					cout << setw(4) << tempItem.m_id << setw(10) << tempItem.m_title << setw(20) << tempItem.m_descr << setw(20) << tempItem.m_add_datetime << setw(20) << tempItem.m_create_datetime << setw(20) << tempItem.m_create_place << endl;
				}
			}
			if(!found)
			{
				return false;
			}
			break;
		}

	case 2:
		{
			cout << "��������Ҫ���ҵı���:";
			string title;
			cin >> title;

			bool found = false;

			cout << "���ҽ��:" << endl;

			for(int i = 0;i != m_photo_list.ItemCount();++i)
			{
				Item tempItem;
				m_photo_list.GetItem(i,tempItem);
				char* p = strstr(tempItem.m_title,title.c_str());
				if(p != NULL)
				{
					if(!found)
					{
						found = true;
						cout << setw(3) << "���" << setw(10) << "����" << setw(20) << "˵��" << setw(20) << "���ʱ��" << setw(20) << "����ʱ��" << setw(20) << "����ص�" << endl;
					}
					cout << setw(4) << tempItem.m_id << setw(10) << tempItem.m_title << setw(20) << tempItem.m_descr << setw(20) << tempItem.m_add_datetime << setw(20) << tempItem.m_create_datetime << setw(20) << tempItem.m_create_place << endl;
				}
			}
			if(!found)
			{
				return false;
			}
			break;
		}
	case 4:
		{
			cout << "��������Ҫ���ҵ��������ڣ���ʽ:�� �� �գ�:";
			int year,month,day;
			cin >> year >> month >> day;

			char date[20];
			sprintf(date,"%d-%d-%d",year,month,day);

			bool found = false;

			cout << "���ҽ��:" << endl;

			for(int i = 0;i != m_photo_list.ItemCount();++i)
			{
				Item tempItem;
				m_photo_list.GetItem(i,tempItem);
				char* p = strstr(tempItem.m_create_datetime,date);
				if(p != NULL)
				{
					if(!found)
					{
						found = true;
						cout << setw(3) << "���" << setw(10) << "����" << setw(20) << "˵��" << setw(20) << "���ʱ��" << setw(20) << "����ʱ��" << setw(20) << "����ص�" << endl;
					}
					cout << setw(4) << tempItem.m_id << setw(10) << tempItem.m_title << setw(20) << tempItem.m_descr << setw(20) << tempItem.m_add_datetime << setw(20) << tempItem.m_create_datetime << setw(20) << tempItem.m_create_place << endl;
				}
			}
			if(!found)
			{
				return false;
			}
			break;
		}
	case 5:
		{
			cout << "��������Ҫ���ҵ�����ص�:";
			string place;
			cin >> place;

			bool found = false;

			cout << "���ҽ��:" << endl;

			for(int i = 0;i != m_photo_list.ItemCount();++i)
			{
				Item tempItem;
				m_photo_list.GetItem(i,tempItem);
				char* p = strstr(tempItem.m_create_place,place.c_str());
				if(p != NULL)
				{
					if(!found)
					{
						found = true;
						cout << setw(3) << "���" << setw(10) << "����" << setw(20) << "˵��" << setw(20) << "���ʱ��" << setw(20) << "����ʱ��" << setw(20) << "����ص�" << endl;
					}
					cout << setw(4) << tempItem.m_id << setw(10) << tempItem.m_title << setw(20) << tempItem.m_descr << setw(20) << tempItem.m_add_datetime << setw(20) << tempItem.m_create_datetime << setw(20) << tempItem.m_create_place << endl;
				}
			}
			if(!found)
			{
				return false;
			}
			break;
		}
	case 6:
		{
			cout << "��������Ҫ���ҵ�������ڣ���ʽ���� �� �գ�:";
			
			int year,month,day;
			cin >> year >> month >> day;

			char date[20];
			sprintf(date,"%d-%d-%d",year,month,day);

			bool found = false;

			cout << "���ҽ��:" << endl;

			for(int i = 0;i != m_photo_list.ItemCount();++i)
			{
				Item tempItem;
				m_photo_list.GetItem(i,tempItem);
				char* p = strstr(tempItem.m_add_datetime,date);
				if(p != NULL)
				{
					if(!found)
					{
						found = true;
						cout << setw(3) << "���" << setw(10) << "����" << setw(20) << "˵��" << setw(20) << "���ʱ��" << setw(20) << "����ʱ��" << setw(20) << "����ص�" << endl;
					}
					cout << setw(4) << tempItem.m_id << setw(10) << tempItem.m_title << setw(20) << tempItem.m_descr << setw(20) << tempItem.m_add_datetime << setw(20) << tempItem.m_create_datetime << setw(20) << tempItem.m_create_place << endl;
				}
			}
			if(!found)
			{
				return false;
			}
			break;
		}
	default:
		{
			cout << "���ܽ����У�" << endl;
		}
	}
	return true;
}

bool XAlbum::ModifyPhoto()
{
	cout << "��������Ҫɾ������Ƭ����ţ�" << endl;
	int id = 0;
	cin >> id;

	Item newItem;
	if(!m_photo_list.GetItem(m_photo_list.GetIndexByID(id),newItem))
	{
		return false;
	}

	cout << "����Ҫ�޸ĺ�����Ϣ��" << endl;
	cout << "[1] ����" << endl;
	cout << "[2] ˵��" << endl;
	cout << "[3] ��������" << endl;
	cout << "[4] ����ص�" << endl;
	int choice = 0;
	cin >> choice;

	switch(choice)
	{
	case 1:
		{
			cout << "�������±���" << endl;
			cin >> newItem.m_title;
			break;
		}
	case 2:
		{
			cout << "��������˵��" << endl;
			cin >> newItem.m_descr;
			break;
		}
	case 3:
		{
			cout << "����������������(��ʽ���� �� �� ʱ �� ��)" << endl;
			int year,month,day,hour,minute,second;
			cin >> year>> month >> day >> hour >> minute >> second;
			sprintf(newItem.m_create_datetime,"%d-%d-%d %d:%d:%d",year,month,day,hour,minute,second);
			break;
		}
	case 4:
		{
			cout << "������������ص�" << endl;
			cin >> newItem.m_create_place;
			break;
		}
	}

	if(!m_photo_list.UpdateItem(m_photo_list.GetIndexByID(id),newItem))
	{
		return false;
	}

	return true;
	
}

bool XAlbum::DeletePhoto()
{
	cout << "��������Ҫɾ������Ƭ����ţ�" << endl;
	int id = 0;
	cin >> id;

	if(!m_photo_list.DeleteItem(m_photo_list.GetIndexByID(id)))
	{
		return false;
	}

	return true;
}
