## @file
# This is DUET FDF file with UEFI HII features enabled
#
# Copyright (c) 2007 - 2011, Intel Corporation. All rights reserved.<BR>
#
#    This program and the accompanying materials
#    are licensed and made available under the terms and conditions of the BSD License
#    which accompanies this distribution. The full text of the license may be found at
#    http://opensource.org/licenses/bsd-license.php
#
#    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
##

  BlockSize          = 0x10000
  # Required IA32 size is ~1 block bigger than required X64 size for each
  # build, so just use minimum IA32 sizes for both.
!if ($(TARGET) == RELEASE)
  NumBlocks          = 0x8        #GenFv image size 0x80000
!else
!if ($(TARGET) == DEBUG)
  NumBlocks          = 0xe        #GenFv image size 0xe0000
!else
  NumBlocks          = 0x25       #GenFv image size 0x250000
!endif
!endif 
  FvAlignment        = 16         #FV alignment and FV attributes setting.
  ERASE_POLARITY     = 1
  MEMORY_MAPPED      = TRUE
  STICKY_WRITE       = TRUE
  LOCK_CAP           = TRUE
  LOCK_STATUS        = TRUE
  WRITE_DISABLED_CAP = TRUE
  WRITE_ENABLED_CAP  = TRUE
  WRITE_STATUS       = TRUE
  WRITE_LOCK_CAP     = TRUE
  WRITE_LOCK_STATUS  = TRUE
  READ_DISABLED_CAP  = TRUE
  READ_ENABLED_CAP   = TRUE
  READ_STATUS        = TRUE
  READ_LOCK_CAP      = TRUE
  READ_LOCK_STATUS   = TRUE

  APRIORI DXE {
    INF  MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
    INF  MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
    INF  OpenCorePkg/Legacy/BootPlatform/8259InterruptControllerDxe/8259.inf
  }

  # Core code
  INF  MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF  MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF  MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  INF  MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf

  # Console
  INF  MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF  MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF  OpenCorePkg/Legacy/BootPlatform/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

  # CPU and interrupts
  INF  UefiCpuPkg/CpuIo2Dxe/CpuIo2Dxe.inf
  INF  OpenCorePkg/Legacy/BootPlatform/CpuDxe/CpuDxe.inf
  INF  OpenCorePkg/Legacy/BootPlatform/8259InterruptControllerDxe/8259.inf
  INF  OpenCorePkg/Legacy/BootPlatform/AcpiResetDxe/Reset.inf

  # Timer
  INF  MdeModulePkg/Universal/Metronome/Metronome.inf
  INF  MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF  MdeModulePkg/Universal/MonotonicCounterRuntimeDxe/MonotonicCounterRuntimeDxe.inf
  INF  OpenCorePkg/Legacy/BootPlatform/8254TimerDxe/8254Timer.inf
  INF  PcAtChipsetPkg/PcatRealTimeClockRuntimeDxe/PcatRealTimeClockRuntimeDxe.inf

  # PCI
  INF  OpenCorePkg/Legacy/BootPlatform/PciRootBridgeDxe/PciRootBridgeNoEnumeration.inf
  INF  OpenCorePkg/Legacy/BootPlatform/PciBusNoEnumerationDxe/PciBusNoEnumeration.inf

  # BIOS Video and CSM
  INF  OpenCorePkg/Legacy/BootPlatform/BiosVideo/BiosVideo.inf
  INF  OpenCorePkg/Legacy/BootPlatform/LegacyRegion2Dxe/LegacyRegion2Dxe.inf

  # ISA (e.g. PS/2 devices)
  INF  OvmfPkg/SioBusDxe/SioBusDxe.inf

  # Keyboard input (OpenCore has custom drivers)
  INF  MdeModulePkg/Bus/Isa/Ps2KeyboardDxe/Ps2KeyboardDxe.inf
  INF  MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf

  # Mouse input (PS/2 is usually customised for touchpad)
  # INF  MdeModulePkg/Bus/Isa/Ps2MouseDxe/Ps2MouseDxe.inf
  # INF  MdeModulePkg/Bus/Usb/UsbMouseDxe/UsbMouseDxe.inf

  # Generic disk I/O (Unicode collation is used by e.g. FAT)
  INF  MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF  MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
  INF  OpenCorePkg/Platform/OpenPartitionDxe/PartitionDxe.inf

  # ACPI and SMBIOS (convenience protocols are optional)
  # INF  OpenCorePkg/Legacy/BootPlatform/SmbiosGenDxe/SmbiosGen.inf
  # INF  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf
  # INF  MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf

  # Filesystems (FAT is mandatory)
  INF  FatPkg/EnhancedFatDxe/Fat.inf

  # Binary drivers
  # INF  RuleOverride=BINARY OpenCorePkg/Legacy/BinDrivers/HfsPlus.inf
  # INF  RuleOverride=BINARY OpenCorePkg/Legacy/BinDrivers/OpenUsbKbDxe.inf

  # Boot management
  INF  OpenCorePkg/Legacy/BootPlatform/BdsDxe/BdsDxe.inf
