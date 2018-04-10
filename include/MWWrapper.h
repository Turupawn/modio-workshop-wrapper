#include <iostream>

#define WINDOWS

#ifdef WINDOWS
#ifdef BUILDING_MODIO_WORKSHOP_WRAPPER_DLL
#define MODIO_WORKSHOP_WRAPPER_DLL __declspec(dllexport)
#else
#define MODIO_WORKSHOP_WRAPPER_DLL __declspec(dllimport)
#endif
#else
#define MODIO_WORKSHOP_WRAPPER_DLL
#endif

class MODIO_WORKSHOP_WRAPPER_DLL MWWrapper
{
public:
    MWWrapper();
    ~MWWrapper();
    void test();
};

