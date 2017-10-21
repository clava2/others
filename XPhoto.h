//
//	个人相册程序
//	照片类
//
//	Created by ZhangHua @ 2015-10
//
//  请按作业要求完成照片类的设计和实现。

#ifndef _XPHOTO_H_
#define _XPHOTO_H_

#define TITLESIZE 256 // 存放标题的数组长度
#define DESCRSIZE 1024 // 存放说明的数组长度
#define DATETIMESIZE 20 // 存放时间字符串的数组长度
#define PLACESIZE 40	//拍摄位置字符数组长度

// 照片

class XPhoto
{
public:
	unsigned int m_id; // 可选属性：照片编号（用来唯一标识一张照片）。最好是自己设计一个自动编号的算法。

	char m_title[TITLESIZE]; // 标题
	char m_descr[DESCRSIZE]; // 说明
	char m_add_datetime[DATETIMESIZE]; // 修改时间

	// 可以在后面添加其他属性

	char m_create_datetime[DATETIMESIZE];  //创建时间

	char m_create_place[PLACESIZE];

	// 可以在后面添加操作函数
public:

	/**only for debug usr*/

	void show();

	int GenerateID();

};

#endif