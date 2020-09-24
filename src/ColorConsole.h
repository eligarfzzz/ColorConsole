#pragma once
#include<Windows.h>
#include<string>
#include<iostream>
namespace ColorConsole {
	/**
	 * @brief 通过构造函数设置rbg颜色
	 *		  如红色为ConsoleColor(1,0,0),青色为ConsoleColor(0,1,1)
	*/
	class ConsoleColor
	{
	private:
		DWORD _color = 0;
	public:
		ConsoleColor(bool needRed, bool needGreen, bool needBlue)
		{
			_color = ((DWORD)needRed) << 2 | ((DWORD)needGreen) << 1 | ((DWORD)needBlue);
		}
		DWORD GetDWORDColor()
		{
			return _color;
		}
	};
	/**
	 * @brief 将控制台颜色重置为黑底白字
	*/
	void DefaultConsoleColor()
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			ConsoleColor(1, 1, 1).GetDWORDColor() | ConsoleColor(0, 0, 0).GetDWORDColor() << 4
		);
	}
	/**
	 * @brief 控制台输出彩色文字和背景
	 * @param text 需要输出的文字
	 * @param foregroundColor 字体颜色
	 * @param backgroundColor 背景颜色
	*/
	void ColorPrintA(std::string text, ConsoleColor foregroundColor, ConsoleColor backgroundColor)
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			foregroundColor.GetDWORDColor() | backgroundColor.GetDWORDColor() << 4
		);
		std::cout << text;
		DefaultConsoleColor();
	}
	/**
	 * @brief ColorPrintA的Unicode版本
	 * @param text 需要输出的文字
	 * @param foregroundColor 字体颜色
	 * @param backgroundColor 背景颜色
	*/
	void ColorPrintW(std::wstring text, ConsoleColor foregroundColor, ConsoleColor backgroundColor)
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			foregroundColor.GetDWORDColor() | backgroundColor.GetDWORDColor() << 4
		);
		std::wcout << text;
		DefaultConsoleColor();
	}
#ifdef UNICODE
#define ColorPrint ColorPrintW
#else
#define ColorPrint ColorPrintA
#endif // DEBUG
}

