/*
 * Employee.h
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>

using namespace std;

enum ENUM_EMPLOYEE_LEVEL
{
	ENUM_EMPLOYEE_LEVEL_MIN = 0,
	ENUM_EMPLOYEE_LEVEL_PARTTIME_TEC,   //兼职技术人员
	ENUM_EMPLOYEE_LEVEL_MANAGER_TEC,    //技术经理
	ENUM_EMPLOYEE_LEVEL_PARTTIME_SALE,  //兼职销售人员
	ENUM_EMPLOYEE_LEVEL_MANAGER_SALE,   //销售经理
	ENUM_EMPLOYEE_LEVEL_BOSS,           //老板
	ENUM_EMPLOYEE_LEVEL_MAX = 0x00ffffff
};

typedef unsigned int uint;

class Employee {
public:
	Employee(string strName = "NewEmployee"
			 , uint uiLevel = ENUM_EMPLOYEE_LEVEL_MIN);
	virtual ~Employee();

	// 显示信息
	void info();
	//密码修改
	void modifyPwd();
	//设置起始增长id
	void setBaseId(uint uiId);
	//获得员工id
	uint getId();

private:
	static uint m_suiId;
	uint m_uiId;            //员工编号
	string m_strPwd;        //登入密码
	string m_strName;       //姓名
	uint m_uiLevel;         //级别
	string m_strNote;       //备注
};

int Employee::m_suiId = 10000;

#endif /* EMPLOYEE_H_ */
