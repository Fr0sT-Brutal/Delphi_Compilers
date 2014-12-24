Include files for checking compiler versions and capabilities
=============================================================

With these files you can write code that is compatible with older Delphi compilers or even other Pascal compilers (FreePascal) by simply enclosing modern/specific constructions with appropriate define. Moreover you don't have to check compiler version where a required feature first appeared, you just check the availability of this feature.

Summary
-------
- Supports Delphi 7, RAD Studio 2005+, FreePascal
- Contains only compiler capabilities, i.e. RTL/VCL changes are not included
- Compatible with JVCL defines (only those related to compiler capabilities are implemented - this means that unit and type availability defines excluded)
- Several ways of implementing conditional defines

General hints
-------------
- Where possible, use capabilities instead of versions checking for greater clearness and portability.

**DON'T**:
```delphi
function Foo; {IF CompilerVersion >= RAD_2005}inline;{$IFEND}
```

**DO**:
```delphi
function Foo; {IFDEF CAPS_INLINE}inline;{$IFEND}
```

- Check existense of types/constants/vars by {$IF DECLARED()}.

**DON'T**:
```delphi
var s: {IFDEF UNICODE}UnicodeString{$ELSE}WideString{$IFEND};
```

**DO**:
```delphi
var s: {IF DECLARED(UnicodeString)}UnicodeString{$ELSE}WideString{$IFEND};
```

Editions
--------

There are two editions of the include file.

1) **Define-only edition** in `CompilersDef.inc`.
Contains only compiler defines, thus supports including into any part of a unit, even before the line with unit name! Under RAD Studio contains compiler version defines named like `RAD_%VER%_UP` where `%VER%` is RAD Studio version (2005-2010, XE, XE2-7...). These defines are identical to frequently used `COMPILER_##_UP` ones.

2) **Declaration edition** in `CompilersDecl.inc`.
Contains some constant declarations, thus allowing more convenient usage. Could be included ONLY in declaration section and below so defines based on this include couldn't be utilized in "uses" section.

You may use the one you need or even both altogether. Internally `CompilersDecl.inc` includes `CompilersDef.inc`.

Usage
-----

1) Check for compiler version (avoid where possible)

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

2) Check for compiler capability

2.1) Traditional

```delphi
{$IFDEF CAPS_REGION}
  {$REGION 'Foo'}
{$ENDIF}
```

Drawback is that you have to remember all names of defines.

2.2) Modern style (only in *Declaration edition*)

```delphi
{$IF Cap_Region}
  ...
{$IFEND}
```

Here you can get Code Insight's help to find out the needed capability as it is actually a usual boolean constant.
(!) Note that constants are named `Cap_*` while defines are named `CAPS_` to avoid ambiguity with FPC as it allows `{$IF %Define_name%}` construction.

Sometimes this option is impossible though and you have to use traditional check

```delphi
  uses {$IFDEF CAPS_NAMESPACES}Winapi.Windows{$ELSE}Windows{$IFEND}, ...
```

Defined capabilities
--------------------

Please refer to `CompilersDef.inc` for the list of currently defined capabilities. When using "Modern style" defines you'll get the list of available capabilities with Code Insight.

WARNING
-------

Some features of RAD Studio ignore all define areas that use `$IF` construction explicitly or implicitly (at least on XE2). This means no autogenerating of methods, Jump to decl/impl etc. Really annoying and stupid bug. Code Insight still works though.