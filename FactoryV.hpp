#ifndef __FACTORYV_HPP_INCLUDED__
#define __FACTORYV_HPP_INCLUDED__

#include <memory>
#include "CString.hpp"
#include "CString1.hpp"

class FactoryV : public Factory {
  public:
    virtual shared_ptr<CString> Create(const  int size, const string& filename) const override final {
      return make_shared<CString1>(size, filename);
    }
    FactoryV() = default;
    ~FactoryV() = default;
  };

#endif // __FACTORYVERT_HPP_INCLUDED__
