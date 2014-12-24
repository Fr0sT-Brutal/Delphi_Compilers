(*******************************************************************************
  Include file for checking compiler versions and capabilities. Declaration edition

                            === WARNING ===
  Some features of RAD Studio ignore all define areas that use `$IF` construction
  explicitly or implicitly (at least on XE2). This means no autogenerating of methods,
  Jump to decl/impl etc. Really annoying and stupid bug. Code Insight still works though.

  General hints:
    1) Where possible, use capabilities instead of versions checking for greater
       clearness and portability.
    2) Check existense of required types/constants/vars by {$IF DECLARED()}.

                      ### Declaration edition ###
  Contains constant declarations, thus allowing more convenient usage (see example).
  Could be included ONLY in declaration section and below so its contents couldn't be
  utilized in "uses" section. If you need it, check CompilersDef.inc file.
  
  Usage:
    1) Check for compiler version (avoid where possible)
      {$IF CompilerVersion >= RAD_2005}
      ...
      {$IFEND}

    2) Check for compiler capability
      {$IF Cap_Region}
      ...
      {$IFEND}
      Here you can get Code Insight to find the needed capability as it is usual
      boolean constant.
      (!) Note that constants are named "Cap_*" while defines are named "CAPS_"
      to avoid ambiguity with FPC as it allows {$IF %Define_name%} construction.

*******************************************************************************)

{$I 'CompilersDef.inc'}

// Compiler version constants for checking with $IF directive (Delphi6+)
// Must be declared for other compilers
const
  RAD_XE7  = 28;
  RAD_XE6  = 27;
  RAD_XE5  = 26;
  RAD_XE4  = 25;
  RAD_XE3  = 24;
  RAD_XE2  = 23;
  RAD_XE   = 22;
  RAD_2010 = 21;
  RAD_2009 = 20;
  RAD_2007 = 19;
  RAD_2006 = 18;
  RAD_2005 = 17;
  Delphi_8 = 16;
  Delphi_7 = 15;
{$IF NOT DECLARED(CompilerVersion)} // just a stub to compile under non-Delphi/RAD
  CompilerVersion = 0;
{$IFEND}

// Declare capability constants to enable {$IF Cap_**} construction

{$IFDEF CAPS_REGION}
  Cap_Region = True;
{$ENDIF}

{$IFDEF CAPS_CLASSPROPS}
  Cap_ClassProps = True;
{$ENDIF}

{$IFDEF CAPS_INLINE}
  Cap_Inline = True;
{$ENDIF}

{$IFDEF CAPS_CLASSNESTED}
  Cap_ClassNested = True;
{$ENDIF}

{$IFDEF CAPS_STRICT}
  Cap_Strict = True;
{$ENDIF}

{$IFDEF CAPS_FORIN}
  Cap_ForIn = True;
{$ENDIF}

{$IFDEF CAPS_STATICMEMBERS}
  Cap_StaticMembers = True;
{$ENDIF}

{$IFDEF CAPS_CLASSMARKS}
  Cap_ClassMarks = True;
{$ENDIF}

{$IFDEF CAPS_METHMARKS}
  Cap_MethMarks = True;
{$ENDIF}

{$IFDEF CAPS_CLASSFIELDS}
  Cap_ClassFields = True;
{$ENDIF}

{$IFDEF CAPS_OPOVERLOAD}
  Cap_OpOverload = True;
{$ENDIF}

{$IFDEF CAPS_CLASSHELPERS}
  Cap_ClassHelpers = True;
{$ENDIF}

{$IFDEF CAPS_ENHANCEDRECS}
  Cap_EnhancedRecs = True;
{$ENDIF}

{$IFDEF CAPS_GENERICS}
  Cap_Generics = True;
{$ENDIF}

{$IFDEF CAPS_EXITPARAM}
  Cap_ExitParam = True;
{$ENDIF}

{$IFDEF CAPS_REFERENCE}
  Cap_Reference = True;
{$ENDIF}

{$IFDEF CAPS_TOBJECTMETHODS}
  Cap_TObjectMethods = True;
{$ENDIF}

{$IFDEF CAPS_GENERICSOK}
  Cap_GenericsOK = True;
{$ENDIF}

{$IFDEF CAPS_INTFCAST}
  Cap_IntfCast = True;
{$ENDIF}

{$IFDEF CAPS_DELAYED}
  Cap_Delayed = True;
{$ENDIF}

{$IFDEF CAPS_ATTRIBUTES}
  Cap_Attributes = True;
{$ENDIF}

{$IFDEF CAPS_CLASSCONSTRDESTR}
  Cap_ClassConstDestr = True;
{$ENDIF}

{$IFDEF CAPS_NATIVEOK}
  Cap_NativeOK = True;
{$ENDIF}

{$IFDEF CAPS_SIMPLEHELPERS}
  Cap_SimpleHelpers = True;
{$ENDIF}

{$IFDEF CAPS_DYNARRAYINIT}
  Cap_DynArrayInit = True;
{$ENDIF}

{$IFDEF CAPS_DYNARRAYOPS}
  Cap_DynArrayOps = True;
{$ENDIF}