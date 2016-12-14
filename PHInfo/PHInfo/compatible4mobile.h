#pragma once
#include <afxwin.h>
#include <map>
using namespace std;

class CCompatibleFont
{
public:
	static CFont BigFont;
	static CFont ListFont;
	static CFont TreeFont;
	static CFont NormalFont;
	static CFont TimerFont;
	static CFont NoteFont;
	static CFont TinyFont;
	static CFont SontiFont;
public:
	static BOOL InitFonts();
};
