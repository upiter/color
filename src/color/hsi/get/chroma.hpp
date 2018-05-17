#ifndef color_hsi_get_chroma
#define color_hsi_get_chroma

// ::color::get::chroma( c )

#include "../category.hpp"
#include "../place/place.hpp"

#include "../../_internal/normalize.hpp"
#include "../../_internal/diverse.hpp"



 namespace color
  {
   namespace get
    {

     template< typename tag_name >
      inline
      typename ::color::model< ::color::category::hsi< tag_name> >::component_const_type
      chroma( ::color::model< ::color::category::hsi< tag_name> > const& color_parameter )
       {
        typedef ::color::category::hsi< tag_name >  category_type;

        typedef typename ::color::trait::scalar<category_type>::instance_type   scalar_type;

        typedef ::color::hsi< scalar_type >  model_scalar_type;
        typedef ::color::_internal::diverse< category_type >     diverse_type;
        typedef ::color::_internal::normalize<category_type>   normalize_type;

        enum
         {
           saturation_p  = ::color::place::_internal::saturation<category_type>::position_enum
          ,intensity_p   = ::color::place::_internal::intensity<category_type>::position_enum
         };

        scalar_type s = normalize_type::template process<saturation_p>( color_parameter.template get<saturation_p>() );
        scalar_type i = normalize_type::template process<intensity_p >( color_parameter.template get<intensity_p >() );

        return diverse_type::template process<intensity_p>( s * i );
       }

    }
  }

#endif