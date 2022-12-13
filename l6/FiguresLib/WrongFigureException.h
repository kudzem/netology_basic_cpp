#pragma once

#pragma once

#pragma once

class ZeroSidesException : public std::exception {
public:
	virtual const char* what() const noexcept override { return "Количество сторон фигуры равно 0"; }
};

class WrongFigureCorners : public std::exception {
public:
	virtual const char* what() const noexcept override { return "Сумма углов не соотвествует количеству сторон"; }
};