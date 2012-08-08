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
    procedure ReachedCB(const x: smallint; const y: smallint);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9Bw'; { Change to your UID }

var
  e: TExample;

{ Callback for x and y position outside of -99, 99 }
procedure TExample.ReachedCB(const x: smallint; const y: smallint);
begin
  if ((x = 100) and (y = 100)) then begin
    WriteLn('Top Right');
  end
  else if ((x = -100) and (y = 100)) then begin
    WriteLn('Top Left');
  end
  else if ((x = -100) and (y = -100)) then begin
    WriteLn('Bottom Left');
  end
  else if ((x = 100) and (y = -100)) then begin
    WriteLn('Bottom Right');
  end
  else begin
    { This can't happen, the threshold is configured to:
      "outside of -99, 99" }
    WriteLn('Error');
  end;
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

  { Get threshold callbacks with a debounce time of 0.2 seconds (200ms) }
  js.SetDebouncePeriod(200);

  { Register threshold reached callback to procedure ReachedCB }
  js.OnPositionReached := {$ifdef FPC}@{$endif}ReachedCB;

  { Configure threshold for "x and y value outside of -99 and 99" }
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
