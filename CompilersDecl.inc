(*******************************************************************************
  Include file for checking compiler versions and capabilities. Declaration edition

                            === WARNING ===
  Some features of RAD Studio ignore all define areas that use `$IF` construction
  explicitly or implicitly (up to Berlin). This means no autogenerating of methods,
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
  RAD_Rio     = 32; RAD_10_3 = 33;
  RAD_Tokyo   = 32; RAD_10_2 = 32;
  RAD_Berlin  = 31; RAD_10_1 = 31;
  RAD_Seattle = 30; RAD_10 = 30;
  RAD_XE8  = 29;
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

  Cap_Region = {$IFDEF CAPS_REGION} True {$ELSE} False {$ENDIF};

  Cap_ClassProps = {$IFDEF CAPS_CLASSPROPS} True {$ELSE} False {$ENDIF};

  Cap_Inline = {$IFDEF CAPS_INLINE} True {$ELSE} False {$ENDIF};

  Cap_ClassNested = {$IFDEF CAPS_CLASSNESTED} True {$ELSE} False {$ENDIF};

  Cap_Strict = {$IFDEF CAPS_STRICT} True {$ELSE} False {$ENDIF};

  Cap_ForIn = {$IFDEF CAPS_FORIN} True {$ELSE} False {$ENDIF};

  Cap_StaticMembers = {$IFDEF CAPS_STATICMEMBERS} True {$ELSE} False {$ENDIF};

  Cap_ClassMarks = {$IFDEF CAPS_CLASSMARKS} True {$ELSE} False {$ENDIF};

  Cap_MethMarks = {$IFDEF CAPS_METHMARKS} True {$ELSE} False {$ENDIF};

  Cap_ClassFields = {$IFDEF CAPS_CLASSFIELDS} True {$ELSE} False {$ENDIF};

  Cap_OpOverload = {$IFDEF CAPS_OPOVERLOAD} True {$ELSE} False {$ENDIF};

  Cap_ClassHelpers = {$IFDEF CAPS_CLASSHELPERS} True {$ELSE} False {$ENDIF};

  Cap_EnhancedRecs = {$IFDEF CAPS_ENHANCEDRECS} True {$ELSE} False {$ENDIF};

  Cap_Generics = {$IFDEF CAPS_GENERICS} True {$ELSE} False {$ENDIF};

  Cap_ExitParam = {$IFDEF CAPS_EXITPARAM} True {$ELSE} False {$ENDIF};

  Cap_Reference = {$IFDEF CAPS_REFERENCE} True {$ELSE} False {$ENDIF};

  Cap_TObjectMethods = {$IFDEF CAPS_TOBJECTMETHODS} True {$ELSE} False {$ENDIF};

  Cap_DeprDetails = {$IFDEF CAPS_DEPRDETAILS} True {$ELSE} False {$ENDIF};

  Cap_GenericsOK = {$IFDEF CAPS_GENERICSOK} True {$ELSE} False {$ENDIF};

  Cap_IntfCast = {$IFDEF CAPS_INTFCAST} True {$ELSE} False {$ENDIF};

  Cap_Delayed = {$IFDEF CAPS_DELAYED} True {$ELSE} False {$ENDIF};

  Cap_Attributes = {$IFDEF CAPS_ATTRIBUTES} True {$ELSE} False {$ENDIF};

  Cap_ClassConstDestr = {$IFDEF CAPS_CLASSCONSTRDESTR} True {$ELSE} False {$ENDIF};

  Cap_NativeOK = {$IFDEF CAPS_NATIVEOK} True {$ELSE} False {$ENDIF};

  Cap_ARC = {$IFDEF CAPS_ARC} True {$ELSE} False {$ENDIF};

  Cap_SimpleHelpers = {$IFDEF CAPS_SIMPLEHELPERS} True {$ELSE} False {$ENDIF};

  Cap_DynArrayInit = {$IFDEF CAPS_DYNARRAYINIT} True {$ELSE} False {$ENDIF};

  Cap_DynArrayOps = {$IFDEF CAPS_DYNARRAYOPS} True {$ELSE} False {$ENDIF};