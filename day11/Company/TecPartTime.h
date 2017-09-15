/*
 * TecPartTime.h
 *
 *  Created on: 2017-8-31
 *      Author: sq
 */

#ifndef TECPARTTIME_H_
#define TECPARTTIME_H_

#include "Employee.h"

class TecPartTime: virtual public Employee
{
public:
	TecPartTime(string strName = "NewTecPP", uint uiLevel =
			ENUM_EMPLOYEE_LEVEL_PARTTIME_TEC, float fPerHourPay = 50);
	virtual ~TecPartTime();

	//设置工作时间
	void setWorkHour();

	//显示信息
	void info();
	//设置所属上级
	void setLeader(uint uiLeaderId);
	//获得其领导
	uint getLeader() const;
	uint& getLeader();

	uint getWorkHour() const;
	uint& getWorkHour();

	float getPerHourPay() const;
	float& getPerHourPay();

	void work();

private:
	uint m_uiWorkHour;
	float m_fPerHourPay;
	uint m_uiLeaderId;
};

#endif /* TECPARTTIME_H_ */
