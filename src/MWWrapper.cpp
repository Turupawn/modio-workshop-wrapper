#include "MWWrapper.h"

MWWrapper::MWWrapper()
{
  modio_instance = new modio::Instance(MODIO_ENVIRONMENT_TEST, 7, "e91c01b8882f4affeddd56c96111977b");    
}

MWWrapper::~MWWrapper()
{
}

std::vector<modio::Mod> MWWrapper::getMods()
{

}

void MWWrapper::process()
{
  this->modio_instance->process();  
}

void MWWrapper::test()
{
  modio::Instance modio_instance(MODIO_ENVIRONMENT_TEST, 7, "e91c01b8882f4affeddd56c96111977b");

  modio::FilterCreator filter;
  filter.setLimit(3);

  // Now we finished setting up the filters we are ready to request the mods
  modio_instance.getMods(filter, [&](const modio::Response& response, const std::vector<modio::Mod> & mods)
  {
    std::cout << "On mod get response: " << response.code << std::endl;
    if(response.code == 200)
    {
      std::cout << "Listing mods" << std::endl;
      std::cout << "============" << std::endl;
      for(auto& mod : mods)
      {
        std::cout << "Id: \t" << mod.id << std::endl;
        std::cout << "Name:\t" << mod.name << std::endl;
      }

      // Additionally, we can access pagination data to ease future browsing queries
      std::cout << std::endl;
      std::cout << "Cursor data:" << std::endl;
      std::cout << "Result count: " << response.result_count << std::endl;
      std::cout << "Result limit: " << response.result_limit << std::endl;
      std::cout << "Result offset: " << response.result_offset << std::endl;
      std::cout << "Result is cached: " << response.result_cached << std::endl;
    }
  });

  while(true)
  modio_instance.process();
}