Include files for checking compiler versions and capabilities
=============================================================

With these files you can write code that is compatible with older Delphi compilers or even other Pascal compilers (FreePascal) by simply enclosing modern/specific constructions with appropriate define. Moreover you don't have to check compiler version where a required feature first appeared, you just check the availability of this feature.

Additionally, there are files for checking current compiler settings in `CompilerOpts.inc`, some cross-compiler and cross-platform defines in `XPlatformCompat.inc` and cross-compiler declarations in `XCompiler.*.pas`

Summary
-------

- Supports Delphi 7 (see note below), RAD Studio 2005+, FreePascal
- Contains only a few of RTL/VCL changes (feel free to suggest)
- Compatible with JVCL defines (only some of them are included)
- Several ways of implementing conditional defines

Delphi 7 support
----------------

In fact, the files only add one define `DCC` for Delphi 7. We consider language and compiler features implemented in Delphi 7 as a base and track all changes from it. Older versions are not supported because they have no `$IF` clause.

General hints
-------------

- Where possible, use capabilities instead of versions checking for greater clearness and portability.

  **DON'T**:
  ```delphi
  function Foo; {$IF CompilerVersion >= RAD_2005}inline;{$IFEND}
  ```
  
  **DO**:
  ```delphi
  function Foo; {$IFDEF CAPS_INLINE}inline;{$IFEND}
  ```

- Check existense of types/constants/vars by {$IF DECLARED()}.

  **DON'T**:
  ```delphi
  var s: {$IFDEF UNICODE}UnicodeString{$ELSE}WideString{$IFEND};
  ```
  
  **DO**:
  ```delphi
  var s: {$IF DECLARED(UnicodeString)}UnicodeString{$ELSE}WideString{$IFEND};
  ```

  :exclamation: Be careful with declaration and implementation sections! If you declare something in declaration section, `$IF DECLARED` will always be true. Use additional define for this case.

  ```delphi
  {$IF NOT DECLARED(IsNumber)}
    {$DEFINE NO_IsNumber}
    function IsNumber(C: Char): Boolean;
  {$IFEND};
  
  ...
  
  {$IFDEF NO_IsNumber}
  function IsNumber(C: Char): Boolean;
  begin
    ...
  end;
  {$ENDIF}
  ```

- Minimize usage of `$IF` checks as much as possible.

  **DON'T**:
  ```delphi
  var i: {$IFDEF CPUX64}Int64{$ENDIF} {$IFDEF CPUX32}Int32{$ENDIF};
  function Foo: {$IFDEF CPUX64}Int64{$ENDIF} {$IFDEF CPUX32}Int32{$ENDIF};
  ```
  
  **DO** (imagine we don't have `NativeInt`):
  ```delphi
  type CPUInt = {$IFDEF CPUX64}Int64{$ENDIF} {$IFDEF CPUX32}Int32{$ENDIF};
  var i: CPUInt;
  function Foo: CPUInt;
  ```
  
  :exclamation: A bad practice is very frequent in CPU bitness check (`{$IFDEF CPUX64} ...x64... {$ELSE} ...x32? We hope so... {$ENDIF}`). Usually code asserts no other bitness exists besides 64 and 32. This is NOT true (FPC is able to build for 16-bit CPUs and probably someday there will appear 128-bit CPUs). So we use straight conditions for known bitnesses; unsupported ones will generate compiler error.

Editions
--------

There are two editions of the include file.

1) **Define-only edition** in `CompilersDef.inc`.
Contains only compiler defines, thus supports including into any part of a unit, even before the first line of a unit. Under RAD Studio contains compiler version defines named like `RAD_%VER%_UP` where `%VER%` is RAD Studio version (2005-2010, XE, XE2-7...). These defines are identical to frequently used `COMPILER_##_UP` ones.

2) **Declaration edition** in `CompilersDecl.inc`.
Contains some constant declarations, thus allowing more convenient usage. Could be included ONLY in declaration section and below so defines based on this include couldn't be utilized in "uses" section.

You may use the one you need or even both altogether. Internally `CompilersDecl.inc` includes `CompilersDef.inc`.

Usage
-----

1. Check for compiler version (avoid where possible)

  **Declaration edition**
  
  ```delphi
  {$IF CompilerVersion >= RAD_2005}
    ...
  {$IFEND}
  ```
  
  **Define-only edition**
  
  ```delphi
  {$IFDEF RAD_2005_UP}
    ...
  {$IFEND}
  ```
  
  *Note*. Version constants are actual for Delphi/RAD only. It is supposed that FPC users use fresh version so there's no need in checking the capabilities of its older versions.

2. Check for compiler capability
   1. Traditional
  
     ```delphi
     {$IFDEF CAPS_REGION}
       {$REGION 'Foo'}
     {$ENDIF}
     ```
  
     Drawback is that you have to remember all names of defines.
   
   2. Modern style (only with *Declaration edition*)
   
     ```delphi
     {$IF Cap_Region}
       ...
     {$IFEND}
     ```
     
     Here you can get Code Insight's help to find out the needed capability as it is actually a usual boolean constant.
     
     :exclamation: Note that constants are named `Cap_*` while defines are named `CAPS_` to avoid ambiguity with FPC as it allows `$IF %Define_name%` construction.
     
     Sometimes this option is impossible though and you have to use traditional check
     
     ```delphi
     uses {$IFDEF HAS_UNITSCOPE}Winapi.Windows{$ELSE}Windows{$IFEND}, ...
     ```

Defined capabilities
--------------------

Please refer to `CompilersDef.inc` for the list of currently defined capabilities. When using "Modern style" defines you'll get the list of available capabilities with Code Insight.

If you find something to add, feel free to suggest it. But note only those defines will be added that couldn't be determined via `$IF` clauses.

WARNING
-------

Some features of RAD Studio ignore all define areas that use `$IF` construction explicitly or implicitly (still not fixed!). This means no autogenerating of methods, Jump to decl/impl etc. Really annoying and stupid bug. Code Insight still works though.