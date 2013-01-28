program ExampleFindCorners;

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
    procedure ReachedCB(sender: TBrickletJoystick; const x: smallint; const y: smallint);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9Bw'; { Change to your UID }

var
  e: TExample;

{ Callback for x and y position outside of [-99..99] }
procedure TExample.ReachedCB(sender: TBrickletJoystick; const x: smallint; const y: smallint);
begin
  if (y = 100) then begin
    WriteLn('Top');
  end
  else if (y = -100) then begin
    WriteLn('Bottom');
  end;
  if (x = 100) then begin
    WriteLn('Right');
  end
  else if (x = -100) then begin
    WriteLn('Left');
  end;
  WriteLn('');
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

  { Get threshold callbacks with a debounce time of 0.2 seconds (200ms) }
  js.SetDebouncePeriod(200);

  { Register threshold reached callback to procedure ReachedCB }
  js.OnPositionReached := {$ifdef FPC}@{$endif}ReachedCB;

  { Configure threshold for "x or y value outside of [-99..99]" }
  js.SetPositionCallbackThreshold('o', -99, 99, -99, 99);

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
