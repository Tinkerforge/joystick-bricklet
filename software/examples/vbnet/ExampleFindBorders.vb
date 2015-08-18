Imports Tinkerforge

Module ExampleFindBorders
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change to your UID

    ' Callback for x or y position outside of [-99..99]
    Sub ReachedCB(ByVal sender As BrickletJoystick, ByVal x As Short, ByVal y As Short)
        If y = 100 Then
            System.Console.WriteLine("Top")
        Else If y = -100 Then
            System.Console.WriteLine("Bottom")
        End If

        If x = 100 Then
            System.Console.WriteLine("Right")
        Else If x = -100 Then
            System.Console.WriteLine("Left")
        End If

        System.Console.WriteLine("")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim j As New BrickletJoystick(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 0.2 seconds (200ms)
        j.SetDebouncePeriod(200)

        ' Register threshold reached callback to function ReachedCB
        AddHandler j.PositionReached, AddressOf ReachedCB

        ' Configure threshold for "x or y value outside of [-99..99]"
        j.SetPositionCallbackThreshold("o"C, -99, 99, -99, 99)

        System.Console.WriteLine("Press key to exit")
        System.Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
