typedef uint32_t acpi_status;
typedef const char *acpi_string;

typedef struct {
	acpi_string osiString;
	int minKernel;
	int maxKernel;
} interface_info_t;

interface_info_t interfaces[] = {
  // common os name
  {"macOS"},
  // macOS by name
  // {"Tiger",         KernelVersion::Tiger},
  // {"Leopard",       KernelVersion::Leopard},
  // {"Snow Leopard",  KernelVersion::SnowLeopard},
  // {"Lion",          KernelVersion::Lion},
  // {"Mountain Lion", KernelVersion::MountainLion},
  // {"Mavericks",     KernelVersion::Mavericks},
  {"Yosemite",      KernelVersion::Yosemite},
  {"El Capitan",    KernelVersion::ElCapitan},
  {"Sierra",        KernelVersion::Sierra},
  {"High Sierra",   KernelVersion::HighSierra},
  {"Mojave",        KernelVersion::Mojave},
  {"Catalina",      KernelVersion::Catalina},
  {"Big Sur",       KernelVersion::BigSur},
  {"Monterey",      KernelVersion::Monterey},
  {"Ventura",       KernelVersion::Ventura},
  {"Sonoma",        KernelVersion::Sonoma},
  // macOS by version
  // {"Mac OS X 10.4", KernelVersion::Tiger},
  // {"Mac OS X 10.5", KernelVersion::Leopard},
  // {"Mac OS X 10.6", KernelVersion::SnowLeopard},
  // {"OS X 10.7",     KernelVersion::Lion},
  // {"OS X 10.8",     KernelVersion::MountainLion},
  // {"OS X 10.9",     KernelVersion::Mavericks},
  {"OS X 10.10",    KernelVersion::Yosemite},
  {"OS X 10.11",    KernelVersion::ElCapitan},
  {"macOS 10.12",   KernelVersion::Sierra},
  {"macOS 10.13",   KernelVersion::HighSierra},
  {"macOS 10.14",   KernelVersion::Mojave},
  {"macOS 10.15",   KernelVersion::Catalina},
  // macOS 11 or later are auto generated
  // interface by range examples
  {"Skylake Framebuffer",     KernelVersion::ElCapitan, KernelVersion::Monterey},
  {"Kaby Lake Framebuffer",   KernelVersion::Sierra, -1}, // possibly Sonoma is the last
  {"Coffee Lake Framebuffer", KernelVersion::HighSierra, -1},
};
