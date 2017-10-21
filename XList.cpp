//
//	列表类
//
//	Created by ZhangHua @ 2014-10
//  2017-10 定义部分成员函数；增加部分成员函数的初始空白定义。
//
//  请按作业要求完成列表类的设计和实现。

#include "XList.h"

XList::XList()
{
	Initialize();
}

void XList::Initialize()
{
	m_items = 0;
}

bool XList::IsEmpty()
{
	if (m_items==0)
		return true;
	else
		return false;
}

bool XList::IsFull()
{
	if (m_items>=LISTSIZE)
		return true;
	else
		return false;
}

int XList::ItemCount()
{
	return m_items;
}

bool XList::AppendItem(Item &item)
{
	// 添加代码

	if(IsFull())
	{
		return false;
	}

	Item* newItem = new Item();

	if(!newItem)
	{
		return false;
	}

	*newItem = item;

	newItem->m_id = newItem->GenerateID();

	m_entries[m_items] = *newItem;
	m_items ++;
	return true;
}

bool XList::GetItem(int idx, Item &item)
{
	// 添加代码

	if((idx > m_items)||(idx < 0))
	{
		return false;
	}

	item = m_entries[idx];

	return true;
}

bool XList::DeleteItem(int idx)
{
	// 添加代码

	if((idx > m_items)||(idx < 0))
	{
		return false;
	}

	for(int i = idx;i != m_items-1;++i)
	{
		m_entries[i] = m_entries[i + 1];
	}

	m_items --;

	return true;
}

bool XList::UpdateItem(int idx, const Item &item)
{
	// 添加代码

	if((idx > m_items)||(idx < 0))
	{
		return false;
	}

	m_entries[idx] = item;

	return true;
}

void XList::Traverse(void (*pFun)(Item &item))
{
	// 添加代码
	for(int i = 0;i = m_items;++i)
	{
		(*pFun)(m_entries[i]);
	}
}

void XList::Clear()
{
	m_items = 0;
}

int XList::GetIndexByID(int ID)
{
	for(int i = 0;i != m_items;++i)
	{
		if(ID == m_entries[i].m_id)
		{
			return i;
		}
	}
	return -1;
}