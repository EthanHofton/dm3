#ifndef DM3_CORE_PLATFORMDETECT_HPP
#define DM3_CORE_PLATFORMDETECT_HPP

#ifdef _WIN32
    #ifdef _WIN64
        #define DM3_PLATFORM_WINDOWS
    #else
        #define DM3_PLATFORM_WINDOWS
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
        #define DM3_PLATFORM_IOS_SIMULATOR
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define DM3_PLATFORM_IOS
	#elif TARGET_OS_MAC == 1
		#define DM3_PLATFORM_OSX
	#else
		#error "Unknown Apple platform!"
	#endif
#elif defined(__ANDROID__)
    #define DM3_PLATFORM_ANDRIOID
    #error "Andrioid is not supported"
#elif defined(__linux__)
    #define DM3_PLATFORM_LINUX
#else
    #error "Unknown Platform"
#endif

#endif
