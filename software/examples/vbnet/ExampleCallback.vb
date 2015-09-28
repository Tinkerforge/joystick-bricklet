Imports System
Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change to your UID

    ' Callback subroutine for pressed callback
    Sub PressedCB(ByVal sender As BrickletJoystick)
        Console.WriteLine("Pressed")
    End Sub

    ' Callback subroutine for released callback
    Sub ReleasedCB(ByVal sender As BrickletJoystick)
        Console.WriteLine("Released")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim j As New BrickletJoystick(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register pressed callback to subroutine PressedCB
        AddHandler j.Pressed, AddressOf PressedCB

        ' Register released callback to subroutine ReleasedCB
        AddHandler j.Released, AddressOf ReleasedCB

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
