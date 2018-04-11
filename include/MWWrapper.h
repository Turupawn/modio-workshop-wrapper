#include <iostream>
#include <vector>

#include "schemas/mod.h"
#include "modio/modio.h"
#include "steam/steam_api.h"

#ifdef __linux__
#define LINUX
#endif

#ifdef __APPLE__
#define OSX
#endif
#ifdef __MACH__
#define OSX
#endif

#ifdef _WIN32
#define WINDOWS
#endif
#ifdef _WIN64
#define WINDOWS
#endif

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
  modio::Instance* modio_instance;
  MWWrapper();
  ~MWWrapper();
  void test();
  std::vector<modio::Mod> getMods();
  void process();
};

