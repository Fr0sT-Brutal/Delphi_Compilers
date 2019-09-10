(*******************************************************************************
  Include file for cross-platform and cross-compiler compatibility.
  Roughly talking, adds FPC defines when compiling under DCC.
  Current defines:
    * CPU32/CPU64/CPU_UNK
    * ENDIAN_LITTLE

*******************************************************************************)

{$IFDEF DCC} // When compiling with Delphi/RAD

  // FPC-style CPU architecture (CPU32/CPU64)
  {$IF SizeOf(Pointer) = 4} {$DEFINE CPU32} {$IFEND}
  {$IF SizeOf(Pointer) = 8} {$DEFINE CPU64} {$IFEND}

  // FPC-style system endianness (only ENDIAN_LITTLE for Delphi currently)
  {$IF DEFINED(CPU386) OR DEFINED(CPUX86) OR DEFINED(CPUX64) OR DEFINED(CPUARM)}
    {$DEFINE ENDIAN_LITTLE}
  {$IFEND}

{$ENDIF DCC}

// CPU## is not defined or not a 32 or 64 bit CPU
{$IF NOT DEFINED(CPU32) AND NOT DEFINED(CPU64)}
  {$DEFINE CPU_UNK}
{$IFEND}
