#ifndef color_cmyk_uint64
#define color_cmyk_uint64

#include "../_internal/utility/type/index.hpp"
#include "../_internal/utility/component/unsigned.hpp"
#include "../_internal/utility/container/unsigned.hpp"

#include "../_internal/bound.hpp"
#include "../_internal/index.hpp"
#include "../_internal/component.hpp"
#include "../_internal/container.hpp"


namespace color
 {
  namespace _internal
   {

    template< >
     struct bound< ::color::category::cmyk_uint64 >
      : public ::color::_internal::utility::bound::general< std::uint64_t, unsigned >
      {
      };

    template< >
     struct index< ::color::category::cmyk_uint64 >
      : public color::_internal::utility::type::index< unsigned >
      {
      };

    template< >
     struct component< ::color::category::cmyk_uint64 >
      : public ::color::_internal::utility::component::Unsigned< std::uint16_t, 16, unsigned>
      {
      };

    template< >
     struct container< ::color::category::cmyk_uint64 >
      : public  ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 4, 16 >
      {
      };

   }
 }

#endif