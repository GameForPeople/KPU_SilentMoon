//#pragma once
#ifndef __TIMEFUNCTION_H_
#define __TIMEFUNCTION_H_

#define TIME_RATE 60 // 기준 타이머의 값을 60으로 합니다.

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
