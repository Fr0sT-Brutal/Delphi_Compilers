Include file for checking compiler versions and capabilities.
--------

Where possible, use capabilities instead of versions checking for greater clearness and portability.
Check existense of types/constants/vars by {$IF DECLARED()}.
Supports compatibility with JVCL defines (only those related to compiler caps
— i.e., unit and type availability defines excluded).

Usage:

1) Check for compiler version (avoid where possible)
  ```delphi
  {$IF CompilerVersion >= RAD_2005}
  ...
  {$IFEND}
  ```

2) Check for compiler capability

  2.1) Traditional
  ```delphi
  {$IFDEF CAPS_REGION}
    {$REGION 'Foo'}
  {$ENDIF}
  ```
  Drawback is that you have to remember all names of defines.

  2.2) Modern style
  ```delphi
  {$IF Cap_Region}
  ...
  {$IFEND}
  ```
  Here you can get Code Insight to find the needed capability as it is usual
  boolean constant.
  (!) Note that constants are named `Cap_*` while defines are named `CAPS_` to avoid ambiguity with FPC as it allows `{$IF %Define_name%}` construction.

Drawbacks:
---------
* Code Insight gets stuck inside such define areas (at least on XE2). This means no autogenerating methods, Jump to decl/impl, name substitution etc.
* This include file utilizes constants so you cannot place its defines in the "uses" section.