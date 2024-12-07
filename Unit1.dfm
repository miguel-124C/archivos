object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 0
    Top = 24
    Width = 121
    Height = 25
    Caption = 'Convertir mayuscula'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 0
    Top = 86
    Width = 121
    Height = 25
    Caption = 'EliminarCaracteres'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 55
    Width = 121
    Height = 25
    Caption = 'Convertir minuscula'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 117
    Width = 121
    Height = 25
    Caption = 'CodificarVocal'
    TabOrder = 3
    OnClick = Button4Click
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 280
    Top = 32
  end
end
