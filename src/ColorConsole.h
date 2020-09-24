#pragma once
#include<Windows.h>
#include<string>
#include<iostream>
namespace ColorConsole {
	/**
	 * @brief ͨ�����캯������rbg��ɫ
	 *		  ���ɫΪConsoleColor(1,0,0),��ɫΪConsoleColor(0,1,1)
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
	 * @brief ������̨��ɫ����Ϊ�ڵװ���
	*/
	void DefaultConsoleColor()
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			ConsoleColor(1, 1, 1).GetDWORDColor() | ConsoleColor(0, 0, 0).GetDWORDColor() << 4
		);
	}
	/**
	 * @brief ����̨�����ɫ���ֺͱ���
	 * @param text ��Ҫ���������
	 * @param foregroundColor ������ɫ
	 * @param backgroundColor ������ɫ
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
	 * @brief ColorPrintA��Unicode�汾
	 * @param text ��Ҫ���������
	 * @param foregroundColor ������ɫ
	 * @param backgroundColor ������ɫ
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

