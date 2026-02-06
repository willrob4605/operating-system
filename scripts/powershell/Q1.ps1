param (
    [string]$File
)
$limit = 1048576

if (-Not (Test-Path $File)) {
    Write-Host "File does not exist."
    exit
}
$size = (Get-Item $File).Length
if ($size -gt $limit) {
    Write-Host "Warning: File is too large"
} else {
    Write-Host "File size is within limits."
}