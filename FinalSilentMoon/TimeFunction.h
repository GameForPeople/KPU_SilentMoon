//#pragma once
#ifndef __TIMEFUNCTION_H_
#define __TIMEFUNCTION_H_

#define TIME_RATE 60 // ���� Ÿ�̸��� ���� 60���� �մϴ�.

class TimeClass {
	int m_timeRate;
public:
	TimeClass() : m_timeRate(TIME_RATE) {

	}
	int GetTimer() const {
		return this->m_timeRate;
	}
	void SetTimer() {

	}
	void TimeFunc();
};

#endif // !__TIMEFUNCTION_H_
