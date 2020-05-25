#ifndef __FACTORY_HPP_INCLUDED__
#define __FACTORY_HPP_INCLUDED__

//#include <memory>
#include "CString.hpp"
#include <map>

class Factory {
  public:
    virtual CString* Create(const int size_, const std::string& filename) const = 0;

    Factory() = default;
    virtual ~Factory() = default;
  };


#endif // __FACTORY_HPP_INCLUDED__
