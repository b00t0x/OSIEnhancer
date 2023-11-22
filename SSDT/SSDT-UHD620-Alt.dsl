DefinitionBlock ("", "SSDT", 2, "hack", "UHD620", 0x00000000)
{
    External (_SB_.PCI0.GFX0, DeviceObj)

    Method (\_SB.PCI0.GFX0._DSM, 4, NotSerialized)  // _DSM: Device-Specific Method
    {
        If (!Arg2)
        {
            Return (Buffer (One)
            {
                 0x03                                             // .
            })
        }

        If (_OSI ("Kaby Lake Framebuffer"))
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

        If (_OSI ("Skylake Framebuffer"))
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

        If (_OSI ("Coffee Lake Framebuffer"))
        {
            Return (Package (0x06)
            {
                "device-id", 
                Buffer (0x04)
                {
                     0x9B, 0x3E, 0x00, 0x00                           // .>..
                }, 

                "AAPL,ig-platform-id", 
                Buffer (0x04)
                {
                     0x00, 0x00, 0x9B, 0x3E                           // ...>
                }, 

                "enable-backlight-registers-fix", 
                One
            })
        }

        Return (Zero)
    }
}

