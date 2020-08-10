(*******************************************************************************
  Include file for checking compiler versions and capabilities.
  Define-only edition
  Compatibility: Delphi 7+, FPC

                            === WARNING ===
  Some features of RAD Studio ignore all define areas that use `$IF` construction
  explicitly or implicitly (still up to XE10). This means no autogenerating of methods,
  Jump to decl/impl etc. Really annoying and stupid bug. Code Insight still works though.

  General hints:
    1) Where possible, use capabilities instead of version checking for greater
       clearness and portability.
    2) Check existense of required types/constants/vars by {$IF DECLARED()}.

                      ### Define-only edition ###
  Contains only compiler defines, thus supports including into any part of a unit,
  even before the unit name line!
  Under RAD Studio contains compiler version defines named like `RAD_%VER%_UP`
  where `%VER%` is RAD Studio version (2005-2010, XE, XE2-8...). These defines
  are identical to frequently used `COMPILER_##_UP` ones.
  For FPC/Lazarus, always their latest release version is considered (no older versions)

  Usage:
    1) Check for compiler version (avoid where possible)
      {$IFDEF RAD_2005_UP}
      ...
      {$IFEND}

    2) Check for compiler capability
      {$IFDEF CAPS_REGION}
        {$REGION 'Foo'}
      {$ENDIF}

  ===== Added defines =====

  1. Compiler versions

    - `DCC` for Delphi's up to XE2 (this built-in define was introduced in XE2)
    - `RAD_XX_UP` for Delphi's - compiler version from XX and later

  2. Compiler capabilities

    Two sets of defines:
      - Internal ones, always named as `CAPS_XXX`
      - JVCL-compatible ones, named as `SUPPORTS_XXX`

  3. Compiler bugs

    Features that work as they should only starting from some version.
    Defines are named as `CAPS_XXX` as it's compiler capability too

  4. RTL (Units, class fields etc)

    - New unit defines, named as `HAS_UNIT_XXX`. Most of them are JVCL-compatible.
      `XXX` contains fully scoped unit name, like System.Net.HttpClient =>
      `SYSTEM_NET_HTTPCLIENT`
    - New field defines, named as `HAS_XXX_YYY` where `XXX` is class/record name
      and `YYY` is field name
    - JVCL-compatible new field defines, named in free form
    - Other defines named in a free form

  References:
    http://edn.embarcadero.com/article/34324
    https://www.embarcadero.com/docs/rad-studio-feature-matrix.pdf
    http://www.tindex.net/Language/ (unavailable - see it in WebArchive)
    FPC: https://www.freepascal.org/docs-html/prog/prog.html

*******************************************************************************)

// *** Compiler versions (Delphi/RAD only) *** \\
// Reference:
// https://docwiki.embarcadero.com/RADStudio/Sydney/en/Compiler_Versions

// Define DCC if not defined yet (Delphi up to XE2)
{$IFNDEF DCC}
  {$IF DECLARED(CompilerVersion)}
    {$DEFINE DCC}
  {$IFEND}
{$ENDIF}

{$IFDEF DCC} // Delphi/RAD

{ Compiler version constants matching:
  RAD_Sydney  = RAD_10_4 = 34;
  RAD_Rio     = RAD_10_3 = 33;
  RAD_Tokyo   = RAD_10_2 = 32;
  RAD_Berlin  = RAD_10_2 = 31;
  RAD_Seattle = RAD_10 = 30;
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
  Delphi_7 = 15; }

  {$IF CompilerVersion >= 17}
    {$DEFINE RAD_2005_UP}
  {$IFEND}
  {$IF CompilerVersion >= 18}
    {$DEFINE RAD_2006_UP}
  {$IFEND}
  {$IF CompilerVersion >= 19}
    {$DEFINE RAD_2007_UP}
  {$IFEND}
  {$IF CompilerVersion >= 20}
    {$DEFINE RAD_2009_UP}
  {$IFEND}
  {$IF CompilerVersion >= 21}
    {$DEFINE RAD_2010_UP}
  {$IFEND}
  {$IF CompilerVersion >= 22}
    {$DEFINE RAD_XE_UP}
  {$IFEND}
  {$IF CompilerVersion >= 23}
    {$DEFINE RAD_XE2_UP}
  {$IFEND}
  {$IF CompilerVersion >= 24}
    {$DEFINE RAD_XE3_UP}
  {$IFEND}
  {$IF CompilerVersion >= 25}
    {$DEFINE RAD_XE4_UP}
  {$IFEND}
  {$IF CompilerVersion >= 26}
    {$DEFINE RAD_XE5_UP}
  {$IFEND}
  {$IF CompilerVersion >= 27}
    {$DEFINE RAD_XE6_UP}
  {$IFEND}
  {$IF CompilerVersion >= 28}
    {$DEFINE RAD_XE7_UP}
  {$IFEND}
  {$IF CompilerVersion >= 29}
    {$DEFINE RAD_XE8_UP}
  {$IFEND}
  {$IF CompilerVersion >= 30}
    {$DEFINE RAD_10_UP}
    {$DEFINE RAD_SEATTLE_UP}
  {$IFEND}
  {$IF CompilerVersion >= 31}
    {$DEFINE RAD_10_1_UP}
    {$DEFINE RAD_BERLIN_UP}
  {$IFEND}
  {$IF CompilerVersion >= 32}
    {$DEFINE RAD_10_2_UP}
    {$DEFINE RAD_TOKYO_UP}
  {$IFEND}
  {$IF CompilerVersion >= 33}
    {$DEFINE RAD_10_3_UP}
    {$DEFINE RAD_RIO_UP}
  {$IFEND}
  {$IF CompilerVersion >= 34}
    {$DEFINE RAD_10_4_UP}
    {$DEFINE RAD_SYDNEY_UP}
  {$IFEND}
{$ENDIF}

// *** Compiler capabilities *** \\

// ~~ RAD_2005 ~~

{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)}
  // Supports REGION?
  {$DEFINE CAPS_REGION}
  {$DEFINE SUPPORTS_REGION} // JVCL compatible
  // Supports class properties?
  {$DEFINE CAPS_CLASSPROPS}
  // Supports Inline?
  {$DEFINE CAPS_INLINE}
  {$DEFINE SUPPORTS_INLINE} // JVCL compatible
  // Supports class nested const/types?
  {$DEFINE CAPS_CLASSNESTED}
  {$DEFINE SUPPORTS_NESTED_CONSTANTS} // JVCL compatible
  {$DEFINE SUPPORTS_NESTED_TYPES}     // JVCL compatible
  // Supports strict?
  {$DEFINE CAPS_STRICT}
  {$DEFINE SUPPORTS_STRICT} // JVCL compatible
  // Supports for-in?
  {$DEFINE CAPS_FORIN}
  {$DEFINE SUPPORTS_FOR_IN} // JVCL compatible
{$IFEND}

// ~~ RAD_2006 ~~

{$IF DEFINED(RAD_2006_UP) OR DEFINED(FPC)}
  // Supports final class methods?
  {$DEFINE CAPS_METHFINAL}
  {$DEFINE SUPPORTS_FINAL}  // JVCL compatible
  // NB: FPC supports this only if $STATIC ON defined
  // Supports static class methods?
  {$DEFINE CAPS_METHSTATIC}
  {$DEFINE SUPPORTS_STATIC} // JVCL compatible
  // Supports abstract and sealed class marks?
  {$DEFINE CAPS_CLASSMARKS}
  // Supports class fields?
  {$DEFINE CAPS_CLASSFIELDS}
  {$DEFINE SUPPORTS_CLASS_FIELDS} // JVCL compatible
  // Supports operator overloading?
  // NB: FPC uses different syntax
  {$DEFINE CAPS_OPOVERLOAD}
  // Supports class helpers?
  {$DEFINE CAPS_CLASSHELPERS}
  {$DEFINE SUPPORTS_CLASS_HELPERS}
  // NB: FPC supports only if {$mode objfpc/delphi} and {$modeswitch advancedrecords} defined
  // Supports enhanced class-like record abilities (methods, props, access level)?
  {$DEFINE CAPS_ENHANCEDRECS}
  {$DEFINE SUPPORTS_ENHANCED_RECORDS} // JVCL compatible
{$IFEND}

// ~~ RAD_2009 ~~

{$IF DEFINED(RAD_2009_UP) OR DEFINED(FPC)}
  // NB: FPC uses different syntax unless Mode Delphi is defined
  // Supports Generics?
  {$DEFINE CAPS_GENERICS}
  {$DEFINE SUPPORTS_GENERICS} // JVCL compatible
  // Supports Exit(param)?
  {$DEFINE CAPS_EXITPARAM}
  // Supports additional text for the deprecated directive?
  {$DEFINE CAPS_DEPRDETAILS}
  {$DEFINE SUPPORTS_DEPRECATED_DETAILS} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2009_UP)}
  // Supports reference to proc/func (closures)?
  {$DEFINE CAPS_REFERENCE}
{$IFEND}

// ~~ RAD_2010 ~~

{$IF DEFINED(RAD_2010_UP) OR DEFINED(FPC)}
  // Supports class constructors/destructors?
  {$DEFINE CAPS_CLASSCONSTRDESTR}
  {$DEFINE SUPPORTS_CLASS_CTORDTORS} // JVCL compatible
  // Supports Casting interfaces to objects?
  {$DEFINE CAPS_INTFCAST}
  {$DEFINE SUPPORTS_CAST_INTERFACE_TO_OBJ} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2010_UP)}
  // Supports delayed loading of an external library?
  {$DEFINE CAPS_DELAYED}
  {$DEFINE SUPPORTS_DELAYED_LOADING} // JVCL compatible
  // Supports attributes?
  {$DEFINE CAPS_ATTRIBUTES}
{$IFEND}

// ~~ RAD_XE3 ~~

{$IF DEFINED(RAD_XE3_UP) OR DEFINED(FPC)}
  // Supports Simple type record helpers?
  {$DEFINE CAPS_SIMPLEHELPERS}
  // Supports ARC?
  {$DEFINE CAPS_ARC}
{$IFEND}

// ~~ RAD_XE7 ~~

{$IF DEFINED(RAD_XE7_UP) OR DEFINED(FPC)}
  // Supports initialization for dynamic arrays?
  {$DEFINE CAPS_DYNARRAYINIT}
{$IFEND}

{$IF DEFINED(RAD_XE7_UP)}
  // Supports string-like operations on dynamic arrays?
  {$DEFINE CAPS_DYNARRAYOPS}
{$IFEND}

// ~~ RAD_10_3 ~~

{$IF DEFINED(RAD_10_3_UP)}
	// Supports Inline Variable Declaration?
  {$DEFINE CAPS_INLINEVARS}
{$IFEND}

// ~~ RAD_10_4 ~~

{$IF DEFINED(RAD_10_4_UP)}
	// Supports Custom Managed Records?
  {$DEFINE CAPS_MANAGEDRECS}
{$IFEND}

// Compiler bugs

// ~~ RAD_2010 ~~

{$IF DEFINED(RAD_2010_UP) OR DEFINED(FPC)}
  // Generics working as they should (type PT = ^T)?
  {$DEFINE CAPS_GENERICSOK}
{$IFEND}

// ~~ RAD_XE2 ~~

{$IF DEFINED(RAD_XE2_UP) OR DEFINED(FPC)}
  // NativeInt, NativeUInt are fixed?
  {$DEFINE CAPS_NATIVEOK}
{$IFEND}

// ~~ RAD_10 ~~

{$IF DEFINED(RAD_10_UP) OR DEFINED(FPC)}
  // Class constructor won't be called if class/variable is declared/instantiated in DPR file
  // (compiler bug up to XE8)
  {$DEFINE CAPS_CLASSCONSTROK}
{$IFEND}

// *** Other (RTL, units, etc) *** \\

// ~~ RAD_2005 ~~

{$IF DEFINED(RAD_2005_UP)}
  {$DEFINE HAS_UNIT_HTTPPROD} // JVCL compatible
{$IFEND}

// ~~ RAD_2007 ~~

{$IF DEFINED(RAD_2007_UP)}
  {$DEFINE HAS_UNIT_GIFIMG} // JVCL compatible
{$IFEND}

// ~~ RAD_2009 ~~

{$IF DEFINED(RAD_2009_UP) OR DEFINED(FPC)}
  {$DEFINE HAS_UNIT_CHARACTER} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2009_UP)}
  {$DEFINE HAS_UNIT_ANSISTRINGS}      // JVCL compatible
  {$DEFINE HAS_UNIT_PNGIMAGE}         // JVCL compatible
  // Exception class has the StackTrace propery; JVCL compatible
  {$DEFINE HAS_EXCEPTION_STACKTRACE}
  // TObject has new methods (Equals, GetHashCode, ToString)
  {$DEFINE HAS_TOBJECT_METHODS}
{$IFEND}

// ~~ RAD_XE ~~

{$IF DEFINED(RAD_XE_UP)}
  {$DEFINE HAS_UNIT_REGEX}
  {$DEFINE HAS_UNIT_REGULAREXPRESSIONSAPI} // JVCL compatible
  // TFormatSettings has constructor Create
  {$DEFINE HAS_TFMTSETT_CREATE}
{$IFEND}

// ~~ RAD_XE2 ~~

{$IF DEFINED(RAD_XE2_UP)}
  // Has scoped RTL/VCL units?
  {$DEFINE HAS_UNITSCOPE}              // JVCL compatible
  {$DEFINE HAS_UNIT_SYSTEM_UITYPES}    // JVCL compatible
  {$DEFINE HAS_UNIT_VCL_THEMES}        // JVCL compatible
  // since XE2 TList is is TPointerList not PPointerList
  {$DEFINE TLIST_ISNOT_PPOINTERLIST}
{$IFEND}

// ~~ RAD_XE3 ~~

{$IF DEFINED(RAD_XE3_UP)}
  {$DEFINE HAS_UNIT_SYSTEM_ACTIONS}    // JVCL compatible
  // TControl has a StyleElements property; JVCL compatible
  {$DEFINE HAS_PROPERTY_STYLEELEMENTS}
{$IFEND}

// ~~ RAD_XE4 ~~

{$IF DEFINED(RAD_XE4_UP)}
  // Ansi* routines deprecated and moved to AnsiStrings unit
  {$DEFINE DEPRECATED_SYSUTILS_ANSISTRINGS} // JVCL compatible
{$IFEND}

// ~~ RAD_XE7 ~~

{$IF DEFINED(RAD_XE7_UP)}
  // Parallel Programming library in System.Threading unit
  {$DEFINE HAS_UNIT_SYSTEM_THREADING}
  // All net encodings in unit System.NetEncoding
  {$DEFINE HAS_UNIT_SYSTEM_NETENCODING}
  // TControl has Size and PlatformDefault properties
  {$DEFINE HAS_TCONTROL_SIZE}
  {$DEFINE HAS_TCONTROL_PLATFORMDEFAULT}
{$IFEND}

// ~~ RAD_XE8 ~~

{$IF DEFINED(RAD_XE8_UP)}
  // HTTP client in System.Net.HttpClient unit
  {$DEFINE HAS_UNIT_SYSTEM_NET_HTTPCLIENT}
  // Hashes in System.Hash unit
  {$DEFINE HAS_UNIT_SYSTEM_HASH}
{$IFEND}
