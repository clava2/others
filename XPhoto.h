//
//	����������
//	��Ƭ��
//
//	Created by ZhangHua @ 2015-10
//
//  �밴��ҵҪ�������Ƭ�����ƺ�ʵ�֡�

#ifndef _XPHOTO_H_
#define _XPHOTO_H_

#define TITLESIZE 256 // ��ű�������鳤��
#define DESCRSIZE 1024 // ���˵�������鳤��
#define DATETIMESIZE 20 // ���ʱ���ַ��������鳤��
#define PLACESIZE 40	//����λ���ַ����鳤��

// ��Ƭ

class XPhoto
{
public:
	unsigned int m_id; // ��ѡ���ԣ���Ƭ��ţ�����Ψһ��ʶһ����Ƭ����������Լ����һ���Զ���ŵ��㷨��

	char m_title[TITLESIZE]; // ����
	char m_descr[DESCRSIZE]; // ˵��
	char m_add_datetime[DATETIMESIZE]; // �޸�ʱ��

	// �����ں��������������

	char m_create_datetime[DATETIMESIZE];  //����ʱ��

	char m_create_place[PLACESIZE];

	// �����ں�����Ӳ�������
public:

	/**only for debug usr*/

	void show();

	int GenerateID();

};

#endif