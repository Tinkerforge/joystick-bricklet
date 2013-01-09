program ExampleCallback;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletJoystick;

type
  TExample = class
  private
    ipcon: TIPConnection;
    js: TBrickletJoystick;
  public
    procedure PressedCB(sender: TBrickletJoystick);
    procedure ReleasedCB(sender: TBrickletJoystick);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9Bw'; { Change to your UID }

var
  e: TExample;

{ Callback function for pressed and released events }
procedure TExample.PressedCB(sender: TBrickletJoystick);
begin
  WriteLn('Pressed');
end;

procedure TExample.ReleasedCB(sender: TBrickletJoystick);
begin
  WriteLn('Released');
end;

procedure TExample.Execute;
begin
  { Create IP connection }
  ipcon := TIPConnection.Create;

  { Create device object }
  js := TBrickletJoystick.Create(UID, ipcon);

  { Connect to brickd }
  ipcon.Connect(HOST, PORT);
  { Don't use device before ipcon is connected }

  { Register callbacks for pressed and released events }
  js.OnPressed := {$ifdef FPC}@{$endif}PressedCB;
  js.OnReleased := {$ifdef FPC}@{$endif}ReleasedCB;

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
