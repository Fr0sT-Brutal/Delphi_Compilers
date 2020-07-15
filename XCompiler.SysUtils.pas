// Cross-compiler defines for SysUtils unit

unit XCompiler.SysUtils;

interface

uses SysUtils;

const
  // FPC feInvalidHandle / DCC INVALID_HANDLE_VALUE
  {$IF NOT DECLARED(feInvalidHandle)}
  feInvalidHandle = INVALID_HANDLE_VALUE;
  {$IFEND}
  {$IF NOT DECLARED(INVALID_HANDLE_VALUE)}
  INVALID_HANDLE_VALUE = THandle(-1); // feInvalidHandle is typed const...
  {$IFEND}

  // FPC fsFrom* (DCC misses)
  {$IF NOT DECLARED(fsFromBeginning)}
  fsFromBeginning = 0;
  {$IFEND}
  {$IF NOT DECLARED(fsFromCurrent)}
  fsFromCurrent = 1;
  {$IFEND}
  {$IF NOT DECLARED(fsFromEnd)}
  fsFromEnd = 2;
  {$IFEND}

  // FPC GetLastOSError / DCC GetLastError
  {$IF NOT DECLARED(GetLastError)}
  {$DEFINE No_GetLastError}
  function GetLastError: Cardinal;
  {$IFEND}
  {$IF NOT DECLARED(GetLastOSError)}
  {$DEFINE No_GetLastOSError}
  function GetLastOSError: Integer;
  {$IFEND}

implementation

{$IFDEF No_GetLastError}
function GetLastError: Cardinal;
begin
  Result := Cardinal(GetLastOSError);
end;
{$ENDIF}

{$IFDEF No_GetLastOSError}
function GetLastOSError: Integer;
begin
  Result := Integer(GetLastError);
end;
{$ENDIF}

end.
