//#pragma once
#ifndef __KEYBOARDFUNCTION_H_
#define __KEYBOARDFUNCTION_H_

class KeyboardClass {
	unsigned char m_key;
	int m_specialKey;

public:
	KeyboardClass() : m_key(NULL), m_specialKey(NULL) {};
	~KeyboardClass() {};
	
	unsigned char GetKey() const {
		return this->m_key;
	}

	int GetSpceialKey() const {
		return this->m_specialKey;
	}

	void SetKey(const unsigned char insertKey) {
		this->m_key = insertKey;
	}

	void SetSpecialKey(const int insertSpecialKey) {
		this->m_specialKey = insertSpecialKey;
	}
};
#endif // !__KEYBOARDFUNCTION_H_
