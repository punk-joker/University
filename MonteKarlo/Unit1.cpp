//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
double round(double src, int rank)
{
 double ret,nret,r5=5,r1=1;
 int rnk;
 rnk=rank*10;
 r5=r5/rnk;
 r1=r1/rank;
 nret=floor(src*rnk)/rnk;
 ret=floor(src*rank)/rank;
 if(fabs(nret-ret)>=r5)
  {
   ret+=r1;
  }
 return ret;
}
//---------------------------------------------------------------------------
double random(double y1, double y2)
{
	double x, y, k, b;
	b = y1;
	k = y2 - b;
	x = rand()/(RAND_MAX+1.0);
	y = k * x + b;
	return y;
}
//---------------------------------------------------------------------------
double func(double x)
{
	return -pow(x, 2)+2*x+x+19;
}
//---------------------------------------------------------------------------
void MonteKarlo(double a, double b, int k, int e, double *xx, int *DrawInd)
{
	int i;
	double x, xi;
	Form1->Chart1->Series[1]->Clear();
	srand(time(NULL));
	x = round(random(a, b), e*100);
	for (i = 0; i < k; i++) {
		xi = round(random(a, b), pow(10, e));
		Form1->Chart1->Series[1]->AddXY(xi,func(xi), "", clRed);
		if (func(x) < func(xi)) {
			x = xi;
		}
	}

	*DrawInd = Form1->Series2->AddXY(x,func(x), "", clGreen);
	*xx = x;

	Form1->Chart1->Refresh();
}
//---------------------------------------------------------------------------
void Graph(int a, int b)
{
	int i;
	Form1->Chart1->Series[0]->Clear();
	for (i = a; i < b*2+1; i++) {
		Form1->Chart1->Series[0]->AddXY(i,func(i), "");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AfterDraw(TObject *Sender)
{
	UnicodeString s;
	if (DrawIndex > -1)
	{
		Form1->Chart1->Canvas->Font->Color = clRed;
		Form1->Chart1->Canvas->DoVertLine(Form1->Series2->CalcXPos(DrawIndex), Form1->Series2->CalcYPos(DrawIndex), Form1->Chart1->LeftAxis->IEndPos);
		s = FloatToStr(round(Form1->Series2->XValue[DrawIndex], 10000));
		Form1->Chart1->Canvas->TextOutW((Form1->Series2->CalcXPos(DrawIndex) - (Form1->Chart1->Canvas->TextWidth(s)/2)), Form1->Chart1->LeftAxis->IEndPos+20, s);
		Form1->Chart1->Canvas->DoHorizLine(Form1->Series2->CalcXPos(DrawIndex), Form1->Chart1->BottomAxis->IStartPos, Form1->Series2->CalcYPos(DrawIndex));
		s = FloatToStr(round(Form1->Series2->YValue[DrawIndex], 10000));
		Form1->Chart1->Canvas->TextOutW((Form1->Chart1->BottomAxis->IStartPos - Form1->Chart1->Canvas->TextWidth(s) - 20), (Form1->Series2->CalcYPos(DrawIndex) - (Form1->Chart1->Canvas->TextHeight(s)/2)), s);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->Series1->LinePen->Width = 2;
	Form1->Chart1->Series[1]->Pen->Hide();
	Form1->Chart1->AllowPanning = pmBoth;
	DrawIndex = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	int iter, y, e, i;
	double a, b, x;
	a = StrToFloat(Edit1->Text);
	b = StrToFloat(Edit2->Text);
	iter = StrToInt(Edit3->Text);
	e = StrToInt(Edit6->Text);
	Graph(a, b);
	MonteKarlo(a, b, iter, e, &x, &DrawIndex);
	Edit4->Text = FloatToStr(x);
	Edit5->Text = FloatToStr(func(x));
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
