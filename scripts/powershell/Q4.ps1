cd "C:\Users\Will Roberts\Desktop\PowerShell Scripts\TestFiles"

#Do a loop
Get-ChildItem -Filter *.txt -File | ForEach-Object {
    Rename-Item $_.FullName ("OLD_" + $_.Name)
}

Write-Host "The files have been renamed"
