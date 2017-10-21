//
//	个人相册程序
//	相册类
//
//	Created by ZhangHua @ 2015-10
//  2017-10 增加ShowAllPhotos和AddPhoto函数的声明
//
//  请按作业要求完成相册类的设计和实现。

#ifndef _XALBUM_H_
#define _XALBUM_H_

#include "XList.h"
#include "XPhoto.h"

class XAlbum
{
protected:
	XList m_photo_list; // 用列表对象来保存相册中的照片

	// 在后面添加相册的成员函数
public:
	// 显示全部照片
	void ShowAllPhotos();

	// 添加照片
	bool AddPhoto();

	//查找照片
	bool SearchPhoto();

	//删除照片
	bool DeletePhoto();

	//修改图片
	bool ModifyPhoto();
};

#endif