//
//	个人相册应用程序
//
//	Created by ZhangHua @ 2015-10
//  2017-10 增加相册对象；修改初始提示。
//
//  请按作业要求完成应用程序的设计和实现。

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XAlbum.h"

// 显示个人相册程序的功能菜单，并获取用户选择执行的功能项
// 返回值是用户选择的功能项编号
int menu();

// 个人相册程序的主控函数
void main()
{
	XAlbum myAlbum; // 相册对象

	int choice; // 保存用户选择的功能项编号
	do
	{
		// 显示菜单，获取要执行的功能项
		choice = menu();

		// 根据功能项编号执行相应的操作
		switch (choice)
		{
		case 1: // [1]显示全部照片列表
			{
				std::cout<<"\n你选择执行[1]显示全部照片\n该功能还在建设……\n\n";
				myAlbum.ShowAllPhotos();
				break;
			}
		case 2: // [2]添加照片
			{
				std::cout<<"\n你选择执行[2]添加照片\n该功能还在建设……\n\n";
				if(!myAlbum.AddPhoto())
				{
					cout << "添加失败，可能是空间已满（最大100个）或者系统无法申请内存，请重试！" << endl;
				}
				break;
			}
		case 3: // [3]查找照片
			{
				std::cout<<"\n你选择执行[3]查找照片\n该功能还在建设……\n\n";
				if(!myAlbum.SearchPhoto())
				{
					cout << "未能找到该图片！" << endl;
				}
				break;
			}
		case 4: // [4]删除照片
			{
				std::cout<<"\n你选择执行[4]删除照片\n该功能还在建设……\n\n";
				if(!myAlbum.DeletePhoto())
				{
					cout << "删除失败！" << endl;
				}
				break;
			}
		case 5: // [5]修改照片
			{
				std::cout<<"\n你选择执行[5]修改照片\n该功能还在建设……\n\n";
				if(!myAlbum.ModifyPhoto())
				{
					cout << "修改失败！" << endl;
				}
				break;
			}
		case 0: std::cout<<"\n谢谢使用！\n\n"<<endl; break;
		}

		system("pause");
	} while (choice != 0);
}

int menu()
{
	system("cls");
	std::cout<<"====================\n";
	std::cout<<"     瓦瓦的相册\n";
	std::cout<<"      ver  1.0\n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]显示全部照片\n";
	std::cout<<"[2]添加照片\n";
	std::cout<<"[3]查找照片\n";
	std::cout<<"[4]删除照片\n";
	std::cout<<"[5]修改照片\n";
	std::cout<<"[0]退出\n";
	std::cout<<"====================\n";
	
	std::cout<<"请选择要执行的功能：\n";
	int choice;
	std::cin>>choice;
	while (choice<0 || choice>5)
	{
		std::cout<<"输入错误。请重新选择要执行的功能（1~5），输入0退出：\n";
		std::cin>>choice;
	}

	return choice;
}