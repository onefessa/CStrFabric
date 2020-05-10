#ifndef __FACTORYH_HPP_INCLUDED__
#define __FACTORYH_HPP_INCLUDED__

#include "Factory.hpp"
#include "CString.hpp"
#include "CString0.hpp"

class FactoryH : public Factory {
  public:
    virtual shared_ptr<CString>Create(const  int size, const string& filename) const override final {
      return make_shared<CString0>(size, filename);
    }
    FactoryH() = default;
    ~FactoryH() = default;
  };

#endif // __FACTORYHORI_HPP_INCLUDED__
