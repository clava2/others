//
//	�������Ӧ�ó���
//
//	Created by ZhangHua @ 2015-10
//  2017-10 �����������޸ĳ�ʼ��ʾ��
//
//  �밴��ҵҪ�����Ӧ�ó������ƺ�ʵ�֡�

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XAlbum.h"

// ��ʾ����������Ĺ��ܲ˵�������ȡ�û�ѡ��ִ�еĹ�����
// ����ֵ���û�ѡ��Ĺ�������
int menu();

// ��������������غ���
void main()
{
	XAlbum myAlbum; // ������

	int choice; // �����û�ѡ��Ĺ�������
	do
	{
		// ��ʾ�˵�����ȡҪִ�еĹ�����
		choice = menu();

		// ���ݹ�������ִ����Ӧ�Ĳ���
		switch (choice)
		{
		case 1: // [1]��ʾȫ����Ƭ�б�
			{
				std::cout<<"\n��ѡ��ִ��[1]��ʾȫ����Ƭ\n�ù��ܻ��ڽ��衭��\n\n";
				myAlbum.ShowAllPhotos();
				break;
			}
		case 2: // [2]�����Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[2]�����Ƭ\n�ù��ܻ��ڽ��衭��\n\n";
				if(!myAlbum.AddPhoto())
				{
					cout << "���ʧ�ܣ������ǿռ����������100��������ϵͳ�޷������ڴ棬�����ԣ�" << endl;
				}
				break;
			}
		case 3: // [3]������Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[3]������Ƭ\n�ù��ܻ��ڽ��衭��\n\n";
				if(!myAlbum.SearchPhoto())
				{
					cout << "δ���ҵ���ͼƬ��" << endl;
				}
				break;
			}
		case 4: // [4]ɾ����Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[4]ɾ����Ƭ\n�ù��ܻ��ڽ��衭��\n\n";
				if(!myAlbum.DeletePhoto())
				{
					cout << "ɾ��ʧ�ܣ�" << endl;
				}
				break;
			}
		case 5: // [5]�޸���Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[5]�޸���Ƭ\n�ù��ܻ��ڽ��衭��\n\n";
				if(!myAlbum.ModifyPhoto())
				{
					cout << "�޸�ʧ�ܣ�" << endl;
				}
				break;
			}
		case 0: std::cout<<"\nллʹ�ã�\n\n"<<endl; break;
		}

		system("pause");
	} while (choice != 0);
}

int menu()
{
	system("cls");
	std::cout<<"====================\n";
	std::cout<<"     ���ߵ����\n";
	std::cout<<"      ver  1.0\n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]��ʾȫ����Ƭ\n";
	std::cout<<"[2]�����Ƭ\n";
	std::cout<<"[3]������Ƭ\n";
	std::cout<<"[4]ɾ����Ƭ\n";
	std::cout<<"[5]�޸���Ƭ\n";
	std::cout<<"[0]�˳�\n";
	std::cout<<"====================\n";
	
	std::cout<<"��ѡ��Ҫִ�еĹ��ܣ�\n";
	int choice;
	std::cin>>choice;
	while (choice<0 || choice>5)
	{
		std::cout<<"�������������ѡ��Ҫִ�еĹ��ܣ�1~5��������0�˳���\n";
		std::cin>>choice;
	}

	return choice;
}