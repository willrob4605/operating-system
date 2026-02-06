$count = Select-String -Path "server.log.txt" -Pattern "Error"
Write-Host "Number of lines containing 'Error':" $count.Count
