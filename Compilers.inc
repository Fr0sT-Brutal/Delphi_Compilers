(*******************************************************************************
  Include file for checking compiler versions and capabilities.
  Where possible, use capabilities instead of versions checking for greater 
  clearness and portability.
  Check existense of types/constants/vars by {$IF DECLARED()}.
  Supports compatibility with JVCL defines (only those related to compiler caps
  — i.e., unit and type availability defines excluded).

  Usage:
    1) Check for compiler version (avoid where possible)
      {$IF CompilerVersion >= RAD_2005}
      ...
      {$IFEND}

    2) Check for compiler capability
      2.1) Traditional
      {$IFDEF CAPS_REGION}
        {$REGION 'Foo'}
      {$ENDIF}
      Drawback is that you have to remember all names of defines.

      2.2) Modern style
      {$IF Cap_Region}
      ...
      {$IFEND}
      Here you can get Code Insight to find the needed capability as it is usual
      boolean constant.
      (!) Note that constants are named "Cap_*" while defines are named "CAPS_"
      to avoid ambiguity with FPC as it allows {$IF %Define_name%} construction.

  Drawbacks:
    * Code Insight gets stuck inside such define areas (at least on XE2). This
      means no autogenerating methods, Jump to decl/impl, name substitution etc.
    * This include file utilizes constants so you cannot place its defines in the
      "uses" section.

*******************************************************************************)

// compiler version constants for checking with $IF directive (Delphi6+)
// must be declared for other compilers
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
{$IF NOT DECLARED(CompilerVersion)} // just a stub to compile on non-Delphi/RAD
  CompilerVersion = 0;
{$IFEND}

// compiler capabilities

// References:
// http://edn.embarcadero.com/article/34324
// http://www.embarcadero.com/ru/products/delphi/delphi-feature-matrix
// http://www.tindex.net/Language/ (!)
// FPC: http://www.freepascal.org/docs-html/prog/prog.html

// ~~ RAD_2005 ~~

{$IF (CompilerVersion >= RAD_2005) OR DEFINED(FPC)} // Supports REGION?
  {$DEFINE CAPS_REGION}
  {$DEFINE SUPPORTS_REGION} // JVCL compatible
  Cap_Region = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2005) OR DEFINED(FPC)} // Supports class properties?
  {$DEFINE CAPS_CLASSPROPS}
  Cap_ClassProps = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2005) OR DEFINED(FPC)} // Supports Inline?
  {$DEFINE CAPS_INLINE}
  {$DEFINE SUPPORTS_INLINE} // JVCL compatible
  Cap_Inline = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2005) OR DEFINED(FPC)} // Supports class nested const/types?
  {$DEFINE CAPS_CLASSNESTED}
  Cap_ClassNested = True;
  {$DEFINE SUPPORTS_NESTED_CONSTANTS} // JVCL compatible
  {$DEFINE SUPPORTS_NESTED_TYPES}     // JVCL compatible
{$IFEND}

{$IF (CompilerVersion >= RAD_2005) OR DEFINED(FPC)} // Supports strict?
  {$DEFINE CAPS_STRICT}
  {$DEFINE SUPPORTS_STRICT} // JVCL compatible
  Cap_Strict = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2005) OR DEFINED(FPC)} // Supports for-in?
  {$DEFINE CAPS_FORIN}
  {$DEFINE SUPPORTS_FOR_IN} // JVCL compatible
  Cap_ForIn = True;
{$IFEND}

// FPC supports only if $STATIC ON defined
{$IF (CompilerVersion >= RAD_2005) OR DEFINED(FPC)} // Supports static class methods/class props?
  {$DEFINE CAPS_STATICMEMBERS}
  {$DEFINE SUPPORTS_STATIC} // JVCL compatible
  Cap_StaticMembers = True;
{$IFEND}

// ~~ RAD_2006 ~~

{$IF CompilerVersion >= RAD_2006} // Supports abstract and sealed class marks?
  {$DEFINE CAPS_CLASSMARKS}
  Cap_ClassMarks = True;
{$IFEND}

{$IF CompilerVersion >= RAD_2006} // Supports final/sealed/static class method marks
  {$DEFINE CAPS_METHMARKS}
  {$DEFINE SUPPORTS_STATIC} // JVCL compatible
  {$DEFINE SUPPORTS_FINAL}  // JVCL compatible
  Cap_MethMarks = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2006) OR DEFINED(FPC)} // Supports class fields?
  {$DEFINE CAPS_CLASSFIELDS}
  {$DEFINE SUPPORTS_CLASS_FIELDS} // JVCL compatible
  Cap_ClassFields = True;
{$IFEND}

// FPC uses different syntax
{$IF (CompilerVersion >= RAD_2006) OR DEFINED(FPC)} // Supports operator overloading?
  {$DEFINE CAPS_OPOVERLOAD}
  Cap_OpOverload = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2006) OR DEFINED(FPC)} // Supports class helpers?
  {$DEFINE CAPS_CLASSHELPERS}
  {$DEFINE SUPPORTS_CLASS_HELPERS}
  Cap_ClassHelpers = True;
{$IFEND}

// FPC supports only if {$mode objfpc} and {$modeswitch advancedrecords} defined
{$IF (CompilerVersion >= RAD_2006) OR DEFINED(FPC)} // Supports enhanced class-like record abilities (methods, props, access level)?
  {$DEFINE CAPS_ENHANCEDRECS}
  {$DEFINE SUPPORTS_ENHANCED_RECORDS} // JVCL compatible
  Cap_EnhancedRecs = True;
{$IFEND}

// ~~ RAD_2009 ~~

// FPC uses "generic %ClassName%" syntax
{$IF (CompilerVersion >= RAD_2009) OR DEFINED(FPC)} // Supports Generics?
  {$DEFINE CAPS_GENERICS}
  {$DEFINE SUPPORTS_GENERICS} // JVCL compatible
  Cap_Generics = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2009) OR DEFINED(FPC)} // Supports Exit(param)?
  {$DEFINE CAPS_EXITPARAM}
  Cap_ExitParam = True;
{$IFEND}

// FPC seems to lack support?
{$IF CompilerVersion >= RAD_2009} // Supports reference to proc/func (closures)?
  {$DEFINE CAPS_REFERENCE}
  Cap_Reference = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2009) OR DEFINED(FPC)} // Supports TObject new public methods (Equals, GetHashCode, ToString)?
  {$DEFINE CAPS_TOBJECTMETHODS}
  Cap_TObjectMethods = True;
{$IFEND}

// ~~ RAD_2010 ~~

{$IF (CompilerVersion >= RAD_2010) OR DEFINED(FPC)} // Generics working as they should (type PT = ^T)?
  {$DEFINE CAPS_GENERICSOK}
  Cap_GenericsOK = True;
{$IFEND}

//FPC?
{$IF CompilerVersion >= RAD_2010} // Suppors Casting interfaces to objects?
  {$DEFINE CAPS_INTFCAST}
  {$DEFINE SUPPORTS_CAST_INTERFACE_TO_OBJ} // JVCL compatible
  Cap_IntfCast = True;
{$IFEND}

{$IF CompilerVersion >= RAD_2010} // Suppors delayed loading of an external library?
  {$DEFINE CAPS_DELAYED}
  {$DEFINE SUPPORTS_DELAYED_LOADING} // JVCL compatible
  Cap_Delayed = True;
{$IFEND}

//FPC?
{$IF CompilerVersion >= RAD_2010} // Suppors attributes?
  {$DEFINE CAPS_ATTRIBUTES}
  Cap_Attributes = True;
{$IFEND}

{$IF (CompilerVersion >= RAD_2010) OR DEFINED(FPC)} // Suppors class constructors/destructors?
  {$DEFINE CAPS_CLASSCONSTRDESTR}
  {$DEFINE SUPPORTS_CLASS_CTORDTORS} // JVCL compatible
  Cap_ClassConstDestr = True;
{$IFEND}

// ~~ RAD_XE3 ~~

{$IF CompilerVersion >= RAD_XE3} // Suppors Simple type record helpers?
  {$DEFINE CAPS_SIMPLEHELPERS}
  Cap_SimpleHelpers = True;
{$IFEND}

// ~~ RAD_XE7 ~~

{$IF CompilerVersion >= RAD_XE7} // Suppors initialization for dynamic arrays?
  {$DEFINE CAPS_DYNARRAYINIT}
  Cap_DynArrayInit = True;
{$IFEND}

{$IF CompilerVersion >= RAD_XE7} // Suppors string-like operations on dynamic arrays?
  {$DEFINE CAPS_DYNARRAYOPS}
  Cap_DynArrayOps = True;
{$IFEND}

(*   TODO
SUPPORTS_METHODINFO            Compiler supports the METHODINFO directives (D10+)
SUPPORTS_DEPRECATED_DETAILS    Compiler supports additional text for the deprecated directive (D11.NET, D12+)
HAS_PROPERTY_STYLEELEMENTS     TControl has a StyleElements property (D17+)
*)
