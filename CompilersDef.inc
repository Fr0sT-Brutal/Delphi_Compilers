(*******************************************************************************
  Include file for checking compiler versions and capabilities. Define-only edition

                            === WARNING ===
  Some features of RAD Studio ignore all define areas that use `$IF` construction
  explicitly or implicitly (at least on XE2). This means no autogenerating of methods,
  Jump to decl/impl etc. Really annoying and stupid bug. Code Insight still works though.

  General hints:
    1) Where possible, use capabilities instead of versions checking for greater
       clearness and portability.
    2) Check existense of required types/constants/vars by {$IF DECLARED()}.

                      ### Define-only edition ###
  Contains only compiler defines, thus supports including into any part of a unit,
  even before the unit name line!
  Under RAD Studio contains compiler version defines named like RAD_%VER%_UP
  where %VER% is RAD Studio version (2005-2010, XE, XE2-7...). These defines
  are identical to frequently used COMPILER_##_UP ones.

  Usage:
    1) Check for compiler version (avoid where possible)
      {$IFDEF RAD_2005_UP}
      ...
      {$IFEND}

    2) Check for compiler capability
      {$IFDEF CAPS_REGION}
        {$REGION 'Foo'}
      {$ENDIF}

*******************************************************************************)

// *** Compiler versions (Delphi/RAD only) *** \\

{$IF DECLARED(CompilerVersion)} // Delphi/RAD

{ Compiler version constants matching:
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
{$IFEND}

// *** Compiler capabilities *** \\

// References:
// http://edn.embarcadero.com/article/34324
// http://www.embarcadero.com/ru/products/delphi/delphi-feature-matrix
// http://www.tindex.net/Language/ (!)
// FPC: http://www.freepascal.org/docs-html/prog/prog.html

// ~~ RAD_2005 ~~

{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)} // Supports REGION?
  {$DEFINE CAPS_REGION}
  {$DEFINE SUPPORTS_REGION} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)} // Supports class properties?
  {$DEFINE CAPS_CLASSPROPS}
{$IFEND}

{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)} // Supports Inline?
  {$DEFINE CAPS_INLINE}
  {$DEFINE SUPPORTS_INLINE} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)} // Supports class nested const/types?
  {$DEFINE CAPS_CLASSNESTED}
  {$DEFINE SUPPORTS_NESTED_CONSTANTS} // JVCL compatible
  {$DEFINE SUPPORTS_NESTED_TYPES}     // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)} // Supports strict?
  {$DEFINE CAPS_STRICT}
  {$DEFINE SUPPORTS_STRICT} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)} // Supports for-in?
  {$DEFINE CAPS_FORIN}
  {$DEFINE SUPPORTS_FOR_IN} // JVCL compatible
{$IFEND}

// NB: FPC supports this only if $STATIC ON defined
{$IF DEFINED(RAD_2005_UP) OR DEFINED(FPC)} // Supports static class methods/class props?
  {$DEFINE CAPS_STATICMEMBERS}
  {$DEFINE SUPPORTS_STATIC} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2005_UP)} // Uses unit namespaces (System.SysUtils)?
  {$DEFINE CAPS_NAMESPACES}
{$IFEND}

// ~~ RAD_2006 ~~

{$IF DEFINED(RAD_2006_UP)} // Supports abstract and sealed class marks?
  {$DEFINE CAPS_CLASSMARKS}
{$IFEND}

{$IF DEFINED(RAD_2006_UP)} // Supports final/sealed/static class method marks
  {$DEFINE CAPS_METHMARKS}
  {$DEFINE SUPPORTS_STATIC} // JVCL compatible
  {$DEFINE SUPPORTS_FINAL}  // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2006_UP) OR DEFINED(FPC)} // Supports class fields?
  {$DEFINE CAPS_CLASSFIELDS}
  {$DEFINE SUPPORTS_CLASS_FIELDS} // JVCL compatible
{$IFEND}

// NB: FPC uses different syntax
{$IF DEFINED(RAD_2006_UP) OR DEFINED(FPC)} // Supports operator overloading?
  {$DEFINE CAPS_OPOVERLOAD}
{$IFEND}

{$IF DEFINED(RAD_2006_UP) OR DEFINED(FPC)} // Supports class helpers?
  {$DEFINE CAPS_CLASSHELPERS}
  {$DEFINE SUPPORTS_CLASS_HELPERS}
{$IFEND}

// NB: FPC supports only if {$mode objfpc} and {$modeswitch advancedrecords} defined
{$IF DEFINED(RAD_2006_UP) OR DEFINED(FPC)} // Supports enhanced class-like record abilities (methods, props, access level)?
  {$DEFINE CAPS_ENHANCEDRECS}
  {$DEFINE SUPPORTS_ENHANCED_RECORDS} // JVCL compatible
{$IFEND}

// ~~ RAD_2009 ~~

// NB: FPC uses "generic %ClassName%" syntax
{$IF DEFINED(RAD_2009_UP) OR DEFINED(FPC)} // Supports Generics?
  {$DEFINE CAPS_GENERICS}
  {$DEFINE SUPPORTS_GENERICS} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2009_UP) OR DEFINED(FPC)} // Supports Exit(param)?
  {$DEFINE CAPS_EXITPARAM}
{$IFEND}

{$IF DEFINED(RAD_2009_UP)} // Supports reference to proc/func (closures)?
  {$DEFINE CAPS_REFERENCE}
{$IFEND}

{$IF DEFINED(RAD_2009_UP) OR DEFINED(FPC)} // Supports TObject new public methods (Equals, GetHashCode, ToString)?
  {$DEFINE CAPS_TOBJECTMETHODS}
{$IFEND}

{$IF DEFINED(RAD_2009_UP) OR DEFINED(FPC)} // Supports additional text for the deprecated directive?
  {$DEFINE CAPS_DEPRDETAILS}
  {$DEFINE SUPPORTS_DEPRECATED_DETAILS} // JVCL compatible
{$IFEND}

// ~~ RAD_2010 ~~

{$IF DEFINED(RAD_2010_UP) OR DEFINED(FPC)} // Generics working as they should (type PT = ^T)?
  {$DEFINE CAPS_GENERICSOK}
{$IFEND}

{$IF DEFINED(RAD_2010_UP)} // Supports Casting interfaces to objects?
  {$DEFINE CAPS_INTFCAST}
  {$DEFINE SUPPORTS_CAST_INTERFACE_TO_OBJ} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2010_UP)} // Supports delayed loading of an external library?
  {$DEFINE CAPS_DELAYED}
  {$DEFINE SUPPORTS_DELAYED_LOADING} // JVCL compatible
{$IFEND}

{$IF DEFINED(RAD_2010_UP)} // Supports attributes?
  {$DEFINE CAPS_ATTRIBUTES}
{$IFEND}

{$IF DEFINED(RAD_2010_UP) OR DEFINED(FPC)} // Supports class constructors/destructors?
  {$DEFINE CAPS_CLASSCONSTRDESTR}
  {$DEFINE SUPPORTS_CLASS_CTORDTORS} // JVCL compatible
{$IFEND}

// ~~ RAD_XE2 ~~

{$IF DEFINED(RAD_XE2_UP) OR DEFINED(FPC)} // NativeInt, NativeUint are fixed?
  {$DEFINE CAPS_NATIVEOK}
{$IFEND}

// ~~ RAD_XE3 ~~

{$IF DEFINED(RAD_XE3_UP)} // Supports Simple type record helpers?
  {$DEFINE CAPS_SIMPLEHELPERS}
{$IFEND}

// ~~ RAD_XE7 ~~

{$IF DEFINED(RAD_XE7_UP)} // Supports initialization for dynamic arrays?
  {$DEFINE CAPS_DYNARRAYINIT}
{$IFEND}

{$IF DEFINED(RAD_XE7_UP)} // Supports string-like operations on dynamic arrays?
  {$DEFINE CAPS_DYNARRAYOPS}
{$IFEND}

