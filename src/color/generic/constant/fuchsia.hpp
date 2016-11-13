#ifndef color_generic_constant_fuchsia
#define color_generic_constant_fuchsia

// ::color::constant::fuchsia( c )

#include "./base.hpp"

namespace color
 {
  namespace constant
   {

    namespace _internal
     {
      struct fuchsia_w3c_type{};
     }

    namespace w3c
     {
      typedef  ::color::constant::base< ::color::constant::_internal::fuchsia_w3c_type > fuchsia_type;
      typedef  ::color::constant::w3c::fuchsia_type                                      fuchsia_t;
     }

    namespace x11
     {// Same as w3c
      typedef  ::color::constant::w3c::fuchsia_type  fuchsia_type;
      typedef  ::color::constant::w3c::fuchsia_type  fuchsia_t;
     }

    namespace vga
     {// Same as w3c
      typedef  ::color::constant::w3c::fuchsia_type  fuchsia_type;
      typedef  ::color::constant::w3c::fuchsia_type  fuchsia_t;
     }


    typedef ::color::constant::w3c::fuchsia_type fuchsia_t, fuchsia_type;

   }
 }

#endif
