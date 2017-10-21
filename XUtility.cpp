//
//	公用工具类
//  此类提供了一组实用的功能函数。
//
//	Created by ZhangHua @ 2015-04

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#include "XUtility.h"

void XUtility::GetCurDateTime(char *dt)
{
	if (dt==NULL)
		return;

	time_t t = time(NULL);
    char tmp[20];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %X", localtime(&t));
	strcpy(dt, tmp);
}