Write-Host "System Health Snapshot"
Write-Host "Current Date and Time:" (Get-Date)
Write-Host "Hostname of the computer" $env:COMPUTERNAME
Write-Host "Current User logged in" $env:USERNAME
Write-Host "Disk usage: "
Get-PSDrive