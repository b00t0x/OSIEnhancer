# OSIEnhancer
Lilu plugin that enhances the available strings for use with the `_OSI` function used in DSDT and SSDT for OS detection.

You can use strings like `_OSI("Darwin 21")` or `_OSI("Monterey")`, allowing you to apply different ACPI patches for different macOS versions.

## Available Strings
### `_OSI("macOS")`
To patch only macOS in a multi-boot environment, it is recommended to use `_OSI("Darwin")`. However, Linux also [responds](https://www.kernel.org/doc/html/v6.0/firmware-guide/acpi/osi.html#apple-mac-and-osi-darwin) to `_OSI("Darwin")`, which can lead to issues. Therefore, `"macOS"` is defined as an alternative method to detect any macOS versions.

### `_OSI("Darwin XX")`
You can determine the macOS version based on kernel version using strings like `"Darwin 21"`. It also supports future macOS releases. ( `-osibeta` boot-arg required )

### `_OSI("macOS XX")` / `_OSI("OS X 10.XX")`
You can detect the macOS version using strings like `"macOS 12"`. Refer to [interfaces.hpp](./OSIEnhancer/interfaces.hpp) for the actual set strings.

It also supports future macOS releases as long as the naming convention doesn't change. ( `-osibeta` boot-arg required )

### `_OSI("Yosemite")` ... `_OSI("Sonoma")`
You can also use the names of each macOS version. Refer to [interfaces.hpp](./OSIEnhancer/interfaces.hpp) for the actual strings.

### Intel Framebuffer
For my personal use, the following strings have been introduced to identify available Intel iGPU Framebuffers:
- `"Skylake Framebuffer"`
- `"Kaby Lake Framebuffer"`
- `"Coffee Lake Framebuffer"`

For more information on these uses, see [here](https://github.com/b00t0x/opencore-macos-version-specific-dp).

## SSDT
To achieve the functionality of `MinKernel` / `MaxKernel`, this kext is provided with [SSDT and samples](./SSDT) for use in combination.

## Notes
### Mavericks (10.9) and Earlier
`AcpiInstallInterface` is only implemented in Yosemite (10.10) and later, so you can't use this kext with Mavericks or earlier. It might be possible to replace `AcpiOsValidateInterface` from Leopard (10.5) to Mavericks, but this has not been confirmed.

## Credits
- [Slice](https://github.com/SergeySlice) for the [idea](https://www.insanelymac.com/forum/topic/355374-how-to-make-ssdt-if-_osi-darwin-to-a-specific-version-of-macos/?do=findComment&comment=2800041) about AppleACPIPlatform `_OSI` patch
- [RehabMan](https://github.com/RehabMan) for the [Guide](https://www.tonymacx86.com/threads/guide-hackrnvmefamily-co-existence-with-ionvmefamily-using-class-code-spoof.210316/) on DeviceProperties Injection via SSDT
