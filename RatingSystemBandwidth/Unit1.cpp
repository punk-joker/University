//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int count;
int **mtx;
int **mtx_bool;

int Number_of_vertices = 0;
int ACol_glob;
int ARow_glob;
int step = 1;
int flag = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
void mtx_bool_create()
{
  int i;
  mtx_bool = new int*[Number_of_vertices + 1];
  for (i = 0; i < Number_of_vertices + 1; i++)
  {
	mtx_bool[i] = new int[Number_of_vertices + 1];
  }
}

void mtx_bool_init()
{
  int i, j;
  for (i = 0; i < Number_of_vertices + 1; i++)
  {
	for (j = 0; j < Number_of_vertices + 1; j++) {
	  mtx_bool[i][j] = 0;
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CreateMatrix()
{
  int i;
  Form1->matrix = new int*[Number_of_vertices + 1];
  for (i = 0; i < Number_of_vertices + 1; i++)
  {
	Form1->matrix[i] = new int[Number_of_vertices + 1];
  }
  Form1->matrix2 = new int*[Number_of_vertices + 1];
  for (i = 0; i < Number_of_vertices + 1; i++)
  {
	Form1->matrix2[i] = new int[Number_of_vertices + 1];
  }
  Form1->column_status = new String[Number_of_vertices + 1];
  for (i = 0; i < Number_of_vertices; i++) {
    Form1->column_status[i] = "-1";
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TitleGrid()
{
  int i;
  for (i = 0; i < Number_of_vertices; i++) {
	Form1->StringGrid1->Cells[0][i+1] = "E"+IntToStr(i);
	Form1->StringGrid1->Cells[i+1][0] = "E"+IntToStr(i);
	Form1->StringGrid3->Cells[0][i+1] = "E"+IntToStr(i);
	Form1->StringGrid3->Cells[i+1][0] = "E"+IntToStr(i);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ReadFile()
{
  TStringList *tsl=new TStringList;
  tsl->LoadFromFile(Form3->Edit2->Text);
  Form1->StringGrid1->RowCount=tsl->Count+1;
  Form1->StringGrid3->RowCount=tsl->Count+1;
  AnsiString st=tsl->Strings[0];
  int i,col=0;
  for(i=1;i<=st.Length();i++)  if(st[i]==' ') {
	col++;
	Number_of_vertices++;
  }
  Form1->StringGrid1->ColCount=col+2;
  Form1->StringGrid3->ColCount=col+2;
  Number_of_vertices++;

  for( i=0;i<Form1->StringGrid1->RowCount-1;i++)
	for(int j=0;j<Form1->StringGrid1->ColCount;j++)
	{
	  if(tsl->Strings[i].Pos(" "))
	  {
		Form1->StringGrid1->Cells[j+1][i+1]=tsl->Strings[i].SubString(1,tsl->Strings[i].Pos(" ") - 1);
		Form1->StringGrid3->Cells[j+1][i+1]=tsl->Strings[i].SubString(1,tsl->Strings[i].Pos(" ") - 1);
	  }
	  else
	  {
		Form1->StringGrid1->Cells[j+1][i+1]= tsl->Strings[i];
		Form1->StringGrid3->Cells[j+1][i+1]= tsl->Strings[i];
	  }
	  tsl->Strings[i]=  tsl->Strings[i].SubString(tsl->Strings[i].Pos(" ") + 1,tsl->Strings[i].Length());
	}
}
//---------------------------------------------------------------------------
void ReadMatrix()
{
	int i,j;
	for (i = 0; i < Number_of_vertices+1; i++) {
	  for (j = 0; j < Number_of_vertices+1; j++) {
		if (Form1->StringGrid1->Cells[i+1][j+1] == "") {
		  Form1->matrix[j][i] = -1;
		}
		else {
		  Form1->matrix[j][i] = StrToInt(Form1->StringGrid1->Cells[i+1][j+1]);
		}
	  }
	}
    for (i = 0; i < Number_of_vertices+1; i++) {
	  for (j = 0; j < Number_of_vertices+1; j++) {
		if (Form1->StringGrid1->Cells[i+1][j+1] == "") {
		  Form1->matrix2[j][i] = -1;
		}
		else {
		  Form1->matrix2[j][i] = StrToInt(Form1->StringGrid1->Cells[i+1][j+1]);
		}
	  }
	}
	for (i = 1; i < Number_of_vertices+1; i++)
	  for (j = 1; j < Number_of_vertices+1; j++)
        Form1->StringGrid3->Cells[i][j] = Form1->StringGrid1->Cells[i][j];
}
//---------------------------------------------------------------------------
void UpdateStrigGrid()
{
	int i,j;
	for (i = 0; i < Number_of_vertices+1; i++) {
	  for (j = 0; j < Number_of_vertices+1; j++) {
		if (Form1->matrix[j][i] != -1) {
			Form1->StringGrid3->Cells[i+1][j+1] = IntToStr(Form1->matrix[j][i]);
		}
		else Form1->StringGrid3->Cells[i+1][j+1] = "";
	  }
	}
}
//---------------------------------------------------------------------------
int mark_column()
{
  //помечаем столбцы
  int i, j;
  Form1->column_status[0] = '*';
  for (i = 0; i < Number_of_vertices; i++) {
	for (j = 0; j < Number_of_vertices; j++) {
	  if (Form1->matrix[i][j] > 0 && Form1->column_status[j] == "-1") {
		Form1->column_status[j] = i;
	  }
	}
  }
  if (Form1->column_status[3] == "-1" || Form1->column_status[4] == "-1") {
	return 0;
  }
  else {
	for (i = 0; i < Number_of_vertices; i++) {
		Form1->StringGrid2->Cells[i][0] = Form1->column_status[i];
	}
	return 1;
  }
}
//---------------------------------------------------------------------------
void Calculation()
{
    mtx_bool_create();
	Form1->Edit2->Text = "";
	int min, i;
	count = 1;
	mtx_bool_init();
	int *array =(int*) malloc (count * sizeof (int));
	mtx=(int**)malloc(count*sizeof(int*));
	int **mtx_pl=(int**)malloc(count*sizeof(int*));
	int strng = StrToInt(Form1->column_status[Number_of_vertices-1]);
	int column = Number_of_vertices-1;
	mtx[count-1]=(int*)malloc(2*sizeof(int));
	mtx_pl[count-1]=(int*)malloc(2*sizeof(int));
	while (1)
	{
		mtx[count-1][0] = strng;
		mtx[count-1][1] = column;
		mtx_bool[column][strng] = 1;
		if (Form1->Edit2->Text == "") {
		  Form1->Edit2->Text = Form1->StringGrid3->Cells[0][column+1] + Form1->Edit2->Text;
		}
		else {
		  Form1->Edit2->Text = Form1->StringGrid3->Cells[0][column+1] + " - " + Form1->Edit2->Text;
		}
		mtx_pl[count-1][0] = column;
		mtx_pl[count-1][1] = strng;
		array[count-1] = Form1->matrix[strng][column];
		if (strng == 0) {
			break;
		}
		column = strng;
		strng = StrToInt(Form1->column_status[strng]);
		count++;
		array = (int*) realloc (array, count * sizeof (int));
		mtx=(int**)realloc((void *) mtx,(count)*sizeof(int*));
		mtx[count-1]=(int*)malloc(2*sizeof(int));
		mtx_pl=(int**)realloc((void *) mtx_pl,(count)*sizeof(int*));
		mtx_pl[count-1]=(int*)malloc(2*sizeof(int));
	}
	Form1->Edit2->Text = Form1->StringGrid3->Cells[0][1] + " - " + Form1->Edit2->Text;
	min = array[0];
	for (i = 1; i < count; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	Form1->Edit3->Text = IntToStr(min);
	for (i = 0; i < count; i++) {
		Form1->matrix[mtx[i][0]][mtx[i][1]] = Form1->matrix[mtx[i][0]][mtx[i][1]] - min;
	}
}
//---------------------------------------------------------------------------
void prop()
{
	int i,j;
	for (i = 0; i < Number_of_vertices; i++) {
	  for (j = 0; j < Number_of_vertices; j++) {
		if (Form1->matrix[i][j] != -1) {
			Form1->matrix[i][j] = Form1->matrix2[i][j] - Form1->matrix[i][j];
		}
	  }
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	Form1->CreateMatrix();
	ReadMatrix();
	int i, j, p;
	i = 0;
	if (Form1->N10->Checked) {
		  Form1->StringGrid3->Visible = True;
		  Form1->StringGrid2->Visible = True;
		  Form1->Edit2->Visible = True;
		  Form1->Label5->Visible = True;
		  Form1->Edit3->Visible = True;
		  Form1->Label6->Visible = True;
		  Form1->Edit1->Visible = False;
		  Form1->Label1->Visible = False;
		  Form1->Label7->Visible = True;
		  Form1->Label8->Visible = True;
		}

	while (mark_column()) {
		Form1->Label7->Caption = "Шаг " + IntToStr(step);
		step++;
		flag = 1;
		Calculation();
        Form1->StringGrid3->Repaint();
		Application->ProcessMessages();
		UpdateStrigGrid();

		if (Form1->N10->Checked) {
		  Sleep(10000);
		}
		for (j = 0; j < Number_of_vertices; j++) {
			Form1->column_status[j] = "-1";
		}
		flag = 0;

	}
	Form1->Label7->Caption = "Шаг " + IntToStr(step);
	step++;
	Form1->Label5->Visible = False;
	Form1->Label6->Visible = False;
	Form1->Edit2->Visible = False;
	Form1->Edit3->Visible = False;
	Form1->Label9->Visible = True;
	Form1->Label9->Caption = Form1->Label9->Caption + IntToStr(Number_of_vertices - 1);
	Application->ProcessMessages();
	Sleep(5000);
	Form1->Label9->Visible = False;
	Form1->Label7->Caption = "Шаг " + IntToStr(step);
   	Form1->StringGrid2->Visible = False;
	Form1->Label8->Visible = False;
	Form1->Label10->Visible = True;
	Application->ProcessMessages();
	Sleep(3000);
	prop();
	UpdateStrigGrid();
	Application->ProcessMessages();
	Form1->Label11->Visible = True;
	flag = 2;
	Form1->StringGrid3->Repaint();
	Application->ProcessMessages();
	Sleep(5000);
	p = 0;
	for (i = 0; i < Number_of_vertices; i++) {
		if (Form1->matrix[0][i] != -1) {
			p = p + Form1->matrix[0][i];
		}
	}
	flag = 0;
	Edit1->Text = IntToStr(p);
	Label1->Visible = True;
	Edit1->Visible = True;
	Form1->StringGrid2->Visible = False;
	Form1->Label5->Visible = False;
	Form1->Edit2->Visible = False;
	Form1->Label6->Visible = False;
	Form1->Edit3->Visible = False;
	Form1->Label8->Visible = False;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N3Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N4Click(TObject *Sender)
{
  Form3->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N10Click(TObject *Sender)
{
  Form1->N10->Checked = !Form1->N10->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
  Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid3DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
    int i;
	TStringGrid *grid = static_cast<TStringGrid*>(Sender);
	if (flag == 2) {
	  if((ARow == 1) && !(ACol == 0)) {
		grid->Canvas->Brush->Color = clBlue;
		grid->Canvas->FillRect(Rect);
		grid->Canvas->Font->Color = clWhite;
	  }
	  else {
		grid->Canvas->Brush->Color = clWhite;
		grid->Canvas->FillRect(Rect);
		grid->Canvas->Font->Color = clBlack;
	  }
	  grid->Canvas->TextOut(Rect.Left + 2,Rect.Top + 2, grid->Cells[ACol][ARow]);
	}
	else {
	if (flag == 1) {
	  if(mtx_bool[ACol-1][ARow-1] == 1) {
		  grid->Canvas->Brush->Color = clLime;
		  grid->Canvas->FillRect(Rect);
		  grid->Canvas->Font->Color = clWhite;
		}
		else {
		  grid->Canvas->Brush->Color = clWhite;
		  grid->Canvas->FillRect(Rect);
		  grid->Canvas->Font->Color = clBlack;
		}
		grid->Canvas->TextOut(Rect.Left + 2,Rect.Top + 2, grid->Cells[ACol][ARow]);
	  }
    }
}
//---------------------------------------------------------------------------



