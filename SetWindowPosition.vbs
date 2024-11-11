Set objShell = CreateObject("WScript.Shell")
If WScript.Arguments.Count >= 2 Then
  xPos = WScript.Arguments(0)
  yPos = WScript.Arguments(1)
  WScript.Sleep 500 ' Wait for the window to appear
  objShell.AppActivate "cmd.exe"
  Set objWindow = CreateObject("Shell.Application").Windows.Item(0)
  objWindow.Left = xPos
  objWindow.Top = yPos
End If
