$workspaceFolder = Get-Location
if (-not (Test-Path -Path "bin")) { mkdir bin }
pushd bin
ml64.exe /I $workspaceFolder\win32_api /Fl /Sf /c /Cp /Cx /Fm /FR /W2 /Zd /Zf /Zi /Ta $workspaceFolder\src\game.asm $workspaceFolder\src\main.asm
link.exe game.obj main.obj /debug:full /opt:ref /opt:noicf /largeaddressaware:no /entry:Startup /machine:x64 /map /out:SandSim.exe /PDB:Main.pdb /subsystem:windows,6.0 kernel32.lib user32.lib Gdi32.lib  

popd

# $workspaceFolder\extern\stb_truetype.obj
# legacy_stdio_definitions.lib libvcruntime.lib libcmt.lib  libcmtd.lib  libconcrt.lib  libconcrt1.lib  libconcrtd.lib  libconcrtd0.lib  libconcrtd1.lib  libcpmt.lib  libcpmt1.lib libcpmtd0.lib libcpmtd1.lib libomp.lib libompd.lib libsancov.lib libsancovd.lib libvcasan.lib libvcasand.lib  libvcruntime.lib libvcruntimed.lib msvcrt.lib
