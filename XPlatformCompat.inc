(*******************************************************************************
  Include file for cross-platform and cross-compiler compatibility.
  Roughly talking, adds FPC defines when compiling under DCC.
  Current defines:
    * CPU32/CPU64/CPU_UNK - bitness of target CPU. Not an architecture!
    * ENDIAN_LITTLE - target endianness
    * POSIX, UNIX - if target OS is Unix/Posix-like

  Refs:
    https://wiki.freepascal.org/Platform_defines
    https://www.freepascal.org/docs-html/prog/progap7.html

    http://docwiki.embarcadero.com/RADStudio/Sydney/en/Conditional_compilation_(Delphi)#Predefined_Conditionals

*******************************************************************************)

{$IFDEF DCC} // When compiling with Delphi/RAD (built-in since XE2, use CompilersDef.inc for older versions)

  // FPC-style CPU architecture (only CPU32/CPU64 for Delphi currently)
  {$IF SizeOf(Pointer) = 4} {$DEFINE CPU32} {$IFEND}
  {$IF SizeOf(Pointer) = 8} {$DEFINE CPU64} {$IFEND}

  // FPC-style system endianness (only ENDIAN_LITTLE for Delphi currently)
  {$IF DEFINED(CPU386) OR DEFINED(CPUX86) OR DEFINED(CPUX64) OR DEFINED(CPUARM)}
    {$DEFINE ENDIAN_LITTLE}
  {$IFEND}

  // FPC-style target OS: UNIX (DCC has POSIX)
  {$IFDEF POSIX}
    {$DEFINE UNIX}
  {$ENDIF}

{$ENDIF DCC}

{$IFDEF FPC} // When compiling with FPC
  // Delphi-style target OS: POSIX (FPC has UNIX)
  {$IFDEF UNIX}
    {$DEFINE POSIX}
  {$ENDIF}

{$ENDIF FPC}

// CPU## is not defined or not a 32 or 64 bit CPU
{$IF NOT DEFINED(CPU32) AND NOT DEFINED(CPU64)}
  {$DEFINE CPU_UNK}
{$IFEND}
