#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
namespace ColorConsole
{
	/**
	 * @brief 通过构造函数设置rbg颜色
	 *		  如红色为ConsoleColor(1,0,0),青色为ConsoleColor(0,1,1)
	*/
	class ConsoleColor
	{
	private:
		WORD _color = 0;

	public:
		/**
		* @brief 通过构造函数设置rbg颜色。
		*		 win32api只支持8位颜色，所以使用bool输入参数
		* 
		* @param needRed 红色
		* @param needGreen 绿色
		* @param needBlue 蓝色
		*/
		ConsoleColor(bool needRed, bool needGreen, bool needBlue)
		{
			_color = ((WORD)needRed) << 2 | ((WORD)needGreen) << 1 | ((WORD)needBlue);
		}
		WORD GetWORDColor()
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
			ConsoleColor(1, 1, 1).GetWORDColor() | ConsoleColor(0, 0, 0).GetWORDColor() << 4);
	}
	/**
	 * @brief 控制台输出彩色文字和背景
	 * 
	 * @param text 需要输出的文字
	 * @param foregroundColor 字体颜色
	 * @param backgroundColor 背景颜色
	*/
	void ColorPrintA(std::string text, ConsoleColor foregroundColor, ConsoleColor backgroundColor)
	{
		// 修改颜色
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			foregroundColor.GetWORDColor() | backgroundColor.GetWORDColor() << 4);
		std::cout << text;
		// 重置为黑底白字颜色
		DefaultConsoleColor();
	}
	/**
	 * @brief ColorPrintA的Unicode版本
	 * 
	 * @param text 需要输出的文字
	 * @param foregroundColor 字体颜色
	 * @param backgroundColor 背景颜色
	*/
	void ColorPrintW(std::wstring text, ConsoleColor foregroundColor, ConsoleColor backgroundColor)
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			foregroundColor.GetWORDColor() | backgroundColor.GetWORDColor() << 4);
		std::wcout << text;
		DefaultConsoleColor();
	}
#ifdef UNICODE
#define ColorPrint ColorPrintW
#else
#define ColorPrint ColorPrintA
#endif
} // namespace ColorConsole
