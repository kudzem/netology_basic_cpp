#pragma once

#pragma once

#pragma once

class ZeroSidesException : public std::exception {
public:
	virtual const char* what() const { return "���������� ������ ������ ����� 0"; }
};

class WrongFigureCorners : public std::exception {
public:
	virtual const char* what() const { return "����� ����� �� ������������ ���������� ������"; }
};