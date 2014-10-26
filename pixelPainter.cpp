


#include "pixelPainter.h"



#define PI 3.1415


using namespace std;

//I've got no idea...

//http://stackoverflow.com/questions/12378642/c-pixels-in-console-window

//HBITMAP CreateDIBSection(
// HDC hdc,         // handle to DC
// CONST BITMAPINFO *pbmi, // bitmap data
// UINT iUsage,       // data type indicator
// VOID **ppvBits,     // bit values
// HANDLE hSection,     // handle to file mapping object
// DWORD dwOffset      // offset to bitmap bit values
//);

int screenSizeChange(int x, int y, int xSize, int ySize)
{
    
//SetWindowPos()
    
    
    
    
    
    
}


int screenDraw(unsigned char *drawing_bytes, struct xyPair window, HDC mydc)
{

   //if ((!window.xSize) || (!window.ySize)) return;
   if ((!window.x) || (!window.y)) return 0;
   BITMAPINFO info;
   info.bmiHeader.biSize = sizeof (info.bmiHeader);
   info.bmiHeader.biWidth = window.x;//Size;
   info.bmiHeader.biHeight = window.y;//Size;
   info.bmiHeader.biPlanes = 1;
   info.bmiHeader.biBitCount = 24; // 24 bits per pixel - one unsigned char for each pixel
   info.bmiHeader.biCompression = BI_RGB;
   info.bmiHeader.biSizeImage = 0;
   info.bmiHeader.biClrUsed = 0;
   info.bmiHeader.biClrImportant = 0;
   HDC cDC = CreateCompatibleDC (mydc); // this is the GetDC (hwnd) where hwnd is the
                                        // handle of the window I want to write to
   HBITMAP hbmp = CreateCompatibleBitmap  (cDC, window.x, window.y);
   SetDIBits (cDC, hbmp, 0, window.y, drawing_bytes, &info, DIB_RGB_COLORS);
   hbmp = (HBITMAP) SelectObject (cDC, hbmp);
   BitBlt (cDC, 0, 0, window.x, window.y, cDC, 0, 0, SRCCOPY);
   DeleteObject (SelectObject(cDC, hbmp));
   DeleteDC (cDC);
}


int pixelPaint(HWND myConsole) 
{
   AllocConsole();
   FreeConsole();
   DWORD consoleThing;
   
   HBITMAP hBitmap;
   BITMAPINFO* m_Bit;
   //CBitmap m_OffscreenBitmap, *m_pOldBitmap;
   //FIBITMAP* m_dib;
   
   //ATOM aso;
   //Get a console handle
}
   
   
   
//   HBITMAP CreateBitmap(
//  _In_  int nWidth,
//  _In_  int nHeight,
//  _In_  UINT cPlanes,
//  _In_  UINT cBitsPerPel,
//  _In_  const VOID *lpvBits
//);
//   
//   
//   CreateDIBSection(mydc, m_Bit, DIB_RGB_COLORS, (void**)&m_pBits, NULL, 0)
//   m_OffscreenBitmap.Attach(hBitmap);
//   m_pOldBitmap = m_dcOffscreen.SelectObject(&m_OffscreenBitmap);
//   //hBitmap=(HBITMAP) LoadImage(NULL, _T("c:\\Temp\\Temp.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//   
//   int pixel =0;
//
//   //Choose any color
//   COLORREF COLOR = RGB(255,255,255); 
//
//   //Draw pixels
//   for(double i = 0; i < PI * 4; i += 0.05)
//   {
//      SetPixel(mydc,pixel,12,COLOR);
//      pixel+=1;
//   }
//
//   ReleaseDC(myConsole, mydc);
//   cin.ignore();
//   return 0;
//}
   
   
   
int pixelController()
{
   char name[62];
   int thingy = GetConsoleTitle(name, 62);
   HWND myConsole;    
   myConsole = FindWindow(NULL, name);
   //Get a handle to device context
   HDC mydc = GetDC(myConsole);
    
    
    
    
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
