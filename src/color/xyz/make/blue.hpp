#ifndef color_xyz_make_blue
#define color_xyz_make_blue

// ::color::make::blue( c )

 namespace color
  {
   namespace make
    {

      inline
      void blue( ::color::_internal::model< color::category::xyz_uint8 > & color_parameter )
       {
        color_parameter.container() = 0xC0; //!< TODO
       } 

      inline
      void blue( ::color::_internal::model< color::category::xyz_uint16 > & color_parameter )
       {
        color_parameter.container() = 0x7C00; //!< TODO
       }

      inline
      void blue( ::color::_internal::model< color::category::xyz_uint32 > & color_parameter )
       {
        color_parameter.container() = 0xffff0000; //!< TODO
       };

      inline
      void blue( ::color::_internal::model< color::category::xyz_uint64 > & color_parameter )
       {
        color_parameter.container() = std::uint64_t( 0xffffffff00000000u ); //!< TODO
       }

      inline
      void blue( ::color::_internal::model< color::category::xyz_float > & color_parameter )
       {
        color_parameter.container() = std::array<float,3>( { 0, 0, 1 } ); //!< TODO
       };

      inline
      void blue( ::color::_internal::model< color::category::xyz_double> & color_parameter )
       {
        color_parameter.container() = std::array<double,3>( { 0, 0, 1 } ); //!< TODO
       };

      inline
      void blue( ::color::_internal::model< color::category::xyz_ldouble> & color_parameter )
       {
        color_parameter.container() = std::array<long double,3>( { 0, 0, 1 } ); //!< TODO
       };

    }
  }

#endif
