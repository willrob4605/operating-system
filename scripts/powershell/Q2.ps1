Get-Process |
Sort-Object WorkingSet -Descending| 
Select-Object -First 5 Name, Id, @{Name="MemoryMB"; Expression={[math]::Round($_.WorkingSet / 1MB, 2)}}