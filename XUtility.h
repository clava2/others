//
//	公用工具类
//  此类提供了一组实用的功能函数。
//
//	Created by ZhangHua @ 2015-04
//
//  根据需要自己添加新函数。

#ifndef _XUTILITY_H_
#define _XUTILITY_H_

class XUtility
{
public:
	// 获取当前系统时间，转换为字符串（格式为 YYYY-MM-DD hh:mm:ss），并保存到 dt 指向的字符数组
	void GetCurDateTime(char *dt);
};

#endif