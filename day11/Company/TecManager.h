/*
 * TecManager.h
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#ifndef TECMANAGER_H_
#define TECMANAGER_H_

#include "TecPartTime.h"

class TecManager: public TecPartTime
{
public:
	TecManager(string strName = "NewTecMa", float fSalary = 10000);
	virtual ~TecManager();

	//显示信息
	void info();
	//设置经理的工资
	void setSalary();

	float getSalary() const
	{
		return m_fSalary;
	}

	float& getSalary()
	{
		return m_fSalary;
	}

	//对下属员工的增删改查
	void addTecPartTime(uint uiId = 0);
	void delTecPartTimeById(uint uiId = 0);
	void modifyTecPartTime(uint uiId = 0);
	TecPartTime* findTecPartTime(uint uiId = 0);
	void displayTecPartTimeInfo();

	void work();

private:
	float m_fSalary;
};

#endif /* TECMANAGER_H_ */
