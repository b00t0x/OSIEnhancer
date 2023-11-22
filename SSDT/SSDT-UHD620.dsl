DefinitionBlock ("", "SSDT", 2, "hack", "UHD620", 0x00000000)
{
    External (_SB_.PCI0.GFX0, DeviceObj)
    External (DARW, MethodObj)    // 2 Arguments

    Method (\_SB.PCI0.GFX0._DSM, 4, NotSerialized)  // _DSM: Device-Specific Method
    {
        If (!Arg2)
        {
            Return (Buffer (One)
            {
                 0x03                                             // .
            })
        }

        If (_OSI ("El Capitan"))
        {
            Return (Package (0x04)
            {
                "device-id", 
                Buffer (0x04)
                {
                     0x16, 0x19, 0x00, 0x00                           // ....
                }, 

                "AAPL,ig-platform-id", 
                Buffer (0x04)
                {
                     0x02, 0x00, 0x26, 0x19                           // ..&.
                }
            })
        }

        If (DARW (0x10, 0x15))
        {
            Return (Package (0x04)
            {
                "device-id", 
                Buffer (0x04)
                {
                     0x16, 0x59, 0x00, 0x00                           // .Y..
                }, 

                "AAPL,ig-platform-id", 
                Buffer (0x04)
                {
                     0x02, 0x00, 0x26, 0x59                           // ..&Y
                }
            })
        }

        If (DARW (0x16, 0xFF))
        {
            Return (Package (0x06)
            {
                "device-id", 
                Buffer (0x04)
                {
                     0xA5, 0x3E, 0x00, 0x00                           // .>..
                }, 

                "AAPL,ig-platform-id", 
                Buffer (0x04)
                {
                     0x04, 0x00, 0xA5, 0x3E                           // ...>
                }, 

                "enable-backlight-registers-fix", 
                One
            })
        }

        Return (Zero)
    }
}

