#define DRIVER_FUNC_INSTALL     0x01
#define DRIVER_FUNC_REMOVE      0x02
#define DRIVER_FUNC_STOP        0x03
#define DRIVER_FUNC_STALL       0x04
#define DRIVER_FUNC_PROCESS     0x05
#define DRIVER_FUNC_MERGE       0x06
#define DRIVER_FUNC_LINK        0x07
#define DRIVER_FUNC_RESOLVE     0x08
#define DRIVER_FUNC_LOCK        0x09
#define DRIVER_FUNC_UPDATE      0x010
#define DRIVER_FUNC_SWITCH      0x011
#define DRIVER_FUNC_LOOP        0x012


#define DRIVER_NAME       _T("lamk")
#define DRIVER_VERSION    _T("1.0.0")
#define DRIVER_OS       _T("s%")
#define DRIVER_STATS       _T("status")

BOOLEAN
ManageDriver(
    IN LPCTSTR  DriverName,
    IN LPCTSTR  ServiceName,
    IN USHORT   Function
    );
	
void IoGetStackLimits(
  PULONG_PTR LowLimit,
  PULONG_PTR HighLimit
);
NTSTATUS 
KeExpandKernelStackAndCallout(
  PEXPAND_STACK_CALLOUT Callout,
  PVOID                 Size,
  SIZE_T                Parameter
);
NTSTATUS 
PsTerminateSystemThread(
  NTSTATUS ExitStatus
);