#pragma once

#ifdef FIGURELIB_EXPORTS
#define FIGURELIB_API __declspec(dllexport)
#else
#define FIGURELIB_API __declspec(dllimport)
#endif

class ZeroSidesException : public std::exception {
public:
	FIGURELIB_API
	virtual const char* what() const noexcept override { return "Количество сторон фигуры равно 0"; }
};

class WrongFigureCorners : public std::exception {
public:
	FIGURELIB_API
	virtual const char* what() const noexcept override { return "Сумма углов не соотвествует количеству сторон"; }
};