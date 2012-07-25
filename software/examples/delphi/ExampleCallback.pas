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
    procedure PressedCB;
    procedure ReleasedCB;
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9Bw';

var
  e: TExample;

{ Callback function for pressed and released events }
procedure TExample.PressedCB;
begin
  WriteLn('Pressed');
end;

procedure TExample.ReleasedCB;
begin
  WriteLn('Released');
end;

procedure TExample.Execute;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  js := TBrickletJoystick.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(js);
  { Don't use device before it is added to a connection }

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
