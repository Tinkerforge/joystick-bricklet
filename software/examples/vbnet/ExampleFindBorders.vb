Imports System
Imports Tinkerforge

Module ExampleFindBorders
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Joystick Bricklet

    ' Callback subroutine for position reached callback
    Sub PositionReachedCB(ByVal sender As BrickletJoystick, ByVal x As Short, _
                          ByVal y As Short)
        If y = 100 Then
            Console.WriteLine("Top")
        Else If y = -100 Then
            Console.WriteLine("Bottom")
        End If

        If x = 100 Then
            Console.WriteLine("Right")
        Else If x = -100 Then
            Console.WriteLine("Left")
        End If

        Console.WriteLine("")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim j As New BrickletJoystick(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
        j.SetDebouncePeriod(200)

        ' Register position reached callback to subroutine PositionReachedCB
        AddHandler j.PositionReached, AddressOf PositionReachedCB

        ' Configure threshold for position "outside of -99, -99 to 99, 99"
        j.SetPositionCallbackThreshold("o"C, -99, 99, -99, 99)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
