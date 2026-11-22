param([string]$Source, [string]$Output)
$ErrorActionPreference = 'Stop'

# Find g++ (MSYS2 UCRT64 first, then anything on PATH)
$gpp = 'C:\msys64\ucrt64\bin\g++.exe'
if (-not (Test-Path -LiteralPath $gpp)) {
    $cmd = Get-Command g++ -ErrorAction SilentlyContinue
    if ($cmd) { $gpp = $cmd.Source }
    else {
        Write-Host 'g++ not found. Install it in the "MSYS2 UCRT64" window:'
        Write-Host '  pacman -S --needed mingw-w64-ucrt-x86_64-toolchain'
        exit 1
    }
}
$env:PATH = (Split-Path -Parent $gpp) + ';' + $env:PATH
Write-Host "Using: $gpp"

# Compile (static, so the .exe runs without MSYS2 in PATH)
& $gpp -std=c++17 -g -Wall -static "$Source" -o "$Output"
exit $LASTEXITCODE
