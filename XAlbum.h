//
//	����������
//	�����
//
//	Created by ZhangHua @ 2015-10
//  2017-10 ����ShowAllPhotos��AddPhoto����������
//
//  �밴��ҵҪ�������������ƺ�ʵ�֡�

#ifndef _XALBUM_H_
#define _XALBUM_H_

#include "XList.h"
#include "XPhoto.h"

class XAlbum
{
protected:
	XList m_photo_list; // ���б��������������е���Ƭ

	// �ں���������ĳ�Ա����
public:
	// ��ʾȫ����Ƭ
	void ShowAllPhotos();

	// �����Ƭ
	bool AddPhoto();

	//������Ƭ
	bool SearchPhoto();

	//ɾ����Ƭ
	bool DeletePhoto();

	//�޸�ͼƬ
	bool ModifyPhoto();
};

#endif