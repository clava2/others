//
//	����������
//	��Ƭ��
//
//	Created by ZhangHua @ 2015-10
//
//  �밴��ҵҪ�������Ƭ���ʵ�֡�

#include "XPhoto.h"
#include <iostream>
using std::cout;
using std::endl;


void XPhoto::show()
{
	cout << "\tid = " << m_id << endl;
	cout << "\ttitle = " << m_title << endl;
	cout << "\tdescri = " << m_descr << endl;
	cout << "\tadd_datetime = " << m_add_datetime << endl;
	cout << "\tcreate_datetime = " << m_create_datetime << endl;
	cout << "\tcreate_place = " << m_create_place << endl;
}

int XPhoto::GenerateID()
{
	static int id = 0;
	id ++;
	return id;
}