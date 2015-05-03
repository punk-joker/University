object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1052#1077#1090#1086#1076' '#1052#1086#1085#1090#1077'-'#1050#1072#1088#1083#1086
  ClientHeight = 382
  ClientWidth = 556
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 124
    Height = 13
    Caption = #1055#1088#1077#1076#1077#1083#1099' '#1080#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103':'
  end
  object Label2: TLabel
    Left = 8
    Top = 54
    Width = 90
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1080#1090#1077#1088#1072#1094#1080#1081':'
  end
  object Label3: TLabel
    Left = 264
    Top = 8
    Width = 31
    Height = 13
    Caption = 'X '#1086#1087#1090'.'
  end
  object Label4: TLabel
    Left = 262
    Top = 54
    Width = 33
    Height = 13
    Caption = 'Y max.'
  end
  object Label5: TLabel
    Left = 152
    Top = 8
    Width = 51
    Height = 13
    Hint = #1095#1080#1089#1083#1086' '#1079#1085#1072#1082#1086#1074' '#1087#1086#1089#1083#1077' '#1079#1072#1087#1103#1090#1086#1081
    Caption = #1058#1086#1095#1085#1086#1089#1090#1100':'
    ParentShowHint = False
    ShowHint = True
  end
  object Edit1: TEdit
    Left = 8
    Top = 27
    Width = 49
    Height = 21
    TabOrder = 0
    Text = '-5'
  end
  object Edit2: TEdit
    Left = 71
    Top = 27
    Width = 50
    Height = 21
    TabOrder = 1
    Text = '5'
  end
  object Edit3: TEdit
    Left = 8
    Top = 73
    Width = 113
    Height = 21
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
    Text = '10'
  end
  object Edit4: TEdit
    Left = 264
    Top = 27
    Width = 65
    Height = 21
    ReadOnly = True
    TabOrder = 3
  end
  object Edit5: TEdit
    Left = 262
    Top = 73
    Width = 67
    Height = 21
    ReadOnly = True
    TabOrder = 4
  end
  object BitBtn1: TBitBtn
    Left = 384
    Top = 27
    Width = 121
    Height = 40
    Caption = #1053#1072#1081#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = BitBtn1Click
  end
  object Chart1: TChart
    Left = 8
    Top = 108
    Width = 537
    Height = 261
    Legend.Visible = False
    MarginBottom = 7
    MarginLeft = 7
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1095#1077#1089#1082#1086#1077' '#1086#1090#1086#1073#1088#1072#1078#1077#1085#1080#1077)
    View3D = False
    View3DOptions.Orthogonal = False
    OnAfterDraw = AfterDraw
    TabOrder = 6
    ColorPaletteIndex = 13
    object Series1: TLineSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.ShapeStyle = fosRoundRectangle
      Marks.Visible = False
      Brush.BackColor = clDefault
      Pointer.Brush.Gradient.EndColor = 10708548
      Pointer.Gradient.EndColor = 10708548
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TLineSeries
      Emboss.Color = clRed
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Emboss.Color = 8487297
      Marks.ShapeStyle = fosRoundRectangle
      Marks.Visible = False
      SeriesColor = clBlack
      Brush.BackColor = clDefault
      Pointer.Brush.Gradient.EndColor = clBlack
      Pointer.Gradient.EndColor = clBlack
      Pointer.HorizSize = 5
      Pointer.InflateMargins = True
      Pointer.Style = psCircle
      Pointer.VertSize = 5
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Edit6: TEdit
    Left = 152
    Top = 27
    Width = 65
    Height = 21
    TabOrder = 7
    Text = '3'
  end
end
