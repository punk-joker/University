unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Timer1: TTimer;
    Button1: TButton;
    procedure FormCreate(Sender: TObject);
    procedure DrawImg;
    procedure Timer1Timer(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  diametr_cylinder, length_cylinder, x_cylinder, y_cylinder: integer;
  x_block, x_block_t, y_block, diametr_block, length_block: integer;
  x3, y3, dist, rad: integer;
  length_stock, x_stock, y_stock, x_stock_t, y_stock_t: integer;
  animation: integer;
  angle_rad, angle:real;
implementation

{$R *.dfm}

procedure TForm1.DrawImg;
var
 dx: integer;
begin
  angle_rad:=angle*(Pi/180); //переводим угол поворота в радианы
  x_stock_t := Round( cos(angle_rad)*(x_stock - x3) + sin(angle_rad)*(y_stock - y3) ) + x3; //вычиляем координаты на круге
  y_stock_t := Round( cos(angle_rad)*(y_stock - y3) - sin(angle_rad)*(x_stock - x3) ) + y3; //при повороте на угол a

  dx:=Round(Sqrt((660*660) - ((y_stock_t - y3)*(y_stock_t - y3)))); //вычисляем отклонение блока
  x_block_t:=x_block+(660-dx-(x3-x_stock_t)+60); //новые координаты блока

  Image1.Canvas.FillRect(Canvas.ClipRect); //очиста canvas

  //рисуем цилиндр
  Image1.Canvas.Pen.Width := 2;
  Image1.Canvas.MoveTo(x_cylinder,y_cylinder);
  Image1.Canvas.LineTo(length_cylinder, y_cylinder);
  Image1.Canvas.MoveTo(x_cylinder,y_cylinder);
  Image1.Canvas.LineTo(x_cylinder, y_cylinder+diametr_cylinder);
  Image1.Canvas.MoveTo(x_cylinder,y_cylinder+diametr_cylinder);
  Image1.Canvas.LineTo(length_cylinder, y_cylinder+diametr_cylinder);

  //рисуем блок
  Image1.Canvas.MoveTo(x_block_t, y_block);
  Image1.Canvas.LineTo(x_block_t + length_block, y_block);
  Image1.Canvas.LineTo(x_block_t + length_block, y_block + diametr_block);
  Image1.Canvas.LineTo(x_block_t, y_block + diametr_block);
  Image1.Canvas.LineTo(x_block_t, y_block);

  //рисуем шток
  Image1.Canvas.Arc(x3-rad, y3-rad, x3+rad, y3+rad, 0, 0, 0, 0);
  Image1.Canvas.MoveTo(x_stock_t, y_stock_t);
  Image1.Canvas.LineTo(x_block_t + length_block, y3);
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  x_cylinder := 50;
  y_cylinder := 100;
  length_cylinder := 600;
  diametr_cylinder := 200;

  diametr_block := diametr_cylinder - 40;
  length_block := diametr_block;

  x_block := x_cylinder + 40;
  y_block := y_cylinder + 20;

  rad := 100;
  dist := 60;
  x3 := x_cylinder + length_cylinder + rad + dist;
  y3 := y_cylinder + (diametr_cylinder div 2);

  x_stock := x3 - 60;
  y_stock := y3;
  length_stock := x_stock - (x_block + length_block);
  angle := 0;
  DrawImg();
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  angle:=angle+1;
  if angle = 360 then angle:=0;
  DrawImg();
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  if animation=1 then
  begin
    Button1.Caption:='Старт';
    Timer1.Enabled := False;
    animation:=0;
  end
  else
  begin
    Button1.Caption:='Стоп';
    Timer1.Enabled := True;
    animation:=1;
  end
end;

end.
