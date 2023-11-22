#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>
#include "interfaces.hpp"

extern "C" acpi_status AcpiInstallInterface(acpi_string);

static int kernelVersion = getKernelVersion();

static void installInterfaces() {
	// defined in interfaces.h
	for (int i = 0; i < sizeof(interfaces) / sizeof(interface_info_t); ++i) {
		interface_info_t *info = &interfaces[i];
		if (info->maxKernel == 0) {
			info->maxKernel = info->minKernel;
		}
		if (info->minKernel > 0 && kernelVersion < info->minKernel) {
			DBGLOG("osi", "Skipped _OSI(\"%s\") due to KernelVersion(%d) < %d", info->osiString, kernelVersion, info->minKernel);
			continue;
		}
		if (info->maxKernel > 0 && kernelVersion > info->maxKernel) {
			DBGLOG("osi", "Skipped _OSI(\"%s\") due to KernelVersion(%d) > %d", info->osiString, kernelVersion, info->maxKernel);
			continue;
		}
		SYSLOG("osi", "Added _OSI(\"%s\")", info->osiString);
		AcpiInstallInterface(info->osiString);
	}

	// _OSI("macOS xx")
	if (kernelVersion >= KernelVersion::BigSur) {
		char macosString[9];
		snprintf(macosString, sizeof(macosString), "macOS %d", kernelVersion - 9);
		SYSLOG("osi", "Added _OSI(\"%s\")", macosString);
		AcpiInstallInterface(macosString);
	}

	// _OSI("Darwin xx")
	char darwinString[10];
	snprintf(darwinString, sizeof(darwinString), "Darwin %d", kernelVersion);
	SYSLOG("osi", "Added _OSI(\"%s\")", darwinString);
	AcpiInstallInterface(darwinString);
}

static const char *bootargOff[] {
	"-osioff"
};

static const char *bootargDebug[] {
	"-osidbg"
};

static const char *bootargBeta[] {
	"-osibeta"
};

PluginConfiguration ADDPR(config) {
	xStringify(PRODUCT_NAME),
	parseModuleVersion(xStringify(MODULE_VERSION)),
	LiluAPI::AllowNormal,
	bootargOff,
	arrsize(bootargOff),
	bootargDebug,
	arrsize(bootargDebug),
	bootargBeta,
	arrsize(bootargBeta),
	KernelVersion::Yosemite,
	KernelVersion::Sonoma,
	installInterfaces
};
