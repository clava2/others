//
//	个人相册程序
//	相册类
//
//	Created by ZhangHua @ 2015-10
//  2017-10 增加ShowAllPhotos和AddPhoto函数的初始空白定义。
//
//  请按作业要求定义相册类的成员函数。

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "XAlbum.h"
#include "XUtility.h"

void XAlbum::ShowAllPhotos()
{
	// 添加“显示全部照片”的代码

	system("cls");

	if(m_photo_list.IsEmpty())
	{
		cout << "相册是空的";
		return;
	}

	cout << "=======================================================================================================" << endl;
	cout << "||" << setw(3)  << "编号" << "|"<< setw(10) << "标题" << "|"<< setw(20) << "说明" << "|"<< setw(20) << "入册时间"<< "|" << setw(20) << "拍摄时间"<< "|" << setw(20) << "拍摄地点"<< "||" << endl;

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
	// 添加“增加照片”的代码

	XPhoto tempItem;

	string tempString = "";


	cout << "请输入照片标题：" << endl;
	cin >> tempString;

	strcpy(tempItem.m_title,tempString.c_str());

	cout << "请输入照片说明：" << endl;
	cin >> tempString;

	strcpy(tempItem.m_descr,tempString.c_str());

	cout << "请输入照片拍摄日期（格式：年 月 日 时 分 秒）：" << endl;

	int year,month,day,hour,minute,second;
	cin >> year >> month >> day >> hour >> minute >> second;
	sprintf(tempItem.m_create_datetime,"%d-%d-%d %d:%d:%d",year,month,day,hour,minute,second);

	cout << "请输入拍摄地点：" << endl;
	cin >> tempString;

	strcpy(tempItem.m_create_place,tempString.c_str());

	// 下面这段程序是演示怎么获取当前系统时间，你可能需要此功能
	/*char t[20];
	XUtility util;
	util.GetCurDateTime(t);*/

	XUtility util;
	util.GetCurDateTime(tempItem.m_add_datetime);

	tempItem.show();

	m_photo_list.AppendItem(tempItem);

	// 暂时返回 true，你可以修改
	return true;
}


int SearchMenu()
{
	system("cls");
	cout << "=====================" << endl;
	cout << "请选择查找选项：" << endl;
	cout << "---------------------" << endl;
	cout << "[1] 通过序号查找" << endl;
	cout << "[2] 通过标题查找" << endl;
	cout << "[3] 通过说明查找" << endl;
	cout << "[4] 通过拍摄日期查找" << endl;
	cout << "[5] 通过拍摄地点查找" << endl;
	cout << "[6] 通过入册时间查找" << endl;
	cout << "[0] 返回" << endl;
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
			cout << "请输入序号:";
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
				cout << "没能找到！"<< endl;
				return false;
			}
			cout << "查找结果:" << endl;

			cout << setw(3) << "编号" << setw(10) << "标题" << setw(20) << "说明" << setw(20) << "入册时间" << setw(20) << "拍摄时间" << setw(20) << "拍摄地点" << endl;

			cout << setw(4) << result.m_id << setw(10) << result.m_title << setw(20) << result.m_descr << setw(20) << result.m_add_datetime << setw(20) << result.m_create_datetime << setw(20) << result.m_create_place << endl;
			break;
		}
	case 3:
		{
			cout << "请输入需要查找的说明:";
			string descri;
			cin >> descri;

			bool found = false;

			cout << "查找结果:" << endl;

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
						cout << setw(3) << "编号" << setw(10) << "标题" << setw(20) << "说明" << setw(20) << "入册时间" << setw(20) << "拍摄时间" << setw(20) << "拍摄地点" << endl;
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
			cout << "请输入需要查找的标题:";
			string title;
			cin >> title;

			bool found = false;

			cout << "查找结果:" << endl;

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
						cout << setw(3) << "编号" << setw(10) << "标题" << setw(20) << "说明" << setw(20) << "入册时间" << setw(20) << "拍摄时间" << setw(20) << "拍摄地点" << endl;
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
			cout << "请输入需要查找的拍摄日期（格式:年 月 日）:";
			int year,month,day;
			cin >> year >> month >> day;

			char date[20];
			sprintf(date,"%d-%d-%d",year,month,day);

			bool found = false;

			cout << "查找结果:" << endl;

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
						cout << setw(3) << "编号" << setw(10) << "标题" << setw(20) << "说明" << setw(20) << "入册时间" << setw(20) << "拍摄时间" << setw(20) << "拍摄地点" << endl;
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
			cout << "请输入需要查找的拍摄地点:";
			string place;
			cin >> place;

			bool found = false;

			cout << "查找结果:" << endl;

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
						cout << setw(3) << "编号" << setw(10) << "标题" << setw(20) << "说明" << setw(20) << "入册时间" << setw(20) << "拍摄时间" << setw(20) << "拍摄地点" << endl;
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
			cout << "请输入需要查找的入册日期（格式：年 月 日）:";
			
			int year,month,day;
			cin >> year >> month >> day;

			char date[20];
			sprintf(date,"%d-%d-%d",year,month,day);

			bool found = false;

			cout << "查找结果:" << endl;

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
						cout << setw(3) << "编号" << setw(10) << "标题" << setw(20) << "说明" << setw(20) << "入册时间" << setw(20) << "拍摄时间" << setw(20) << "拍摄地点" << endl;
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
			cout << "功能建设中！" << endl;
		}
	}
	return true;
}

bool XAlbum::ModifyPhoto()
{
	cout << "请输入想要删除的照片的序号：" << endl;
	int id = 0;
	cin >> id;

	Item newItem;
	if(!m_photo_list.GetItem(m_photo_list.GetIndexByID(id),newItem))
	{
		return false;
	}

	cout << "你想要修改何种信息？" << endl;
	cout << "[1] 标题" << endl;
	cout << "[2] 说明" << endl;
	cout << "[3] 拍摄日期" << endl;
	cout << "[4] 拍摄地点" << endl;
	int choice = 0;
	cin >> choice;

	switch(choice)
	{
	case 1:
		{
			cout << "请输入新标题" << endl;
			cin >> newItem.m_title;
			break;
		}
	case 2:
		{
			cout << "请输入新说明" << endl;
			cin >> newItem.m_descr;
			break;
		}
	case 3:
		{
			cout << "请输入新拍摄日期(格式：年 月 日 时 分 秒)" << endl;
			int year,month,day,hour,minute,second;
			cin >> year>> month >> day >> hour >> minute >> second;
			sprintf(newItem.m_create_datetime,"%d-%d-%d %d:%d:%d",year,month,day,hour,minute,second);
			break;
		}
	case 4:
		{
			cout << "请输入新拍摄地点" << endl;
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
	cout << "请输入想要删除的照片的序号：" << endl;
	int id = 0;
	cin >> id;

	if(!m_photo_list.DeleteItem(m_photo_list.GetIndexByID(id)))
	{
		return false;
	}

	return true;
}
