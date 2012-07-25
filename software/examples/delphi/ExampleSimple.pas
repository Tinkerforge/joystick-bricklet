program ExampleSimple;

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
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9Bw';

var
  e: TExample;

procedure TExample.Execute;
var posX, posY: smallint;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  js := TBrickletJoystick.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(js);
  { Don't use device before it is added to a connection }

  { Get current position (x and y value) }
  js.GetPosition(posX, posY);
  WriteLn(Format('Position: %d, %d', [posX, posY]));

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
