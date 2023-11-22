# SSDT
## SSDT-Darwin
In [SSDT-Darwin.aml](./SSDT-Darwin.aml), the `DARW` method is defined, allowing you to specify the patch application scope based on kernel version, such as `If(OSDW(16,21))`.

## Samples
### SSDT-UHD620
[SSDT-UHD620](./SSDT-UHD620.dsl) is a sample that demonstrates the usage of `OSDW` and other `_OSI` methods. It is used in conjunction with SSDT-Darwin.

In this example, it applies the Skylake Framebuffer for 10.11, the Kaby Lake one for 10.12 to 12, and the Coffee Lake one for 13 and later.

### SSDT-UHD620-Alt
[SSDT-UHD620-Alt](./SSDT-UHD620-Alt.dsl) is an alternative format of the same functionality as SSDT-UHD620. It prioritizes the Kaby Lake Framebuffer and applies the Skylake / Coffee Lake ones if it's not available.
